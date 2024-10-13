#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
    int idx;
    bool operator<(const Point& p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
};

ll cross(const Point& a, const Point& b, const Point& c) {
    ll dx1 = b.x - a.x, dy1 = b.y - a.y;
    ll dx2 = c.x - a.x, dy2 = c.y - a.y;
    return dx1 * dy2 - dy1 * dx2;
}

vector<Point> convex_hull(vector<Point>& points) {
    sort(points.begin(), points.end());
    int n = points.size();
    vector<Point> hull;

    // Lower hull
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 &&
               cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    // Upper hull
    int t = hull.size() + 1;
    for (int i = n - 2; i >= 0; --i) {
        while ((int)hull.size() >= t &&
               cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    hull.pop_back();  // Remove duplicate point
    return hull;
}

bool cmp(const Point& a, const Point& b, const Point& c) {
    ll dx1 = a.x - c.x, dy1 = a.y - c.y;
    ll dx2 = b.x - c.x, dy2 = b.y - c.y;
    int quad1 = (dy1 > 0 || (dy1 == 0 && dx1 > 0)) ? 0 : 1;
    int quad2 = (dy2 > 0 || (dy2 == 0 && dx2 > 0)) ? 0 : 1;
    if (quad1 != quad2)
        return quad1 < quad2;
    else
        return dx1 * dy2 - dy1 * dx2 > 0;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> points(n);
    vector<int> is_hull(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
        points[i].idx = i;
    }

    vector<Point> hull = convex_hull(points);
    int hull_size = hull.size();
    for (const auto& p : hull) {
        is_hull[p.idx] = 1;
    }

    int total = 1;  // The convex hull itself
    for (int i = 0; i < n; ++i) {
        if (is_hull[points[i].idx]) continue;
        Point c = points[i];
        vector<pair<Point, int>> vec;
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            vec.push_back({points[j], points[j].idx});
        }

        sort(vec.begin(), vec.end(), [&](const pair<Point, int>& a, const pair<Point, int>& b) {
            return cmp(a.first, b.first, c);
        });

        vector<int> pos(n, -1);
        for (int j = 0; j < vec.size(); ++j) {
            pos[vec[j].second] = j;
        }

        vector<int> hull_pos;
        for (const auto& p : hull) {
            hull_pos.push_back(pos[p.idx]);
        }
        sort(hull_pos.begin(), hull_pos.end());

        int cnt = 0;
        for (int j = 0; j < hull_pos.size(); ++j) {
            int curr = hull_pos[j];
            int next = hull_pos[(j + 1) % hull_pos.size()];
            int diff = (next - curr + vec.size()) % vec.size();
            if (diff == 1 || diff == 0) {
                cnt++;
            }
        }
        total += cnt;
    }

    cout << total << '\n';
}

int main() {
    solve();
    return 0;
}
