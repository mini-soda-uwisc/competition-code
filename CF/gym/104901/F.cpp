#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

struct MinCostFlow{
    struct Edge{
        int to, cap, cost, rev;
    };

    int n;
    vector<vector<Edge>> G;
    vector<int> dist, prevv, preve;

    MinCostFlow(int n) : n(n), G(n), dist(n), prevv(n), preve(n) {}

    void addEdge(int from, int to, int cap, int cost){
        G[from].pb({to, cap, cost, (int)G[to].size()});
        G[to].pb({from, 0, -cost, (int)G[from].size() - 1});
    }

    int minCostFlow(int s, int t, int f){
        int res = 0;
        while(f > 0){
            fill(dist.begin(), dist.end(), INF);
            dist[s] = 0;
            bool update = true;
            while(update){
                update = false;
                for(int v = 0; v < n; v++){
                    if(dist[v] == INF) continue;
                    for(int i = 0; i < G[v].size(); i++){
                        Edge &e = G[v][i];
                        if(e.cap > 0 && dist[e.to] > dist[v] + e.cost){
                            dist[e.to] = dist[v] + e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            update = true;
                        }
                    }
                }
            }

            if(dist[t] == INF) return -1;

            int d = f;
            for(int v = t; v != s; v = prevv[v]){
                d = min(d, G[prevv[v]][preve[v]].cap);
            }

            f -= d;
            res += d * dist[t];
            for(int v = t; v != s; v = prevv[v]){
                Edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }

        return res;
    }
};

void solve(){
    int n, m;
    cin >> n >> m;

    MinCostFlow fl(n + 3);
    vector<int> a(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int S = 0, L = n + 1, T = n + 2;
    vector<vector<int>> e;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        fl.addEdge(u, v, a[u], 1);
        e.pb({u, v});
    }

    for(int i = 1; i <= n; i++){
        fl.addEdge(S, i, INF, 0);
    }
    for(int i = 1; i <= n; i++){
        fl.addEdge(i, L, INF, INF);
    }
    fl.addEdge(L, T, INF, 0);
    int qwq = fl.minCostFlow(S, T, INF);
    cout << qwq << endl;

    for(int i = 0; i < e.size(); i++){
        int u = e[i][0], v = e[i][1];
        auto edge = fl.G[u][v];
        if(fl.G[u][edge.rev].cap != 0){
            cout << '1';
        }
        else{
            cout << '0';
        }
    }
    cout << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

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