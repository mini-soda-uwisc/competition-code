#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};

double distance(Point &a, Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int n;
vector<Point> p;

inline int prev(int x) {
    if (x == 0) return n - 1;
    else return x - 1;
}
inline int next(int x) {
    if (x == n - 1) return 0;
    else return x + 1;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    p.reserve(n + 10);
    for (int i = 1; i <= n; ++i) {
        double x, y;
        cin >> x >> y;
        p.emplace_back(Point(x, y));
    }


    double ans = 0;
    for (int i = 0; i < n; ++i) {
        Point &x = p[i], &y = p[prev(i)], &z = p[next(i)];
        double d = distance(x, y) + distance(x, z);
        double dp = distance(y, z) * sqrt(2);
        cout << "d: " << d << '\n';
        cout << "dp: " << dp << '\n';
        ans = max(ans, dp - d);
    }

    printf("%.10lf\n", ans);
    return 0;
}