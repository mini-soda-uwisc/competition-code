#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

#define int long long

int n;
int f[N];

signed main() {
    cin >> n;
    fill(f, f + N, 1e18);
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i / 2; ++j) {
            f[i] = min(f[i], f[j] + f[i - j]);
        }

        for (int j = 1; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                f[i] = min(f[i], f[j] + f[i / j]);
            }
        }

        string s = to_string(i);
        for (int j = 1; j < s.size(); ++j) {
            string t1 = s.substr(0, j);
            string t2 = s.substr(j);
            if (t1[0] == '0' || t2[0] == '0') {
                continue;
            }
            f[i] = min(f[i], f[stoi(t1)] + f[stoi(t2)]);
        }
    }

    cout << f[n] << '\n';
    return 0;
}