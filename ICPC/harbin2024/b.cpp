#include <bits/stdc++.h>
using namespace std;

#define ld long long

const int N = 1e5 + 10;

struct Point{
    ld x, y;
    Point() {
        x = 0, y = 0;
    }
    Point(ld x, ld y) {
        this->x = x;
        this->y = y;
    }
    bool operator == (const Point& p) const {
        return x == p.x && y == p.y;
    }
    Point operator - (const Point& p) const {
        return {x - p.x, y - p.y};
    }
    ld operator * (const Point& p) const {
        return x * p.y - y * p.x;
    }
    bool operator < (const Point& p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
}p[N], p_[N], convex1[N], convex2[N];

int n, tp1, tp2;
int siz;

map<Point, int> existed;

int get_next(int i, int size) {
    if (i != size) return i + 1;
    return 1;
}

ld cross(Point a, Point b, Point c){
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool cmp(Point a, Point b){
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}

inline ld get_area() {
    ld res = 0;
    for (int i = 1; i <= tp1; ++i) {
        res += convex1[i] * convex1[get_next(i, tp1)];
    }
    return abs(res);
}

void convex_hull(Point points[], int size, Point stk[], int& tp){
    sort(points, points + size, cmp);
    if (size == 0) {
        tp = 0;
        return;
    }
    if (size <= 2) {
        for (int i = 1; i <= size; ++i) {
            stk[i] = points[i - 1];
        }
        stk[size + 1] = points[0];
        tp = size + 1;
        return;
    }
    tp = 0;

    for(int i = 0; i < size; i++){
        while(tp > 1 && cross(stk[tp - 1], stk[tp], points[i]) <= 0){
            tp--;
        }
        stk[++tp] = points[i];
    }

    int lim = tp;
    for(int i = size - 2; i >= 0; i--){
        while(tp > lim && cross(stk[tp - 1], stk[tp], points[i]) <= 0){
            tp--;
        }
        stk[++tp] = points[i];
    }
}

inline void solve() {
    tp1 = 0;
    tp2 = 0;
    siz = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    convex_hull(p, n, convex1, tp1);
//    cout << tp1 << '\n';
    --tp1;

    for (int i = 1; i <= tp1; ++i) {
        existed[convex1[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (!existed[p[i]]) {
            p_[siz++] = p[i];
        }
    }

    convex_hull(p_, siz, convex2, tp2);
//    --tp2;

//    cout << "tp2: " << tp2 << '\n';

    if (tp2 == 0) {
        cout << "-1\n";
        return;
    }
    --tp2;

    int cur = 1;
    ld dis = LLONG_MAX;

    for (int i = 1; i <= tp1; ++i) {
//        cout << "i-th loop: \n";
        while (1) {
            ld l = (convex1[get_next(i, tp1)] - convex1[i]) * (convex2[cur] - convex1[i]);
            ld r = (convex1[get_next(i, tp1)] - convex1[i]) * (convex2[get_next(cur, tp2)] - convex1[i]);

            dis = min({dis, abs(l), abs(r)});

//            cout << dis << '\n';

            if (r >= l) break;
            cur = get_next(cur, tp2);
        }
        dis = min(dis, abs((convex1[i] - convex2[cur]) * (convex1[get_next(i, tp1)] - convex2[cur])));
    }

    cout << get_area() - dis << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}