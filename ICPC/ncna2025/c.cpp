#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int a[n][m];
    int dp[2][n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    if (n == 1 && m == 1) {
        cout << "0\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[0][i][j] = dp[1][i][j] = (int)1e9;
        }
    }
    dp[0][0][0] = a[0][0];

    for (int i = 1; i <= n * m; i++) {
        int id = i % 2, last = id ^ 1;
        for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < m; jj++) {
                dp[id][ii][jj] = (int)1e9;
            }
        }

        for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < m; jj++) {
                if (ii) {
                    dp[id][ii][jj] = min(dp[id][ii][jj], dp[last][ii - 1][jj] + a[ii][jj]);
                }
                if (jj) {
                    dp[id][ii][jj] = min(dp[id][ii][jj], dp[last][ii][jj - 1] + a[ii][jj]);
                }
                if (ii + 1 < n) {
                    dp[id][ii][jj] = min(dp[id][ii][jj], dp[last][ii + 1][jj] + a[ii][jj]);
                }
                if (jj + 1 < m) {
                    dp[id][ii][jj] = min(dp[id][ii][jj], dp[last][ii][jj + 1] + a[ii][jj]);
                }
            }
        }

        if (dp[id][n - 1][m - 1] <= k) {
            cout << i << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}