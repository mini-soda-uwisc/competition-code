#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
const int N = 1010;
int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}

struct point3d {
    double x, y, z;
    point3d operator - (const point3d& p) const {
        return {x - p.x, y - p.y, z - p.z};
    }

};

struct point {
    double x, y;
    Point() {
    }
    Point(double x, double y) : x(x), y(y) {}
    double operator ^ (const point &b) const {
        return x * b.y - y * b.x;
    }

    point operator - (const point& b) const {
        return {x - b.x, y - b.y};
    }
};

struct line {
    point s, e;
    line() {

    }
    line(point s, point e) : s(s), e(e) {
        if (s.y > e.y || (s.y == e.y && s.x > e.x)) {
            swap(s, e);
        }
    }

    int segcrossseg(line v) {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        int d3 = sgn((v.e - v.s) ^ (s - v.s));
        int d4 = sgn((v.e - v.s) ^ (e - v.s));
        if ( (d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 2;
        return (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0) ||
            (d2 == 0 )
    }
};



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    struct p {
        long double x, y;
    };

    vector<p> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }

    struct line {
        char u, v;
        int hu, hv;
    };

    vector<line> b;
    for (int i = 0; i < m; i++) {
        char u, v;
        cin >> u >> v;


    }
    cout << ans << '\n';
}