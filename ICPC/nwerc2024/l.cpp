#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

#define int long long

int n, m, x, y;
int a[N], b[N];
int available[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    if (a[n] < b[m]) {
        cout << "impossible\n";
        return 0;
    }

    fill(available + 1, available + n + 1, y);

    int remain = -1;

    int p = 1;
    for (int i = 1; i <= m; ++i) {
        if (a[p] < b[i] || available[p] == 0) {
            while (p <= n && (a[p] < b[i] || available[p] == 0)) ++p;

            if (p > n) {
                if(a[p - 1] < b[i]){
                    cout << "impossible" << '\n';
                    return 0;
                }
                remain = i;
                break;
            }
        }
        --available[p];
    }

    if (remain == -1) {
        cout << n << '\n';
        return 0;
    }

    fill(available + 1, available + n + 1, x - y);
    p = n;
    for (int i = m; i >= remain; --i) {
//        if(a[p] < b[i]){
//            cout << "impossible" << '\n';
//            return 0;
//        }
        if (p == 1 && (available[p] == 0 || a[p] < b[i])) {
            cout << "impossible\n";
            return 0;
        }

        if (available[p] == 0) {
            while (p >= 1 && available[p] == 0) --p;
            if (p == 0) {
                cout << "impossible\n";
                return 0;
            }
        }

        --available[p];
    }

    cout << p - 1 << '\n';
    return 0;
}