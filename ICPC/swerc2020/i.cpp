#include <bits/stdc++.h>
using namespace std;

const int N = 100010, M = 200010;

int hed[N], to[M], nxt[M], edcnt;
inline void ADD(int x, int y) {
    nxt[++edcnt] = hed[x];
    hed[x] = edcnt;
    to[edcnt] = y;
}

int n, m;

int vis[N], dis[N];
void dijkstra(int s) {
    fill(vis + 1, vis + n + 1, 0);
    fill(dis + 1, dis + n + 1, INT_MAX);
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    dis[s] = 0;
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();

        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = hed[x]; i; i = nxt[i]) {
            int y = to[i];
            if (dis[y] > dis[x] + 1) {
                dis[y] = dis[x] + 1;
                q.push({-dis[y], y});
            }
        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        ADD(x, y);
        ADD(y, x);
    }

    int start = rand() % n + 1;

    dijkstra(start);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dis[i]);
    }

    if (ans > n) cout << "-1\n";
    else cout << ceil(log2(ans * 1.0)) + 1 << '\n';
    return 0;
}