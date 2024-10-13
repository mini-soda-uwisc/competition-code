#include <bits/stdc++.h>
using namespace std;

// 定义无限大值
const int INF = numeric_limits<int>::max();

// 边的结构体
struct Edge {
    int to;         // 边的终点
    int capacity;   // 边的容量
    int flow;       // 当前流量
    int rev;        // 反向边在邻接表中的索引

    Edge(int to, int capacity, int rev) : to(to), capacity(capacity), flow(0), rev(rev) {}
};

// 图的类
class Graph {
public:
    int numVertices;                    // 顶点数量
    vector<vector<Edge>> adjList;       // 邻接表

    Graph(int vertices) : numVertices(vertices), adjList(vertices, vector<Edge>()) {}

    // 添加一条边和其反向边
    void addEdge(int from, int to, int capacity) {
        // 正向边
        adjList[from].emplace_back(to, capacity, adjList[to].size());
        // 反向边
        adjList[to].emplace_back(from, 0, adjList[from].size() - 1);
    }

    // 使用 BFS 寻找增广路径，返回路径上的最小残量
    int bfs(int s, int t, vector<int>& parent, vector<int>& parentEdge) {
        fill(parent.begin(), parent.end(), -1);
        queue<int> q;
        q.push(s);
        parent[s] = -2; // 标记源点已访问

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < adjList[u].size(); ++i) {
                Edge &edge = adjList[u][i];
                if (parent[edge.to] == -1 && edge.capacity > edge.flow) {
                    parent[edge.to] = u;
                    parentEdge[edge.to] = i;
                    q.push(edge.to);
                    if (edge.to == t) break;
                }
            }
        }

        if (parent[t] == -1)
            return 0; // 没有增广路径

        // 计算路径上的最小残量
        int path_flow = INF;
        int v = t;
        while (v != s) {
            int u = parent[v];
            int edge_idx = parentEdge[v];
            path_flow = min(path_flow, adjList[u][edge_idx].capacity - adjList[u][edge_idx].flow);
            v = u;
        }

        // 更新路径上的流量
        v = t;
        while (v != s) {
            int u = parent[v];
            int edge_idx = parentEdge[v];
            adjList[u][edge_idx].flow += path_flow;
            // 更新反向边的流量
            adjList[v][adjList[u][edge_idx].rev].flow -= path_flow;
            v = u;
        }

        return path_flow;
    }

    // 计算最大流
    int maxFlow(int s, int t) {
        int total_flow = 0;
        vector<int> parent(numVertices, -1);
        vector<int> parentEdge(numVertices, -1);

        while (true) {
            int flow = bfs(s, t, parent, parentEdge);
            if (flow == 0)
                break;
            total_flow += flow;
        }

        return total_flow;
    }

    // 构建残差网络
    Graph getResidualGraph() {
        Graph residual(numVertices);
        for(int u = 0; u < numVertices; ++u) {
            for(auto &edge : adjList[u]) {
                if(edge.capacity - edge.flow > 0) {
                    residual.addEdge(u, edge.to, edge.capacity - edge.flow);
                }
                if(edge.flow > 0) {
                    residual.addEdge(edge.to, u, edge.flow);
                }
            }
        }
        return residual;
    }

    // 打印图的边
    void printGraph() {
        for(int u = 0; u < numVertices; ++u) {
            for(auto &edge : adjList[u]) {
                cout << u << " -> " << edge.to
                     << " | Capacity: " << edge.capacity
                     << " | Flow: " << edge.flow << endl;
            }
        }
    }
};

// 求解函数
inline void solve() {
    int n, E;
    cin >> n >> E; // U: 左侧节点数, V: 右侧节点数, E: 边数

    vector<int> U, V;
    map<int, int> added;
    // 定义总节点数: 左侧 U + 右侧 V + 源点 S + 汇点 T
    int S = n;
    int T = n + 1;
    int totalVertices = n + 2;

    Graph g(totalVertices);

    for(int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g.addEdge(u, v, 1);
    }

    function<void(int, int)> dfs = [&](int x, int tag) {
        added[x] = 1;
        if (tag == 0) U.push_back(x);
        else V.push_back(x);

        for (auto& edge : g.adjList[x]) {
            if (!added[edge.to]) {
                dfs(edge.to, tag ^ 1);
            }
        }
    };
    dfs(0, 0);

//    cout << "U: ";
//    for (int i = 0; i < U.size(); ++i) {
//        cout << U[i] << ' ';
//    }
//    cout << '\n';
//    cout << "V: ";
//    for (int i = 0; i < V.size(); ++i) {
//        cout << V[i] << ' ';
//    }
//    cout << '\n';

    // 添加源点到左侧节点的边，容量为1
    for(int u : U) {
        g.addEdge(S, u, 1);
    }

    // 添加右侧节点到汇点的边，容量为1
    for(int v : V) {
        g.addEdge(v, T, 1);
    }

    // 读取并添加边，从左侧节点到右侧节点，容量为1


    // 计算最大流（即最大匹配）
    g.maxFlow(S, T);
    // cout << "最大匹配数: " << max_matching << "\n";

    // 构建残差网络
    Graph residual = g.getResidualGraph();
//    residual.printGraph();

    // 统计 a 和 b
    int a = 0, b = 0;

    // 在残差网络中，源点 S 到左侧节点的边，统计剩余容量 > 0
    for(int u : U) {
        for(auto &edge : residual.adjList[S]) {
            if(edge.to == u && edge.capacity > 0) {
                a++;
                break; // 每个左侧节点只有一条从 S 到它的边
            }
        }
    }

    // 在残差网络中，右侧节点到汇点 T 的边，统计剩余容量 > 0
    for(int v : V) {
        for(auto &edge : residual.adjList[v]) {
            if(edge.to == T && edge.capacity > 0) {
                b++;
                break; // 每个右侧节点只有一条到 T 的边
            }
        }
    }
    cout << a << ' ' << b << '\n';

    // 输出 a * b
    cout << (1LL * a * b) << "\n"; // 使用 1LL 防止溢出
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
