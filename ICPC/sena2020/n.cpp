#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, ans = 0;
int a[100];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    for (int l = 1; l <= n; ++l) {
        for (int r = l + 1; r <= n; ++r) {
            int x = a[l], y = a[r];
            int idx = r + 1;
            while (idx <= n && x + y > a[idx]) ++idx;
            --idx;

            if (idx <= r) continue;
            ans += 1ll << (idx - r);
            --ans;
        }
    }
    cout << ans << '\n';
    return 0;
}