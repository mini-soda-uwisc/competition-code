#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;
const double MAXN = 1e4 + 0.1;

template <typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)6e5 + 1, M = N * 2;

ld a[N], b[N], sqr[N], ps[N];

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i];
        ps[i] = ps[i - 1] + a[i] * a[i];
    }

    ld ans = 2 * INF;
    for (int i = k; i <= n; i++) {
        ld mean = (b[i] - b[i - k]) / k;
        ld sum = b[i] - b[i - k];
        ld ssum = ps[i] - ps[i - k];
        ans = chmin(ans, k * mean * mean - 2 * mean * sum + ssum);
    }
    cout << setprecision(20) << ans << "\n";
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    double ans = MAXN;

    while (t--) {
        solve();
    }

    return 0;
}
