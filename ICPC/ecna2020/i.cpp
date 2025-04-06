#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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

const int N = (int)2e6 + 1, M = N * 2;

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
        return a + v * dot(v, p - a) / dot(v, v);
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

    friend bool operator<(const Point& a, const Point& b) {
        return (a.x < b.x) || (a.x == b.x && a.y < b.y);
    }

    friend std::ostream &operator<<(ostream &os, Point p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

int h[N], e[M], ne[M], idx = 0;

void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<Point<ld>, Point<ld>>> a;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a.pb({Point<ld>(x1, y1), Point<ld>(x2, y2)});
    }

    ld x, y, v;
    cin >> x >> y >> v;

    ld dx1, dy1, dx2, dy2, vf;
    cin >> dx1 >> dy1 >> dx2 >> dy2 >> vf;
    
    a.pb({Point<ld>(dx1, dy1), Point<ld>(dx2, dy2)});

    vector<Point<ld>> b[a.size()];
    vector<Point<ld>> vec;
    Point<ld> p;

    map<Point<ld>, int> mp;
    map<int, Point<ld>> rv;
    int id = 0;

    auto join = [&](Point<ld> point){
        if(!mp.count(point)){
            rv[id] = point;
            mp[point] = id++;
        }
    };

    for(int i = 0; i < n; i++){
        auto p1 = a[i].first, p2 = a[i].second;
        if(Point<ld>(x, y).on_segment(p1, p2, Point<ld>(x, y))){
            b[i].pb(Point<ld>(x, y));
            join(Point<ld>(x, y));
        }
    }

    for(int i = 0; i < a.size(); i++){
        auto p1 = a[i].first, p2 = a[i].second;
        b[i].pb(p1), b[i].pb(p2);
        join(p1), join(p2);

        for(int j = i + 1; j < a.size(); j++){
            auto q1 = a[j].first, q2 = a[j].second;
            join(q1), join(q2);
            auto pt = p.intersect(p1, p2 - p1, q1, q2 - q1);
              
            if(p.seg_intersection(p1, p2, q1, q2)){
                // cout << pt << endl;
                join(pt);

                b[i].pb(pt);
                b[j].pb(pt);

                if(j == a.size() - 1){
                    vec.pb(pt);
                }
            }
        }
    }

    for(int i = 0; i <= 2 * id; i++){
        h[i] = -1;
    }
    idx = 0;

    Point<ld> p1, p2;
    auto cmp = [&](const Point<ld>& a, const Point<ld>& b) -> bool {
        ld t1 = ((a.x - p1.x) * (p2.x - p1.x) + (a.y - p1.y) * (p2.y - p1.y));
        ld t2 = ((b.x - p1.x) * (p2.x - p1.x) + (b.y - p1.y) * (p2.y - p1.y));
        return t1 < t2;
    };

   for(int i = 0; i < n; i++){
        p1 = a[i].first, p2 = a[i].second;
        sort(b[i].begin(), b[i].end(), cmp);
        for (int j = 1; j < b[i].size(); j++){
            add(mp[b[i][j - 1]], mp[b[i][j]]);
            add(mp[b[i][j]], mp[b[i][j - 1]]);
        }
    }

    priority_queue<pair<ld, int>, vector<pair<ld, int>>, greater<>> q;
    q.push({0, mp[Point<ld>(x, y)]});

    vector<ld> dp(id + 1, INF);
    vector<int> vs(id + 1);
    dp[mp[Point<ld>(x, y)]] = 0;
 
    while(!q.empty()){
        auto pair = q.top();
        q.pop();

        int u = pair.second;
        auto p1 = rv[u];
        if(vs[u]){
            continue;
        }
        vs[u] = 1;

        for(int i = h[u]; i != -1; i = ne[i]){
            int j = e[i];
            auto p2 = rv[j];
            if(dp[j] > dp[u] + p.point_dist(p1, p2)){
                dp[j] = dp[u] + p.point_dist(p1, p2);
                q.push({dp[j], j});
            }
        }
    }
 
    ld qwq = INF;
    for(auto P : vec){
        int u = mp[P];
        ld df = p.point_dist(Point<ld>(dx1, dy1), P);
        ld ds = dp[u];
      
        if(df * v >= ds * vf){
            qwq = chmin(qwq, chmax(df / vf, ds / v));
        }
    }

    if(qwq == INF){
        cout << -1 << endl;
    }
    else{
        cout << setprecision(20) << qwq << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
