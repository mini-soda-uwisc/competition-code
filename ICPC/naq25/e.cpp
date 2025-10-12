#include <bits/stdc++.h>
using namespace std;

#define ld long double

int n, m;

struct Point {
    ld x, y;
};

inline ld dis2(Point& a, Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

Point r[10], y[10];
Point b1 = {144, 84};

int sr = 0, sy = 0;

inline void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> r[i].x >> r[i].y;
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> y[i].x >> y[i].y;

    ld mir = 1e18, miy = 1e18;
    for (int i = 1; i <= n; ++i) mir = min(mir, dis2(r[i], b1));
    for (int i = 1; i <= m; ++i) miy = min(miy, dis2(y[i], b1));

    if (mir < miy) {
        for (int i = 1; i <= n; ++i) {
            if (dis2(r[i], b1) < miy) ++sr;
        }
    } else {
        for (int i = 1; i <= m; ++i) {
            if (dis2(y[i], b1) < mir) ++sy;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i = 1; i <= 10; ++i) {
        solve();
    }

    cout << sr << ' ' << sy << '\n';
    return 0;
}