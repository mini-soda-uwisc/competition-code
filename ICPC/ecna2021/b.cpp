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

struct LCA{
    vector<int> h, w, e, ne, dep;
    vector<vector<int>> fa;
    int n, idx;

    const int depth = 18;

    LCA(int _n){
        n = _n;
        idx = 0;

        dep.resize(n, (int)1e9);
        fa.resize(n);

        ne.resize(n * 2, 0);
        h.resize(n * 2, -1);
        e.resize(n * 2, 0);

        for(int i = 0; i < n; i++){
            fa[i] = vector<int>(depth + 1);
        }
    }

    void add(int u, int v) {
        e[idx] = v, ne[idx] = h[u], h[u] = idx++;
        e[idx] = u, ne[idx] = h[v], h[v] = idx++;
    }

    void bfs(int rt) {
        dep[rt] = 1;
        dep[0] = 0;

        queue<int> q;
        q.push(rt);

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i = h[u]; i != -1; i = ne[i]){
                int j = e[i];
                if(dep[j] > dep[u] + 1){
                    dep[j] = dep[u] + 1;

                    q.push(j);
                    fa[j][0] = u;
                    for(int k = 1; k < depth; k++){
                        fa[j][k] = fa[fa[j][k - 1]][k - 1];
                    }
                }
            }
        }
    }

    int lca(int u, int v){
        if(dep[u] < dep[v]) swap(u, v);

        for(int i = depth - 1; i >= 0; i--){
            if(dep[fa[u][i]] >= dep[v]){
                u = fa[u][i];
            }
        }
        if(u == v) return u;

        for(int i = depth - 1; i >= 0; i--){
            if (fa[u][i] != fa[v][i]){
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return fa[u][0];
    }
};

int h[N], e[M], ne[M], idx;

void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void solve(){
    int n, m;
    cin >> n >> m;

    int a[n + 1], outd[n + 1], ind[n + 1];
    LCA lca(n + 1);

    for(int i = 1; i <= n; i++){
        ind[i] = outd[i] = 0;
        cin >> a[i];
        h[i] = -1;
    }
    idx = 0;

    int f[n + 1];
    for(int i = 0; i <= n; i++){
        f[i] = (int)1e9;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        add(u, v);
        lca.add(u, v);
        ind[v]++, outd[u]++;
    }

    for(int i = 1; i <= n; i++){
        if(ind[i] == 0){
            lca.bfs(i);
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(ind[i] == 0){
            q.push(i);
            f[i] = a[i];
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = h[u]; ~i; i = ne[i]){
            int v = e[i];

            f[v] = min(f[v], f[u] + a[v]);
            ind[v]--;
            if(ind[v] == 0){
                q.push(v);
            }
        }
    }

    int qwq = (int)1e9;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j && outd[i] == 0 && outd[j] == 0){
                if(lca.lca(i, j) == 0){
                    qwq = chmin(qwq, f[i] + f[j]);
                }
                else {
                    qwq = chmin(qwq, f[i] + f[j] - f[lca.lca(i, j)]);
                }
            }
        }
    }
    cout << qwq << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}