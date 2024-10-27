#include <bits/stdc++.h>
using namespace std;

const int N = 110, M = N * N;

#define int long long

int n, m, s, t;
int f[N][N];
int u[M], v[M], wt[M];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> s >> t;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j] = INT_MAX;
        }
        f[i][i] = 0;
    }

//    cout << "f: \n";
//
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            cout << f[i][j] << ' ';
//        }
//        cout << '\n';
//    }


    for (int i = 1; i <= m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        u[i] = x, v[i] = y, wt[i] = z;
        f[x][y] = f[y][x] = z;
    }

//    cout << "f: \n";
//
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            cout << f[i][j] << ' ';
//        }
//        cout << '\n';
//    }

    // floyd shortest path
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (f[i][k] != INT_MAX && f[k][j] != INT_MAX) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
    }

//    cout << "f: \n";
//
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            cout << f[i][j] << ' ';
//        }
//        cout << '\n';
//    }

    int ans = 0;
    for (int i = 1; i <= m; ++i) {
//        cout << "Now is at edge " << i << " with weight " << wt[i] << '\n';
//        cout << "u: " << u[i] << ", v: " << v[i] << '\n';
//        cout << "positive: " << f[s][u[i]] << ", " << f[v[i]][t] << '\n';
//        cout << "negative: " << f[s][v[i]] << ", " << f[u[i]][t] << '\n';
        if (min(f[s][u[i]] + wt[i] +  f[v[i]][t], f[s][v[i]] + wt[i] + f[u[i]][t]) != f[s][t]) {
//            cout << "i: " << i << '\n';
            ans += wt[i];
        }
    }



    cout << ans << '\n';
    return 0;
}
