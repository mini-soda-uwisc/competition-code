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

template<typename T>
struct Point{
    T x, y;
    ld eps;

    Point() : x(0), y(0), eps(1e-9) {}
    Point(T x, T y) : x(x), y(y), eps(1e-9) {}

    void set_eps(T eps){
        this->eps = eps;
    }

    Point operator+ (const Point& b){
        return Point(x + b.x, y + b.y);
    }

    Point operator- (const Point& b){
        return Point(x - b.x, y - b.y);
    }

    Point operator- (){
        return Point(-x, -y);
    }

    Point operator* (T t) const{
        return Point(x * t, y * t);
    }

    Point operator/ (T t) const{
        return Point(x / t, y / t);
    }

    Point &operator+=(Point p) &{
        x += p.x;
        y += p.y;
        return *this;
    }

    Point &operator-=(Point p) &{
        x -= p.x;
        y -= p.y;
        return *this;
    }

    Point &operator*=(T v) &{
        x *= v;
        y *= v;
        return *this;
    }

    Point &operator/=(T v) &{
        x /= v;
        y /= v;
        return *this;
    }

    Point &operator=(const Point& b) &{
        x = b.x;
        y = b.y;
        return *this;
    }

    friend Point operator+ (const Point& a, const Point& b){
        return {a.x + b.x, a.y + b.y};
    }

    friend Point operator- (const Point& a, const Point& b){
        return {a.x - b.x, a.y - b.y};
    }

    friend bool operator==(Point a, Point b){
        return a.x == b.x && a.y == b.y;
    }

    int sign(T x){
        if(fabs(x) < eps){
            return 0;
        }
        if(x < 0){
            return -1;
        }
        return 1;
    }

    bool cmp(T x, T y){
        if(fabs(x - y) > eps){
            return 0;
        }
        return 1;
    }

    bool cmp(const Point& a, const Point& b){
        return cmp(a.x, b.x) && cmp(a.y, b.y);
    }

    T dot(const Point& a, const Point& b){
        return a.x * b.x + a.y * b.y;
    }

    T square(Point a){
        return dot(a, a);
    }

    T cross(const Point& a, const Point& b){
        return a.x * b.y - a.y * b.x;
    }

    T cross(const Point& a, const Point& b, const Point& p){
        return (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
    }

    T get_len(const Point& a){
        return sqrt(dot(a, a));
    }

    T get_angle(const Point& a, const Point& b){
        return acos(dot(a, b) / get_len(a) / get_len(b));
    }

    T area(const Point& a, const Point& b, const Point& c){
        return cross(b - a, c - a);
    }

    Point rotate(const Point& a, T angle){ //两个点就 b - a (b按a转)
        T dx = a.x * cos(angle) + a.y * sin(angle);
        T dy = -a.x * sin(angle) + a.y * cos(angle);
        return Point(dx, dy);
    }

    Point intersect(const Point& p, const Point& v, const Point& q, const Point& w){
        Point u = p - q;
        T t = cross(w, u) / cross(v, w);
        return p + v * t;
    }

    T point_dist(const Point& a, const Point& b){
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    T line_dist(const Point& a, const Point& b, const Point& p){
        Point u = b - a, v = p - a;
        return fabs(cross(u, v)) / get_len(u);
    }

    T get_slope(const Point& a, const Point& b){
        if(b.y == a.y) return INF;
        if(b.x == a.x) return 0;
        return (b.y - a.y) / (b.x - a.x);
    }

    T circle_intersect(const Point& p1, const Point& p2, const T r1, const T r2){
        ld d = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
        return d >= r1 + r2;
    }

    T seg_dist(const Point& a, const Point& b, const Point& p){
        if(a == b){
            return get_len(p - a);
        }
        Point u = b - a, v = p - a, w = p - b;

        if(sign(dot(u, v)) < 0){
            return get_len(v);
        }
        if(sign(dot(u, w)) > 0){
            return get_len(w);
        }
        return line_dist(a, b, p);
    }

    Point projection(const Point& a, const Point& b, const Point& p){
        Point v = b - a;
        return a + v * dot(v, p - a) / get_len(v);
    }

    bool on_segment(const Point& a, const Point& b, const Point& p){
        bool u = sign(cross(p - a, p - b)) == 0;
        bool v = sign(dot(p - a, p - b)) <= 0;
        return u && v;
    }

    bool seg_intersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2){
        T c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1);
        T c3 = cross(b2 - b1, a2 - b1), c4 = cross(b2 - b1, a1 - b1);
        return sign(c1) * sign(c2) <= 0 && sign(c3) * sign(c4) <= 0;
    }

    friend std::ostream &operator<<(ostream &os, Point p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

struct DSU{
    vector<int> node, size;

    DSU(){}
    DSU(int n){
        init(n);
    }

    void init(int n){
        node.resize(n);
        size.resize(n);

        for(int i = 0; i < n; i++){
            node[i] = i;
            size[i] = 1;
        }
    }

    int find(int x){
        return x == node[x] ? x : node[x] = find(node[x]);
    }

    void erase(int x){
        size[find(x)] -= 1;
        node[x] = x;
    }

    void relocate(int x, int y){ //can't be root
        int dx = find(x), dy = find(y);
        if(dx == dy){
            return;
        }
        node[x] = dy;
        size[dx] -= 1;
        size[dy] += 1;
    }

    int set(int x, int y){
        return find(x) == find(y);
    }

    int merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y){
            return 0;
        }

        size[x] += size[y];
        node[y] = x;
        return 1;
    }

    int heuristic_merge(int x, int y){
        x = find(x);
        y = find(y);
        if(size[x] < size[y]){
            swap(x, y);
        }
        return merge(x, y);
    }

    int get(int x){
        return size[find(x)];
    }
};

void solve(){
    int x, y;
    cin >> x >> y;

    int n;
    cin >> n;
    vector<Point<ld>> a;

    for(int i = 0; i < n; i++){
        ld x, y;
        cin >> x >> y;
        a.pb(Point<ld>(x, y));
    }

    auto check = [&](ld t) -> int{
        DSU dsu(n + 4);
        Point<ld> st(0, 0), ed(x, y), pt;

        for(int i = 0; i < n; i++){
            if(pt.circle_intersect(st, a[i], 0, t) == 0){
                return 1;
            }
            if(pt.circle_intersect(ed, a[i], 0, t) == 0){
                return 1;
            }

            if(a[i].x - t < 0){
                dsu.heuristic_merge(i, n);
            }
            if(a[i].x + t > x){
                dsu.heuristic_merge(i, n + 1);
            }
            if(a[i].y - t < 0){
                dsu.heuristic_merge(i, n + 2);
            }
            if(a[i].y + t > y){
                dsu.heuristic_merge(i, n + 3);
            }

            for(int j = i + 1; j < n; j++){
                if(pt.circle_intersect(a[i], a[j], t, t) == 0){
                    dsu.heuristic_merge(i, j);
                }
            }
        }
        return dsu.set(n, n + 1) || dsu.set(n + 2, n + 3) || dsu.set(n, n + 2) || dsu.set(n + 1, n + 3);
    };

    ld l = 0, r = 1e12, eps = 1e-12, base = 1;
    while(r - l > chmax(base, l) * eps){
        ld mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }

    cout <<setprecision(20) << l << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//  cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
