#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

void solve() {
    int n, m, t;
    cin >> n >> m >> t;

    int a[n][m], b[n][m];
    memset(b, 0, sizeof b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n && i && j + 1 < m && j) {
                if (a[i + 1][j] == -1 || a[i - 1][j] == -1 || a[i][j - 1] == -1 || a[i][j + 1] == -1) {
                    continue;
                }
                if (chmax(a[i][j - 1], a[i][j + 1]) < a[i][j]) {
                    if (chmin(a[i + 1][j], a[i - 1][j]) > a[i][j]) {
                        b[i][j] = 1;
                    }
                }
            }
        }
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
    int dp[n][m][t + 1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k <= t; k++) {
                dp[i][j][k] = 1e9;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i][0] != -1) {
            if (b[i][0] > t) {
                continue;
            }
            q.push({a[i][0], i, 0, b[i][0]});
            dp[i][0][b[i][0]] = a[i][0];
        }
    }

    while (!q.empty()) {
        auto p = q.top();
        q.pop();

        int dirx[3] = {0, 1, -1}, diry[3] = {1, 1, 1};
        int x = p[1], y = p[2], c = p[3];

        for (int i = 0; i < 3; i++) {
            int dx = p[1] + dirx[i], dy = p[2] + diry[i];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m || a[dx][dy] == -1 || c + b[dx][dy] > t) {
                continue;
            }

            int dt = c + b[dx][dy];
            if (dp[dx][dy][dt] > dp[x][y][c] + a[dx][dy]) {
                dp[dx][dy][dt] = dp[x][y][c] + a[dx][dy];
                q.push({dp[dx][dy][dt], dx, dy, dt});
            }
        }
    }

    int qwq = (int)1e9;
    for (int i = 0; i < n; i++) {
        qwq = chmin(qwq, dp[i][m - 1][t]);
    }

    if (qwq == 1e9) {
        cout << "impossible" << endl;
    }
    else {
        cout << qwq << endl;
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

    while(t--){
        solve();
    }

    return 0;
}
