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
    int n, min1, max1;
    cin >> n >> min1 >> max1;
    vector<int> a(n - 1);
    unordered_map<int, int> mp;
    int min2 = MAXN, max2 = -1;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
        min2 = min(min2, a[i]);
        max2 = max(max2, a[i]);
        mp[a[i]]++;
    }

    if (max1 < max2 || min1 > min2 || !mp.count(min1) && !mp.count(max1)) {
        cout << "-1\n";
        return;
    }

    if (!mp.count(min1) || !mp.count(max1)) {
        if (!mp.count(min1)) {
            cout << min1 << '\n';
        }
        if (!mp.count(max1)) {
            cout << max1 << '\n';
        }
        return;
    }
    for (int i = min1; i <= max1; i++) {
        cout << i << '\n';
    }
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
