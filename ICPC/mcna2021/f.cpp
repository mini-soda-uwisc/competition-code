#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n, k;
string a[N];

struct SCC {
    vector<int> dfn, low, id, visited;
    stack<int> stk;
    vector<vector<int>> adj;
    int timestamp, cnt;

    SCC(int _n) : dfn(_n), low(_n), id(_n), visited(_n), adj(_n) {
        timestamp = cnt = 0;
    }

    void add(int u, int v) {
        adj[u].push_back(v);
    }

    void Tarjan(int u) {
        dfn[u] = low[u] = ++timestamp;
        stk.push(u);
        visited[u] = true;

        for(int j : adj[u]) {
            if(!dfn[j]) {
                Tarjan(j);
                low[u] = min(low[u], low[j]);
            }
            else if(visited[j]) {
                low[u] = min(low[u], dfn[j]);
            }
        }

        if(dfn[u] == low[u]) {
            cnt++;
            int y;
            do {
                y = stk.top();
                stk.pop();
                visited[y] = false;
                id[y] = cnt;
            } while(y != u);
        }
    }
};

// 修改变量编码方式
inline int neg(int x) {
    return x ^ 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = " " + a[i];
    }

    SCC g(k * 2);

    for (int i = 1; i <= n; ++i) {
        vector<pair<int, bool>> answers;
        for (int j = 1; j <= k; ++j) {
            if (a[i][j] != 'X') {
                // 将答案转换为变量编号：j*2 表示第j题选T，j*2+1 表示第j题选F
                int var = (j-1) * 2;
                if (a[i][j] == 'F') var++;
                answers.push_back({var, a[i][j] == 'T'});
            }
        }
        
        // 对每对答案添加约束
        for (size_t p = 0; p < answers.size(); p++) {
            for (size_t q = p + 1; q < answers.size(); q++) {
                int u = answers[p].first;
                int v = answers[q].first;
                // 如果u正确，则v必须错误
                g.add(u, neg(v));
                // 如果v正确，则u必须错误
                g.add(v, neg(u));
            }
        }
    }

    for (int i = 0; i < k * 2; ++i) {
        if (!g.dfn[i]) {
            g.Tarjan(i);
        }
    }

    string res(k, ' ');
    for (int i = 0; i < k; ++i) {
        int t = i * 2;
        if (g.id[t] == g.id[t^1]) {
            cout << "-1\n";
            return 0;
        }
        // 如果T的编号大于F的编号，选F；否则选T
        res[i] = (g.id[t] > g.id[t^1]) ? 'F' : 'T';
    }

    cout << res << '\n';
    return 0;
}