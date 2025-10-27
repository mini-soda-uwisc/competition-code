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

const int N = (int)1e3 + 1, M = N * 2;
int h[N], e[M], ne[M], s[N], p[N], idx;
int dp[N][N][2];

void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void solve() {
    int n, c;
    cin >> n >> c;

    for (int i = 1; i <= n; i++) {
        h[i] = -1;
    }
    idx = 0;

    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> p[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    auto dfs = [&](auto& self, int u, int fa) -> void {
        if (s[u] <= c) {
            dp[u][s[u]][1] = p[u];
        }
        // dp[u][0][0] = 0;

        int ndp[c + 1][2];
        memset(ndp, 0, sizeof ndp);

        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (j == fa) {
              continue;
            }
            self(self, j, u);

            for (int k = 0; k <= c; k++) {
                ndp[k][0] = dp[u][k][0], ndp[k][1] = dp[u][k][1];
                dp[u][k][0] = dp[u][k][1] = 0;
            }

            for (int k = 0; k <= c; k++) {
                for (int l = 0; l + k <= c; l++) {
                    for (int p = 0; p <= 1; p++) {
                        for (int q = 0; q <= 1; q++) {
                            if (p == 1 && q == 1) {
                                continue;
                            }
                            dp[u][l + k][p] = chmax(dp[u][l + k][p], dp[j][l][q] + ndp[k][p]);
                        }
                    }
                }
            }
        }
    };

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 1; j++) {
            dp[i][j][0] = dp[i][j][1] = 0;
        }
    }

    dfs(dfs, 1, 1);

    int qwq = 0;
    for (int i = 0; i <= c; i++) {
        qwq = chmax(qwq, chmax(dp[1][i][0], dp[1][i][1]));
    }
    cout << qwq << endl;
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
