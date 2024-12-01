#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(int a, int b) {
    int i = b;
    while (i >= 2) {
        if (a % i == 0) {
            return a / i;
        }

        i = i - 1;
    }

    return a;
}

inline void solve() {
    int n;
    cin >> n;

    vector<int> fractors;
    int sqr = sqrt(n);
    for (int i = 1; i <= sqr; ++i) {
        if (n % i == 0) {
            fractors.emplace_back(i);
            fractors.emplace_back(n / i);
        }
    }

    if (sqr * sqr == n) {
        fractors.erase(find(fractors.begin(), fractors.end(), sqr));
    }

    sort(fractors.begin(), fractors.end());

    int ans = 0;
    for (int i = 0; i < fractors.size() - 1; ++i) {
        int length = fractors[i + 1] - fractors[i];
//        cout << fractors[i] << ' ' << length << '\n';
        ans += (n / fractors[i]) * length;
    }

    ans += 1ll;
    cout << ans << '\n';

//    ans = 0;
//    for (int i = 1; i <= n; ++i) {
//        cout << i << ": " << f(n, i) << '\n';
//        ans += f(n, i);
//    }
//    cout << ans << '\n';
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