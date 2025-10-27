#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

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
    int n, m;
    cin >> n >> m;

    int S = N + 1, T = S + 1;
    CostFlow<ll> cf(N + 3, N + 3, S, T, INF);

    for (int i = 0; i < n; i++) {
        cf.add(S, i, 1, 0);
        cf.add(i, n + i, 1, 0);
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        cf.add(u, n + v, 1, w);
    }

    for (int i = 0; i < n; i++) {
        cf.add(n + i, T, 1, 0);
    }

    cf.reverse();
    cout << setprecision(20) << cf.EK() * 0.05 << "\n";
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
