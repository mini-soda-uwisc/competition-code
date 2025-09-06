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
ll dp[3001][3001], mx[3001][3001];

void solve() {
    int n;
    cin >> n;

    ll a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 3001; i++) {
        for (int j = 0; j < 3001; j++) {
            dp[i][j] = -INF;
            mx[i][j] = -INF;
        }
    }

    for (int i = 1; i <= n; i++) {
        mx[1][i] = a[1];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            int len = i - j;
            dp[i][len] = chmax(dp[i][len], mx[j][len] + a[i]);
        }
        for (int j = n - 1; j >= 1; j--) {
            mx[i][j] = chmax(mx[i][j + 1], dp[i][j]);
        }
    }

    ll ans = -INF;
    for (int i = 1; i <= n; i++) {
        ans = chmax(ans, dp[n][i]);
    }

    cout << ans << "\n";
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
