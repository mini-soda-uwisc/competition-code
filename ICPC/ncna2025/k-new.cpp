#include <bits/stdc++.h>
using namespace std;

struct Point {
    long double x, y;

    Point(long double x, long double y) : x(x), y(y) {

    }

    Point operator- (const Point & b) {
        return Point(x - b.x, y - b.y);
    }

    Point operator+ (const Point& b) {
        return Point(x + b.x, y + b.y);
    }

    Point operator* (long double t) const{
        return Point(x * t, y * t);
    }

    friend Point operator+ (const Point& a, const Point& b) {
        return {a.x + b.x, a.y + b.y};
    }

    friend Point operator- (const Point& a, const Point& b) {
        return {a.x - b.x, a.y - b.y};
    }

    int sign(long double x) {
        if (fabs(x) < 1e-9) {
            return 0;
        }
        if (x < 0) {
            return -1;
        }
        return 1;
    }

    long double cross(const Point& a, const Point& b) {
        return a.x * b.y - a.y * b.x;
    }

    bool seg_int(const Point a1, const Point a2, const Point b1, const Point b2) {
        long double c1 = cross(a2 - a1, b1 - a1);
        long double c2 = cross(a2 - a1, b2 - a1);
        long double c3 = cross(b2 - b1, a2 - a1);
        long double c4 = cross(b2 - b1, a1 - b1);

        return sign(c1) * sign(c2) <= 0 && sign(c3) * sign(c4) <= 0;
    }

    Point intersect(const Point& p, const Point& v, const Point& q, const Point& w) {
        Point u = p - q;
        long double t = cross(w, u) / cross(v, w);
        return p + v * t;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Point> a;
    for (int i = 0; i < n; i++) {
        long double x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }

    int mask[m];
    struct info {
        char u, v;
        int hu, hv;
    };

    vector<info> b;
    for (int i = 0; i < m; i++) {
        char u, v;
        cin >> u >> v;

        int hu, hv;
        cin >> hu >> hv;

        b.push_back({u, v, hu, hv});
    }

    for (int i = 0; i < m; i++) {
        int u = b[i].u - 'A', v = b[i].v - 'A';
        Point p1 = a[u], p2 = a[v];

        mask[i] = 1 << i;
        for (int j = 0; j < m; j++) {
            if (i == j) {
                continue;
            }

            int du = b[j].u - 'A', dv = b[j].v - 'A';
            Point p3 = a[u], p4 = a[v];

            if (p1 == p3 && p2 == p4) {
                
            }

            auto vec1 = p2 - p1, vec2 = p4 - p3;
            if (!p1.seg_int(p1, p2, p3, p4)) {
                continue;
            }

            auto tp = p1.intersect(p1, vec1, p2, vec2);
            long double h1 = b[i].hu - (p1.x - tp.x) / (p1.x - p2.x) * (b[i].hv - b[i].hu);
            long double h2 = b[j].hu - (p3.x - tp.x) / (p3.x - p4.x) * (b[j].hv - b[j].hu);

            if (fabs(h1 - h2) >= 6) {
                mask[i] |= 1 << j;
            }
            else {
                if (i > j) {
                    cout << b[i].u << b[i].v << " " << b[j].u << b[j].v << " " << "too close\n";
                }
            }
        }
    }

    int mx = 0;
    for (int i = 0; i < 1 << m; i++) {
        int _mask = i;

        for (int j = 0; j < m; j++) {
            _mask &= mask[j];
        }

        if (_mask == i) {
            int ans = 0;
            for (int j = 0; j < 30; j++) {
                if (i >> j & 1) {
                    ans++;
                }
            }

            mx = max(mx, ans);
        }
    }

    cout << mx << " ziplines" << "\n";

    return 0;
}