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

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), o(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        o[i] = a[i];
    }

    int S = N, T = S + 1, V = T + 1;
    CostFlow<int> fl(N + 10, N + 10, S, V, (int)1e9);

    map<int, map<int, int>> vis;
    map<int, int> mp, d;

    for(int i = 0; i < n; i++){
        for(int j = 1; j * j <= a[i]; j++){
            if(a[i] % j == 0){
                a.pb(a[i] / j);
                a.pb(j);
            }
        }
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for(int i = 0; i < a.size(); i++){
        d[a[i]] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        fl.add(S, d[o[i]], 1, 0);
    }

    reverse(a.begin(), a.end());
    mp[1] = 1;

    for (int i = 0; i < a.size(); i++){
        if(a[i] == 1) continue;
        mp[a[i]] = 1;

        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                if(!vis[a[i]][j]) {
                    vis[a[i]][j] = vis[j][a[i]] = 1;
                    fl.add(d[a[i]], d[j], n, 1);
                }
                if (j != 1 && j != a[i] / j) {
                    if(!vis[a[i]][a[i] / j]) {
                        vis[a[i]][a[i] / j] = vis[a[i] / j][a[i]] = 1;
                        fl.add(d[a[i]], d[a[i] / j], n, 1);
                    }
                }
            }
        }
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