
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

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> a(n + 1);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        for (int j = 1; j <= chmin(m, n - i); j++) {
            ll y;
            cin >> y;
            a[i].pb({i + j, x - y});
        }
    }

    vector<ll> f(n + 1, INF);
    f[0] = 0;

    for (int i = 0; i < n; i++) {
        for (auto [x, y] : a[i]){
            f[x] = chmin(f[x], f[i] + y);
        }
    }
    cout << f[n] << endl;
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
