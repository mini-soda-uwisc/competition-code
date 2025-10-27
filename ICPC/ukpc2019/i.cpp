#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template <typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

void solve() {
    int n, m;
    cin >> n >> m;

    if (m < (1 << (n - 1))) {
        cout << "impossible\n";
    }
    else {
        int c[21][21];
        memset(c, 0, sizeof c);

        for (int i = 1; i <= n; i++) {
            c[n][i] = 1;
        }
        c[n][1] = m - (1 << (n - 1)) + 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= i; j++) {
                c[i][j] = c[i + 1][j] + c[i + 1][j + 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cout << c[i][j] << " \n"[j == i];
            }
        }
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
