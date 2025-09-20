#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

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

int dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};

void solve() {
    int n, m;
    cin >> n >> m;

    int a[n][m], vis[n][m];
    priority_queue<vector<int>, vector<vector<int>>, less<>> q;
    memset(vis, 0, sizeof vis);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            q.push({a[i][j], i, j});
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        auto p = q.top();
        q.pop();

        if (vis[p[1]][p[2]]) {
            continue;
        }

        queue<vector<int>> que;
        vis[p[1]][p[2]] = 1;
        if (p[0] <= 1) {
            continue;
        }
        que.push(p);
        cnt++;

        while (!que.empty()) {
            auto pair = que.front();
            que.pop();

            int h = pair[0], x = pair[1], y = pair[2];
            for (int i = 0; i < 4; i++) {
                int dx = x + dirx[i], dy = y + diry[i];
                if (dx < 0 || dy < 0 || dx >= n || dy >= m || h < a[dx][dy] || vis[dx][dy] || a[dx][dy] <= 1) {
                    continue;
                }
                vis[dx][dy] = 1;
                que.push({a[dx][dy], dx, dy});
            }
        }
    }
    cout << cnt << "\n";
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
