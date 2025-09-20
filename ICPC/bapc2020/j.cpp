#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c, e, m;
    cin >> c >> e >> m;
    if (c != 4) {
        cout << "impossible\n";
        return 0;
    }

    if (e % 2 != 0) {
        cout << "impossible\n";
    }

    e /= 2;

    int l = 0, r = e / 2;
    while (l < r) {
        int mid = (l + r) / 2;
        int sq = mid * (e - mid);
        if (sq >= m) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (l * (e - l) != m) {
        cout << "impossible\n";
        return 0;
    }
    cout << l + 2 << ' ' << e - l + 2 << '\n';
    return 0;
}