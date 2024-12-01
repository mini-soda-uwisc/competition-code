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

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll a[n], c[n];
    for (int i = 0; i < n; i++) {
        c[i] = 0;
    }

    ll f[n][m];
    vector<vector<ll>> b;

    for (int i = 0; i < n; i++) {
        ll qwq = 0;
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            cin >> f[i][j];
        }
        b.pb({a[i], i});
    }

    sort(b.begin(), b.end());
    for(int i = 0; i < m; i++){
        f[b[0][1]][i] = chmax(0ll, f[b[0][1]][i]);
    }

    for(int i = 1; i < n; i++){
        ll pre = 0, cur = 0;
        for(int j = 0; j < m; j++) {
            pre += f[b[i - 1][1]][j];
            cur += chmax(0ll, f[b[i][1]][j]);
        }

        ll diff = pre - cur;
        if(diff < 0) diff = 0;
        else if(b[i - 1][1] != b[i - 1][0]) diff++;

        for(int j = 0; j < m; j++){
            if(f[b[i][1]][j] == -1){
                f[b[i][1]][j] = chmin(diff, k);
                diff = chmax(diff - k, 0ll);
            }
        }

        if(diff != 0){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}