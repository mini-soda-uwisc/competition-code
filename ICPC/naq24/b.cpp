#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;
const double MAXN = 1e4 + 0.1;

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int) 1e5 + 1, M = N * 2;

double solve(pair<double, double> point1, pair<double, double> point2) {
    double x1 = point1.first;
    double y1 = point1.second;
    double x2 = point2.first;
    double y2 = point2.second;

    if ((x1 < 0 && x2 > 0) || (x1 > 0 && x2 < 0)) {
        double t = -x1 / (x2 - x1);
        double y_intercept = y1 + t * (y2 - y1);
        return y_intercept > 0 ? y_intercept : -1.0;
    }

    return -1.0;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;

    double ans = MAXN;

    while (t--) {
        pair<double, double> point1, point2;
        cin >> point1.first >> point1.second >> point2.first >> point2.second;
        double temp = solve(point1, point2);
        if (temp > 0) {
            ans = min(ans, temp);
        }
    }

    ans = ans == MAXN ? -1.0 : ans;

    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}