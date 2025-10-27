#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

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

int node[N];

int find(int x) {
    return x == node[x] ? x : node[x] = find(node[x]);
}

struct Basis{
    static const int bits = 62;

    vector<ll> bs, t;
    int flag;

    Basis() : bs(bits + 1), t(bits + 1), flag(0) {}

    void insert(ll x){
        for(int i = bits; i >= 0; i--){
            if(x & (1ll << i)){
                if (!bs[i]){
                    bs[i] = x;
                    return;
                }
                x ^= bs[i];
            }
        }
        flag = 1;
    }

    bool check(ll x){ //查询一个数是否可以被一堆数异或出来
        for(int i = bits; i >= 0; i--){
            if(x & (1ll << i)){
                if(!bs[i]) return 0;
                x ^= bs[i];
            }
        }
        return true;
    }

    ll get_min(ll res = 0){
        for(int i = bits; i >= 0; i--) {
            res = chmin(res, res ^ bs[i]);
        }
        return res;
    }

    ll query(ll k){
        ll res = 0, cnt = 0;

        k -= flag;
        if(!k) return 0;

        for(int i = 0; i <= bits; i++){
            for(int j = i - 1; j >= 0; j--){
                if(bs[i] & (1ll << j)){
                    bs[i] ^= bs[j];
                }
            }
            if(bs[i]) t[cnt++] = bs[i];
        }

        if(k >= (1ll << cnt)) return -1;

        for(int i = 0; i < cnt; i++){
            if(k & (1ll << i)){
                res ^= t[i];
            }
        }
        return res;
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        node[i] = i;
    }

    vector<vector<ll>> a;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        a.push_back({w, u, v});
    }

    sort(a.begin(), a.end());
    vector<vector<pair<int, ll>>> adj(n + 1);
    vector<vector<ll>> c;

    for (int i = 0; i < m; i++) {
        ll w = a[i][0], x = a[i][1], y = a[i][2];
        if (find(x) != find(y)) {
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});

            if (x > y) {
                swap(x, y);
            }
            node[find(x)] = find(y);
        }
        c.push_back({x, y, w});
    }

    vector<ll> xr(n + 1);

    auto dfs = [&](auto& self, int u, int fa) -> void {
        for (auto& [v, w] : adj[u]) {
            if (v == fa) {
                continue;
            }
            xr[v] = xr[u] ^ w;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 1);

    Basis bs;
    for (int i = 0; i < c.size(); i++) {
        ll x = c[i][0], y = c[i][1], w = c[i][2];
        bs.insert(xr[x] ^ xr[y] ^ w);
    }

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << bs.get_min(xr[u] ^ xr[v]) << "\n";
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

    while (t--) {
        solve();
    }

    return 0;
}
