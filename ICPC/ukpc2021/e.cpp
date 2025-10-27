#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

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

const int N = (int)1e6 + 1, M = N * 2;

void solve() {
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    s1 = '#' + s1;
    s2 = '#' + s2;

    auto DP = [&](int l, int r) -> string {

    };

    string ans = "";
    for (int i = 0; i < n; i += 10) {
        int len = (i + 10 < n ? 9 : n - i - 1);
        ans += DP(i, i + len);
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
