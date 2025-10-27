#include <bits/stdc++.h>
using namespace std;

int n, m;
int sx, sy, px, py;
string a[100];

// 0 up 1 left 2 down 3 right
int vis[100][100][4];

inline int left(int cur) {
    return (cur + 1) % 4;
}
inline int right(int cur) {
    return (cur + 3) % 4;
}

inline int valid(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >>m >> sx >> sy >> px >> py;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = '#' + a[i];
    }

    int d = 3;
    int x = sx, y = sy;
    while (1) {
        // cout << "now at (" << x << ", " << y << "), towards " << d << "\n";
        if (x == px && y == py) {
            cout << "1\n";
            return 0;
        }

        if (vis[x][y][d]) {
            cout << "0\n";
            return 0;
        }

        vis[x][y][d] = 1;
        int nx = x + dx[left(d)], ny = y + dy[left(d)];
        if (valid(nx, ny) && a[nx][ny] == '0') {
            d = left(d);
            x = nx;
            y = ny;
            continue;
        }

        nx = x + dx[d];
        ny = y + dy[d];
        if (valid(nx, ny) && a[nx][ny] == '0') {
            x = nx;
            y = ny;
            continue;
        }

        d = right(d);
    }
    return 0;
}