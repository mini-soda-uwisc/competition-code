#include <bits/stdc++.h>
using namespace std;

int n, m, p;
string a[110];
string s;

inline int valid(int x,int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// int vis[110][110][110];
// int bfs(int sx, int sy) {
//     queue<tuple<int, int, int>> q;
//     memset(vis, 0, sizeof(vis));
//     vis[sx][sy][0] = 1;
//     q.emplace(sx,sy, 0);
//     while (!q.empty()) {
//         auto [x, y, step] = q.front();
//         // printf("Searching (%d, %d) %c, step = %d\n", x, y, a[x][y], step);
//         if (step == s.length() - 1) return 1;
//         q.pop();
//         for (int i = 0; i < 8; ++i) {
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if (!valid(nx, ny)) continue;
//             if (vis[nx][ny][step + 1]) continue;
//             if (a[nx][ny] == s[step + 1]) {
//                 if (step + 1 == s.length() - 1) {
//                     return 1;
//                 }
//                 vis[nx][ny][step + 1] = 1;
//                 q.emplace(nx, ny, step + 1);
//             }
//         }
//     }
//     return 0;
// }

int vis[110][110];
int dfs(int x, int y, int step) {
    if (step == s.length() - 1) {
        return 1;
    }
    if (vis[x][y]) return 0;
    vis[x][y] = 1;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!valid(nx, ny)) continue;
        if (vis[nx][ny]) continue;
        if (s[step + 1] != a[nx][ny]) continue;
        if (dfs(nx, ny, step + 1)) {
            return 1;
        }
    }
    vis[x][y] = 0;
    return 0;
}

void solve(int case_id) {
    memset(vis, 0, sizeof(vis));
    int ok = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == s[0]) {
                if (dfs(i, j, 0)) {
                    ok = 1;
                    goto END;
                }
            }
        }
    }
    END:
    if (ok) {
        cout << "Case " << case_id << ": Yes    " << s << '\n';
    } else {
        cout << "Case " << case_id << ": No    " << s << '\n';
    }
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);

    cin >> n >> m;
    getchar();
    for (int i = 1; i <= n; ++i) {
        getline(cin, a[i]);
        a[i] = " " + a[i];
    }

    // for (int i = 1; i <= n; ++i) {
    //     cout << a[i] << '\n';
    // }

    cin >> p;
    getchar();
    // cout << p << '\n';
    for (int i = 1; i <= p; ++i) {
        getline(cin, s);
        // cout << "s: " << s << '\n';
        solve(i);
    }
    return 0;
}