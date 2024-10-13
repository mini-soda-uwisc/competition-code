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

const int N = (int) 1e5 + 1, M = N * 2;

void solve() {

}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ld x1, y1, x2, y2, a;

    cin >> x1 >> y1 >> x2 >> y2 >> a;

    a /= 2.0;

    ld a2 = a * a;

    ld cx = (x1 + x2) / 2.0;
    ld cy = (y1 + y2) / 2.0;

    ld c = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 2.0;
    ld c2 = c * c;

    ld b = sqrt(a2 - c2);
    ld b2 = b * b;

    ld theta = atan2(y2 - y1, x2 - x1);

    ld a2Cos2Theta = a2 * cos(theta) * cos(theta);
    ld b2Sin2Theta = b2 * sin(theta) * sin(theta);
    ld a2Sin2Theta = a2 * sin(theta) * sin(theta);
    ld b2Cos2Theta = b2 * cos(theta) * cos(theta);

    ld minX = cx - sqrt(a2Cos2Theta + b2Sin2Theta);
    ld maxX = cx + sqrt(a2Cos2Theta + b2Sin2Theta);
    ld minY = cy - sqrt(a2Sin2Theta + b2Cos2Theta);
    ld maxY = cy + sqrt(a2Sin2Theta + b2Cos2Theta);

    cout << fixed << setprecision(20) << minX << " " << minY << " " << maxX << " " << maxY << endl;
    return 0;
}