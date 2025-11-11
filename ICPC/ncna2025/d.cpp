#include <bits/stdc++.h>
using namespace std;

int a[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        a[x + 1]++;
        a[y + 1]--;
    }

    int ans = 0;
    for (int i = 1; i < 25; i++) {
        a[i] += a[i - 1];
    }

    for (int i = 1; i <= 24; i++) {
        if (a[i] >= k) {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}