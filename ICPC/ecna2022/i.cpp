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

int h[N], e[M], ne[M], w[M], idx;

void add(int u, int v, int c) {
    e[idx] = v, w[idx] = c, ne[idx] = h[u], h[u] = idx++;
}

void solve(){
    int n, m;
    cin >> n >> m;

    int f[n][m];
    memset(f, 0, sizeof f);

    for(int i = 0; i < n; i++){
        h[i] = -1;
    }
    idx = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> f[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int w;
            cin >> w;

            if(w != -1){
                add(i, j, w);
            }
        }
    }

    ll d[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = INF;
        }
    }

    ll p[m][n];
    memset(p, 0, sizeof p);

    for(int i = 0; i < n; i++){
        d[i][i] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

        int v[n];
        memset(v, 0, sizeof v);

        q.push({0, i});
        while(!q.empty()){
            auto [dis, u] = q.top();
            q.pop();

            if(v[u]){
                continue;
            }
            v[u] = 1;

            for(int j = h[u]; j != -1; j = ne[j]){
                int v = e[j];
                if(d[i][v] > d[i][u] + w[j]){
                    d[i][v] = d[i][u] + w[j];
                    q.push({d[i][v], v});
                }
            }
        }
    }

    ll dp[m][n];
    memset(dp, 0, sizeof dp);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                dp[i][j] += d[k][j] * f[k][i];
            }
        }
    }

    int S = n * m * 2 + 1, T = S + 1, V = T + 1;
    CostFlow<ll> cf(n * m * 2 + 4, (n * m + 1) * 4, S, V, INF);

    for(int i = 0; i < m; i++){
        cf.add(S, i, 1, 0);
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cf.add(i, m + j, 1, dp[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        cf.add(m + i, T, 1, 0);
    }

    cf.add(T, V, m, 0);

    cout << cf.EK() << endl;
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