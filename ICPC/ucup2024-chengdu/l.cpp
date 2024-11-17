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

int __lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

void solve() {
    int p50, p95, p99;
    cin >> p50 >> p95 >> p99;
    cout << 100 << endl;
    for (int i = 0; i < 50; ++i) {
        cout << p50 << " ";
    }
    for (int i = 0; i < 45; ++i) {
        cout << p95 << " ";
    }
    for (int i = 0; i < 4; ++i) {
        cout << p99 << " ";
    }
    cout << p99 + 1 << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}