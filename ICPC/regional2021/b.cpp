#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
// const int mod = 998244353;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)2e5 + 1, M = N * 2;
ll c[N], p10[N], mod;

ll qpow(ll a, ll b, ll m){
    ll res = 1;  
    a = a % m;  
    
    while(b > 0){
        if(b % 2 == 1){
            res = (res * a) % m; 
        }
        a = (a * a) % m; 
        b /= 2;  
    }
    
    return res;
}

struct LCA{
    vector<int> h, w, e, ne, dep;
    vector<vector<int>> fa;
    vector<vector<ll>> f;
    vector<ll> p;
    int n, idx;

    const int depth = 18;

    LCA(int _n){
        n = _n;
        idx = 0;

        dep.resize(n, (int)1e9);
        fa.resize(n);
        f.resize(n);

        ne.resize(n * 2, 0);
        h.resize(n * 2, -1);
        e.resize(n * 2, 0);
        p.resize(n + 1);

        for(int i = 0; i < n; i++){
            fa[i] = vector<int>(depth + 1);
            f[i] = vector<ll>(depth + 1);
        }
    }

    void add(int u, int v) {
        e[idx] = v, ne[idx] = h[u], h[u] = idx++;
        e[idx] = u, ne[idx] = h[v], h[v] = idx++;
    }

    void bfs(int rt) {
        dep[rt] = 1;
        dep[0] = 0;
        p[rt] = c[rt];

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

                    p[j] = (p[u] * 10 % mod + c[j] + mod) % mod;
                    f[j][0] = c[u];
                    fa[j][0] = u;
                    
                    for(int k = 0; k < depth; k++){
                        fa[j][k + 1] = fa[fa[j][k]][k];
                    }
                    for(int k = 0; k < depth; k++){
                        int t = fa[j][k];
                        f[j][k + 1] = (f[j][k] * p10[1 << k] % mod + f[t][k] + mod) % mod;
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

ll calc1(int u, int v, const LCA& lca){
    int dep = lca.dep[u] - lca.dep[v];
    ll qwq = c[u];

    for(int i = lca.depth; i >= 0; i--){
        if(dep >= (1 << i)){
            dep -= (1 << i);
            qwq = (qwq * p10[1 << i] % mod + lca.f[u][i] + mod) % mod; 
            u = lca.fa[u][i];
        }
    }
    return qwq;
}

ll calc2(int u, int v, const LCA &lca){
    ll pu = lca.p[u], pv = lca.p[v];
    ll uwu = (pv - pu * p10[lca.dep[v] - lca.dep[u]] + mod) % mod;
    return (uwu + mod) % mod;
}

void solve(){
    int n, q;
    cin >> n >> mod >> q;

    LCA lca(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;

        lca.add(u, v);
    }

    p10[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        c[i] %= mod;

        lca.f[i][0] = c[i];
        p10[i] = qpow(10, i, mod);
    }

    lca.bfs(1);

    for(int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        int anc = lca.lca(u, v);
        ll up = calc1(u, anc, lca);
        ll down = calc2(anc, v, lca);
        ll l = lca.dep[v] - lca.dep[anc];
        cout << (down + up * p10[l] % mod + mod) % mod << endl;
    }
}

int main(){
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
