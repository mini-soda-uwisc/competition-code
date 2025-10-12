#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;
const double MAXN = 1e4 + 0.1;

template <typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

template<typename T>
struct MaxFlow {
    using V = bool;
    using E = int;

    vector<E> h, e, ne, cur;
    vector<T> f, d;

    E id, s, t, n, m;
    T INF;

    MaxFlow(E n, E m, E s, E t, T INF): n(n), m(m), s(s), t(t), INF(INF){
        e.resize(m << 1), ne.resize(m << 1), f.resize(m << 1);
        h.assign(n, -1), cur.resize(n), d.resize(n);
        id = 0;
    }

    V bfs(){
        queue<E> q;
        q.push(s);
        fill(d.begin(), d.end(), -1);
        d[s] = 0;
        cur[s] = h[s];

        while(!q.empty()){
            E u = q.front();
            q.pop();

            for(E i = h[u]; i != -1; i = ne[i]){
                E v = e[i];
                if(d[v] == -1 && f[i] > 0){
                    d[v] = d[u] + 1;
                    cur[v] = h[v];
                    if(v == t) return 1;
                    q.push(v);
                }
            }
        }
        return 0;
    }

    T find(E u, T flow_limit){
        if(u == t) return flow_limit;
        T flow = 0;
        for(E i = cur[u]; i != -1 && flow < flow_limit; i = ne[i]){
            E v = e[i];

            if(d[v] == d[u] + 1 && f[i] > 0){
                T tmp = find(v, chmin(flow_limit - flow, f[i]));
                if(tmp > 0){
                    f[i] -= tmp;
                    f[i ^ 1] += tmp;
                    flow += tmp;
                }
                else{
                    d[v] = -1;
                }
            }
        }
        return flow;
    }

    T dinic(){
        T maxflow = 0;
        while(bfs()){
            T flow;
            while((flow = find(s, INF)) > 0){
                maxflow += flow;
            }
        }
        return maxflow;
    }

    void add(E u, E v, T cap){
        e[id] = v; f[id] = cap; ne[id] = h[u]; h[u] = id++;
        e[id] = u; f[id] = 0; ne[id] = h[v]; h[v] = id++;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    int S = N + 1, T = S + 1;
    MaxFlow<ll> mf(N + 3, N + 3, S, T, INF);

    for (int i = 1; i<= n; i++) {
        mf.add(S, i, 10000);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        mf.add(u, v + n, 10000);
        mf.add(v, u + n, 10000);
    }

    for (int i = 1; i <= n; i++) {
        mf.add(i + n, T, 10000);
    }

    ll ans = mf.dinic();
    if (ans != n * 10000) {
        cout << -1 << "\n";
    }
    else {
        int a[n + 1][n + 1];
        memset(a, 0, sizeof a);

        for (int i = 1; i <= n; i++) {
            for (int j = mf.h[i]; j != -1; j = mf.ne[j]) {
                int v = mf.e[j];
                if (n <= v && v <= 2 * n) {
                    a[i][v - n] = mf.f[1 ^ j];
                }
            }
        }

        for (int i = 1; i <=n; i++) {
            for (int j = 1; j<= n; j++) {
                cout << a[i][j] << " \n"[j == n];
            }
        }
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    double ans = MAXN;

    while (t--) {
        solve();
    }

    return 0;
}
