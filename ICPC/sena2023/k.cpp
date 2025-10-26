#include <bits/stdc++.h>
using namespace std;

#define int long long

inline void solve() {
    int x, k, a, b;
    cin >> x >> k >> a >> b;
    int ans = 0;
    while (1) {
        ++ans;
        int y = (b - a) * x / a;
        if (y >= k) break;
        k -= y;
        x += y;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}