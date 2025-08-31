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

void solve() {
    int n, m;
    cin >> n >> m;

    int ans = (int)2e9;
    for (int i = 1; i <= chmin(31, m); i++) {
        int sum = (1 << i) - 1;
        int rem = m - i;
        if (i == m && sum >= n) {
            ans = chmin(ans, 1 << (i - 1));
        }
        if (rem && sum >= (int)((n - sum + rem - 1) / rem)) {
            ans = chmin(ans, chmax(1 << (i - 1), (int)((n - sum) * 1.0 + rem - 1)/ rem));
        }
    }
    cout << (ans == 2e9 ? -1 : ans) << "\n";
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
