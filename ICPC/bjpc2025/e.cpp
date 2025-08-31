#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template <typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }

    ld a, b, c;
    cin >> a >> b >> c;

    auto f = [&](ld t) -> ld {
        ld x, y;
        if (a == 0){
            x = t;
            y = -c / b;
        }
        else if (b == 0) {
            x = -c / a;
            y = t;
        }
        else {
            x = t;
            y = (a * x + c) / -b;
        }

        ld res = 0;
        for (int i = 0; i < n; i++) {
            ld dx = p[i].first, dy = p[i].second;
            res = chmax(res, sqrt((x - dx) * (x - dx) + (y - dy) * (y - dy)));
        }

        return res;
    };

    ld l = -INF, r = INF, eps = 1e-12;
    while(l + eps < r){
        ld mid = (r - l) / 3.0;
        ld m1 = l + mid;
        ld m2 = m1 + mid;
        if(f(m1) <= f(m2)){
            r = m2;
        }
        else{
            l = m1;
        }
    }

    cout << setprecision(20) << chmin(f(l), f(r)) << "\n";
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
