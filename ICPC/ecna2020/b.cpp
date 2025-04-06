#include <bits/stdc++.h>
using namespace std;

const
int N = 110;

int ans;
string target;

int n, m, tot = 0;
char a[N][N];
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int isvalid(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

bool f[20][20][N][10][N];
int vis[20][20][N][10][N];
bool search(int x, int y, int cur, int direction, int tot_kinks) {
    // cout << last_nx << ' ' << last_ny << endl;
    if (direction == -1) {
        if (cur == target.length()) {
            if (tot_kinks == ans) return true;
            return false;
        }
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!isvalid(nx, ny) || a[nx][ny] != target[cur]) continue;
            if (search(nx, ny, cur + 1, i, 0)) {
                return true;
            }
        }
        return false;
    }

    if (vis[x][y][cur][direction][tot_kinks]) {
        return f[x][y][cur][direction][tot_kinks];
    }
    if (cur == target.length()) {
        // cout << "search found: " << tot_kinks << '\n';
        if (tot_kinks == ans) return true;
        return false;
    }
    if (tot_kinks > ans) return false;

    vis[x][y][cur][direction][tot_kinks] = 1;

    int nx = x + dx[direction], ny = y + dy[direction];
    if (isvalid(nx, ny) && target[cur] == a[nx][ny]) {
        if (search(nx, ny, cur + 1, direction, tot_kinks)) {
            f[x][y][cur][direction][tot_kinks] = true;
            return true;
        }
    }
    for (int i = 0; i < 8; ++i) {
        if (direction == i) continue;
        int nx2 = x + dx[i], ny2 = y + dy[i];
        if (!isvalid(nx2, ny2)) continue;
        if (a[nx2][ny2] != target[cur]) continue;
        if (search(nx2, ny2, cur + 1, i, tot_kinks + 1)) {
            f[x][y][cur][direction][tot_kinks] = true;
            return true;
        }
    }

    f[x][y][cur][direction][tot_kinks] = false;
    return false;
}

int main() {
    freopen("b.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            static string tmp;
            cin >> tmp;
            a[i][j] = tmp[0];
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cin >> ans >> target;
    // cout << "ans: " << ans << ", target: " << target << '\n';

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == target[0]) {
                if (search(i, j, 1, -1, 0)) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}
