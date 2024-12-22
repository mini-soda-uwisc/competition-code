#include <bits/stdc++.h>
using namespace std;

#define int long long

int f[1000][1000];

int n, p, m, a, b;

signed main() {
    cin >> n >> p >> m;
    a = n - p;
    b = p;
    f[0][0] = 1;
    for (int k = 1; k <= a; ++k) {
    for (int i = k; i <= a; ++i) {
        for (int j = 0; j <= 700; ++j) {

                f[i][j] = (f[i][j] + f[i - k][j ^ k]) % m;
            }
        }
    }

    cout << f[a][b] << '\n';
    return 0;
}