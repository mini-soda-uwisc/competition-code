#include <bits/stdc++.h>
using namespace std;

const int N = 25;

#define int long long

string s;
int f[N][N];
int n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    n = s.length();
    s = " " + s;

    for (int i = 1; i <= n + 1; ++i) f[i][i - 1] = 1;

    for (int l = n; l >= 1; --l) {
        for (int r = l; r <= n; ++r) {
            if ((r - l + 1) % 2) continue;
            const char bracks[] = "(){}[]<>";

            for (int i = 0; i < 8; i += 2) {
                if (s[l] != bracks[i] && s[l] != '?') continue;

                for (int j = l; j <= r; ++j) {
                    if (s[j] != bracks[i + 1] && s[j] != '?') continue;
                    f[l][r] += f[l + 1][j - 1] * f[j + 1][r];
                }
            }
        }
    }

    cout << f[1][n] << '\n';
    return 0;
}