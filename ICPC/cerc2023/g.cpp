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
    ld xa, ya, xb, yb, xc, yc, rc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> rc;

    xa = xa - xc;
    xb = xb - xc;
    ya = ya - yc;
    yb = yb - yc;

    auto get_dist = [&](ld x1, ld y1, ld x2, ld y2) -> ld {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };

    int A = fabsl(get_dist(xa, ya, 0, 0)) - rc * rc <= 1e-6;
    int B = fabsl(get_dist(xb, yb, 0, 0)) - rc * rc <= 1e-6;

    if ((!A && B) || (A && !B) || (A && B)) {
        cout << setprecision(20) << sqrt(get_dist(xa, ya, xb, yb)) << endl;;
        return;
    }

    ld eps = 1e-6;
    auto f = [&](ld t) -> ld{
        ld x = rc * cos(t), y = rc * sin(t);
        ld dist = sqrt(get_dist(xa, ya, x, y)) + sqrt(get_dist(xb, yb, x, y));
        return dist;
    };

    ld qwq = 1e30;
    auto TRY = [&](ld L, ld R) -> void {
        ld l = L, r = R;
        for (int it = 0; it < 80; ++it) {
            ld m1 = l + (r - l) / 3;
            ld m2 = r - (r - l) / 3;
            ld f1 = f(m1), f2 = f(m2);
            qwq = min(qwq, min(f1, f2));
            if (f1 <= f2) r = m2;
            else l = m1;
        }
    };

    TRY(0, pi);
    TRY(pi, 2 * pi);
    cout << setprecision(20) << qwq << endl;
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
