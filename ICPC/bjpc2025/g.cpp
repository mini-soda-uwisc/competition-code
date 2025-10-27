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

const int N = (int)5e5 + 1, M = N * 2;
int dp[N][2];

void solve() {
    int n;
    cin >> n;

    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        int fac = a[i];
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                if (j > 1) {
                    fac = chmin(fac, j);
                }
                if (a[i] / j > 1) {
                    fac = chmin(fac, a[i] / j);
                }
            }
        }

        dp[fac][1] += (dp[fac][0] != b[i]);
        dp[fac][0] = b[i];

        // cout << fac << " " << dp[fac][0] << " " << dp[fac][1] << "\n";
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
        max = chmax(max, dp[i][1]);
    }
    cout << max << "\n";
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