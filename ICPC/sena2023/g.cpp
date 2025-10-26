#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1 << 22;
int f[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    const int s = (1 << m) - 1;

    for (int i = 1; i <= n; ++i) {
        string str;
        cin >> str;
        int k = 0;
        for (int j = 0; j < m; ++j) {
            k <<= 1;
            k += str[j] - '0' + 0;
        }
        ++f[s ^ k];
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= s; ++j) {
            if ((j & (1 << i)) == 0) {
                f[j] += f[j ^ (1 << i)];
            }
        }
    }

    int ans = m;
    for (int i = 1; i <= s; ++i) {
        f[i] = n - f[i];
        int k = __builtin_popcount(i);
        if (f[i] < k) ans = min(ans, k - 1);
    }

    cout << ans << '\n';
    return 0;
}