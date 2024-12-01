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
    int n;
    cin >> n;
    if (n == 1) {
        cout << "impossible\n";
        return;
    }
    if (n == 2) {
        cout << "1 0\n";
        return;
    }
    if (n == 3) {
        cout << "1 0 2\n";
        return;
    }

    if (n % 4 == 0) {
        cout << "impossible\n";
        return;
    }

    cout << "1 0 2 ";
    for (int i = 4; i < n; i += 2) {
        if (i % 4 == 0) {
            cout << i << ' ' << i - 1 << ' ';
        } else {
            cout << i - 1 << ' ' << i << ' ';
        }
    }

    if (n % 2 == 0) cout << n - 1;
    cout << '\n';
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

//    main();
    return 0;
}