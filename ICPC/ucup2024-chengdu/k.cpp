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

const int N = (int)1e6 + 1, M = N * 2;

template<typename T>
struct CostFlow {
    using V = bool;
    using E = int;

    E id, s, t, n, m;
    T INF;

    vector<E> pre, h, ne, e;
    vector<T> d, f, w, incf;
    vector<V> st;
    V rev;

    CostFlow(E n, E m, E s, E t, T INF): n(n), m(m), INF(INF), s(s), t(t){
        h.assign(n, -1), pre.resize(n), incf.resize(n), st.resize(n), d.resize(n);
        e.resize(m << 1), ne.resize(m << 1), f.resize(m << 1), w.resize(m << 1);
        rev = id = 0;
    }

    T EK(){
        T cost = 0;
        while(spfa()){
            T tmp = incf[t];
            cost += d[t] * tmp;

            for(E i = t; i != s; i = e[pre[i] ^ 1]){
                f[pre[i]] -= tmp;
                f[pre[i] ^ 1] += tmp;
            }
        }
        return rev ? -cost : cost;
    }
    void reverse(){
        for(E i = 0; i < id; i += 2){
            f[i] += f[i ^ 1];
            f[i ^ 1] = 0;
            w[i] = -w[i];
            w[i ^ 1] = -w[i ^ 1];
        }
        rev = 1;
    }

    V spfa(){
        fill(d.begin(), d.end(), INF);
        fill(incf.begin(), incf.end(), 0);
        queue<E> q;

        q.push(s); d[s] = 0; incf[s] = INF;
        st.assign(n, 0);
        st[s] = 1;

        while(!q.empty()){
            E u = q.front(); q.pop();
            st[u] = 0;
            for(E i = h[u]; i != -1; i = ne[i]){
                E v = e[i];

                if(f[i] > 0 && d[v] > d[u] + w[i]){
                    d[v] = d[u] + w[i];
                    pre[v] = i;
                    incf[v] = chmin(incf[u], f[i]);

                    if(!st[v]){
                        q.push(v);
                        st[v] = 1;
                    }
                }
            }
        }
        return incf[t] > 0;
    }

    void add(E u, E v, T cap, T cost){
        e[id] = v; f[id] = cap; w[id] = cost; ne[id] = h[u]; h[u] = id++;
        e[id] = u; f[id] = 0; w[id] = -cost; ne[id] = h[v]; h[v] = id++;
    }
};

map<int, map<int, int>> vis, rec;
map<int, int> mp, d, p;
int n;

void dfs1(int x, int fa, CostFlow<int>& fl, int dep){
    if(x <= 1) return;
    for(int i = 1; i * i <= x; i++){
        if(x % i == 0){
            if(vis[fa][i] < dep){
                vis[fa][i] = vis[i][fa] = dep;
                dfs1(i, fa, fl, dep + 1);
            }
            if(i != 1 && i != x / i){
                if(vis[fa][x / i] < dep){
                    vis[fa][x / i] = vis[x / i][fa] = dep;
                    dfs1(x / i, fa, fl, dep + 1);
                }
            }
        }
    }
}

void dfs2(int x, int fa, CostFlow<int>& fl){
    if(p[x]) return;
    mp[x] = p[x] = 1;
  
    for(int i = 1; i * i <= x; i++){
        if(x % i == 0){
            dfs2(i, fa, fl);

            if(!rec[fa][i]){
                rec[fa][i] = rec[i][fa] = 1;
                fl.add(d[fa], d[i], n, vis[fa][i]);
            }

            if(i != 1 && i != x / i){
                dfs2(x / i, fa, fl);

                if(!rec[fa][x / i]){
                    rec[fa][x / i] = rec[x / i][fa] = 1;
                    fl.add(d[fa], d[x / i], n, vis[fa][x / i]);
                }
            }
        }
    }
}

void solve() {
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int S = N, T = S + 1, V = T + 1;
    CostFlow<int> fl(N + 10, N + 10, S, V, (int)1e9);

    for(int i = 0; i < n; i++){
        for(int j = 1; j * j <= a[i]; j++){
            if(a[i] % j == 0){
                b.pb(a[i] / j);
                b.pb(j);
            }
        }
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for(int i = 0; i < b.size(); i++){
        d[b[i]] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        fl.add(S, d[a[i]], 1, 0);
    }

    mp[1] = 1;
    for(int i = 0; i < n; i++){
        vis.clear();
        rec.clear();
        p.clear();
        dfs1(a[i], a[i], fl, 1);
        dfs2(a[i], a[i], fl);
    }

    for(auto [x, y] : mp){
        fl.add(d[x], T, 1, 0);
    }

    fl.add(T, V, n, 0);
    fl.reverse();
    cout << fl.EK() << endl;
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
