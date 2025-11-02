#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

struct state {
    int x, y, d;
    int operator < (const state& s) const {
        if (x != s.x) return x < s.x;
        if (y != s.y) return y < s.y;
        return d < s.d;
    }
};

int n, q;
string a[N];

// map<state, vector<state>> G;
// map<state, int> vis, f;
// queue<state> que;

vector<tuple<int, int, int>> G[N][N][4];
int vis[N][N][4], f[N][N][4];
queue<tuple<int, int, int>> que;

inline int isvalid(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

// direction
// U - 0, R - 1, D - 2, L - 3
inline pair<int, int> getfront(int x, int y, int d) {
    int nx = x, ny = y;
    if (d == 0) {
        --nx;
    } else if (d == 1) {
        ++ny;
    } else if (d == 2) {
        ++nx;
    } else if (d == 3) {
        --ny;
    } else {
        assert(false);
    }
    if (!isvalid(nx, ny)) return {-1, -1};
    return {nx, ny};
}
inline pair<int, int> getback(int x, int y, int d) {
    int nx = x, ny = y;
    if (d == 0) {
        ++nx;
    } else if (d == 1) {
        --ny;
    } else if (d == 2) {
        --nx;
    } else if (d == 3) {
        ++ny;
    } else {
        assert(false);
    }
    if (!isvalid(nx, ny)) return {-1, -1};
    return {nx, ny};
}
inline pair<int, int> getleft(int x, int y, int d) {
    int nx = x, ny = y;
    if (d == 0) {
        --ny;
    } else if (d == 1) {
        --nx;
    } else if (d == 2) {
        ++ny;
    } else if (d == 3) {
        ++nx;
    } else {
        assert(false);
    }
    if (!isvalid(nx, ny)) return {-1, -1};
    return {nx, ny};
}
inline pair<int, int> getright(int x, int y, int d) {
    int nx = x, ny = y;
    if (d == 0) {
        ++ny;
    } else if (d == 1) {
        ++nx;
    } else if (d == 2) {
        --ny;
    } else if (d == 3) {
        --nx;
    } else {
        assert(false);
    }
    if (!isvalid(nx, ny)) return {-1, -1};
    return {nx, ny};
}

inline int turnright(int d) {
    if (d == 3) return 0;
    return d + 1;
}
inline int turnleft(int d) {
    if (d == 0) return 3;
    return d - 1;
}
inline int turnback(int d) {
    if (d == 0) return 2;
    if (d == 1) return 3;
    if (d == 2) return 0;
    return 1;
}

inline int getd(char c) {
    if (c == 'U') return 0;
    if (c == 'R') return 1;
    if (c == 'D') return 2;
    return 3;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    cin >> n >> q;
    n += 2;
    for (int i = 2; i <= n - 1; ++i) {
        cin >> a[i];
        a[i] = '$' + ('@' + a[i] + '@');
    }
    for (int i = 0; i <= n; ++i) a[1].push_back('@');
    a[n] = a[1];

    // for (int i = 1; i <= n; ++i) {
    //     cout << a[i] << '\n';
    // }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == '#') continue;
            if (a[i][j] == '@') continue;

            for (int d = 0; d < 4; ++d) {
                if (auto [ri, rj] = getright(i, j, d); ri != -1 && a[ri][rj] != '#') {
                    G[ri][rj][turnright(d)].emplace_back(i, j, d);
                    continue;
                }

                if (auto [fi, fj] = getfront(i, j, d); fi != -1 && a[fi][fj] != '#') {
                    G[fi][fj][d].emplace_back(i, j, d);
                    continue;
                }

                if (auto [li, lj] = getleft(i, j, d); li != -1 && a[li][lj] != '#') {
                    G[li][lj][turnleft(d)].emplace_back(i, j, d);
                    continue;
                }

                if (auto [bi, bj] = getback(i, j, d); bi != -1 && a[bi][bj] != '#') {
                    G[bi][bj][turnback(d)].emplace_back(i, j, d);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int d = 0; d < 4; ++d) {

            auto push_q = [&](auto& v) {
                for (auto [x, y, p] : v) {
                    // printf("(%d, %d): %d\n", x, y, p);
                    que.emplace(x, y, p);
                    vis[x][y][p] = 1;
                    f[x][y][p] = 1;
                }
            };
            push_q(G[1][i][d]);
            push_q(G[n][i][d]);
            push_q(G[i][1][d]);
            push_q(G[i][n][d]);
        }
    }

    while (!que.empty()) {
        auto [x, y, d] = que.front();
        que.pop();
        for (auto [nx, ny, nd] : G[x][y][d]) {
            if (!vis[nx][ny][nd]) {
                vis[nx][ny][nd] = 1;
                f[nx][ny][nd] = f[x][y][d] + 1;
                que.push({nx, ny, nd});
            }
        }
    }

    for (int i = 1; i <= q; ++i) {
        int x, y, d;
        char t;
        cin >> x >> y >> t;
        d = getd(t);
        ++x, ++y;
        if (!vis[x][y][d]) {
            cout << "-1\n";
        } else {
            cout << f[x][y][d] << '\n';
        }
    }

    return 0;
}
