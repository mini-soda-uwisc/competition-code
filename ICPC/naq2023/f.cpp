#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;
const double MAXN = 1e4 + 0.1;

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
    string str;
    cin >> str;
    int n = (int)str.size();
    unordered_map<char, int> mp;
    for (char c : str) {
        mp[c]++;
    }

    int cnt1 = 0;
    int cnt2 = 0;
    for (auto [c, f] : mp) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            cnt1 += f;
            cnt2 += f;
        } else if (c == 'y') {
            cnt2 += f;
        }
    }

    cout << cnt1 << ' ' << cnt2 << '\n';
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    double ans = MAXN;

    while (t--) {
        solve();
    }

    return 0;
}
