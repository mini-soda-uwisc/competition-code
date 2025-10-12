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

const int N = (int)1e5 + 1, M = N * 2;

void solve() {
    int r, g, b;
    cin >> r >> g >> b;

    int cr, cg, cb;
    cin >> cr >> cg >> cb;

    int rg, gb;
    cin >> rg >> gb;

    r -= cr;
    g -= cg;
    b -= cb;

    int ans = 0;
    if (r > 0) {
        if (r > rg) {
            cout << -1 << '\n';
            return;
        }
        ans += r;
        rg -= r;
    }

    if (g > 0) {
        if (rg + gb < g) {
            cout << -1 << "\n";
            return;
        }
        ans += g;
        if (rg > 0) {
            g -= chmin(g, rg);
        }
        if (g > 0) {
            gb -= g;
        }
    }
    if (b > 0) {
        if (gb < b) {
            cout << -1 << "\n";
            return;
        }
        ans += b;
        gb -= b;
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
    // cin >> t;

    double ans = MAXN;

    while (t--) {
        solve();
    }

    return 0;
}
