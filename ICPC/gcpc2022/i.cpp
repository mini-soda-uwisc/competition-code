#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

#define int long long

int n, m;

int hed[N], to[N], nxt[N], wt[N], edcnt = 0;
inline void ADD(int x, int y, int z) {
    nxt[++edcnt] = hed[x];
    to[edcnt] = y;
    wt[edcnt] = z;
    hed[x] = edcnt;
}

int vis[N], dis[N];
inline void dij() {
    fill(dis, dis + N, LLONG_MAX);
    fill(vis, vis + N, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, 1});
    dis[1] = 0;
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();

        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = hed[x]; i; i = nxt[i]) {
            int y = to[i];
            if (dis[x] + wt[i] < dis[y]) {
                dis[y] = dis[x] + wt[i];
                q.push({dis[y], y});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int buyprice;
        cin >> buyprice;
        for (int j = 1; j <= min(m, n - i + 1); ++j) {
            int sellprice;
            cin >> sellprice;
            ADD(i, i + j, buyprice - sellprice);
        }
    }

    dij();
    cout << dis[n + 1] << '\n';
    return 0;
}