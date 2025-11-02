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

int h[N], e[M], ne[M], w[M], idx;

void add(int u, int v, int c){
     e[idx] = v, ne[idx] = h[u], w[idx] = c, h[u] = idx++;
}

void solve(){
    int n, m, l, r;
    cin >> n >> m >> l >> r;

    for(int i = 0; i <= n; i++){
         h[i] = -1;
    }

    for(int i = 0; i < m; i++){
         int u, v, w;
         cin >> u >> v >> w;
         add(u, v, w), add(v, u, w);
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    vector<ll> dp(n + 1, INF);
    dp[0] = 0;

    q.push({0, 0});
    map<int, int> mp;

    while(!q.empty()){
        auto p = q.top();
        q.pop();

        int u = p.second;
        ll c = p.first;

        for(int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if(dp[j] > dp[u] + w[i]){
                dp[j] = dp[u] + w[i];
                q.push({dp[j], j});
            }
        }
    }
    // for (auto [k, v] : mp) {
    //     cout << k << endl;
    // }
    for (int i = 0; i < n; i++) {
        if (dp[i] * 2 < r) {
            for (int j = h[i]; j != -1; j = ne[j]) {
                mp[j / 2]++;
            }
        }
    }

    cout << mp.size() << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
