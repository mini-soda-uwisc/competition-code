#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ld = long double;
using ll = long long;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b){
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b){
    return a > b ? b : a;
}

const int N = (int)2e5 + 1, M = N * 10;
int h[N], e[M], ne[M], idx;

void add(int u, int v){
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++){
        h[i] = -1;
    }
    idx = 0;

    map<int, int> mp;
    for(int i = 0; i < q; i++){
        int u;
        cin >> u;
        mp[u] = 1;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    auto spfa = [&](int u) -> vector<int>{
        queue<int> q;
        vector<int> f(n + 1, (int)1e9 + 1);

        f[u] = 0;
        q.push(u);
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            for(int i = h[p]; i != -1; i = ne[i]){
                int j = e[i];
                if(f[j] > f[p] + 1){
                    f[j] = f[p] + 1;
                    q.push(j);
                }
            }
        }

        return f;
    };

    auto dp = spfa(1);
    auto ndp = spfa(n);

    ll qwq = 0;
    for(auto [k, v] : mp){
        qwq += ndp[k];
    }

    ll r = INF;
    for(auto [k, v] : mp){
        if((qwq - ndp[k] + (q - 1) * dp[k]) < ndp[1] * (q - 1)){
            if(qwq - ndp[k] + (q - 1) * dp[k] < r){
                r = qwq - ndp[k] + (q - 1) * dp[k];
            }
        }
    }
    if(r == INF){
        r = ndp[1];
    }

    if(r == ndp[1]){
        cout << ndp[1] << "/" << 1 << endl;
    }
    else{
        cout << r / __gcd(r, q - 1ll) << "/" << (q - 1ll) / __gcd(r, q - 1ll) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}