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

const int N = (int)2e6 + 1, M = N * 2;

string a[N];
int dp[N], b[N], c[N], d[N];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < 1 << m; i++) {
        dp[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'Y') {
                c[i] |= 1 << j;
            }
            else {
                b[i] |= 1 << j;
            }
        }
        dp[c[i]] = __popcount(c[i]);
        d[i] = __popcount(c[i]);
    }

    for (int i = 0; i < n; i++) {
        if (dp[c[i]] == m) {
            int max = -1, id = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (m + dp[c[j]] > max) {
                    max = m + dp[c[j]];
                    id = j;
                }
            }
            cout << chmin(i + 1, id + 1) << " " << chmax(i + 1, id + 1) << "\n";
            return;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = (1 << m) - 1; j >= 0; j--) {
            if (j >> i & 1) {
                dp[j ^ (1 << i)] = chmax(dp[j ^ (1 << i)], dp[j]);
            }
        }
    }

    int max = -1, day = -1;
    for (int i = 0; i < n; i++) {
        int mask = b[i];
        if (dp[mask] != -1) {
            if (max < dp[mask] + d[i]) {
                max = dp[mask] + d[i];
                day = i;
            }
        }
    }

    if (day == -1) {
        cout << "No\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i != day && __popcount(c[i] | c[day]) == m && d[i] + d[day] == max) {
            cout << chmin(i + 1, day + 1) << " " << chmax(i + 1, day + 1) << "\n";
            return;
        }
    }
    cout << "No\n";
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
