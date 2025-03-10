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

void solve(string s) {
    int n = (int) s.size();

    ll a = 0;
    int sign = 1;
    for (int i = n; i >= 0; i -= 3) {
        int x = 0;
        for (int j = max(0, i - 3); j < i; ++j) {
            x = x * 10 + (s[j] - '0');
        }
        a += x * sign;
        sign *= -1;
    }

    a = abs(a);
    cout << a << " ";
    if (a % 13 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

void solve() {
    string s;
    cin >> s;
    solve(s);
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