#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int n, m, zero, one, two;
int a[75 * 75];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n * m; ++i){
            cin >> a[i];
            if (a[i] == 0) ++zero;
            if (a[i] == 1) ++one;
            if (a[i] == 2) ++two;
        }

    if (zero >= 2) {
        cout << "0\n";
        return 0;
    }

    if (zero == 1) {
        if (a[0] == 1 || a[n * m - 1] == 1 || min(n, m) > 1) cout << "1\n";
        else cout << "2\n";
        return 0;
    }

    if (two % 2 == 1) {
        int k = two / 2;
        cout << (1ull << k) << '\n';
    } else {
        cout << "0\n";
    }
    return 0;
}