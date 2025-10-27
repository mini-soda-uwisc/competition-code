#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

#define ll long long

int n, m;
ll p[N];
int hed[N], to[N], nxt[N], edcnt;
ll wt[N];
inline void ADD(int x, int y, ll z) {
    nxt[++edcnt] = hed[x];
    hed[x] = edcnt;
    to[edcnt] = y;
    wt[edcnt] = z;
}

int vis[N];
ll dis[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= m; ++i) {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        ADD(x, y, z);
        ADD(y, x, z);
    }

    memset(dis, 0x3f, sizeof(dis));
    priority_queue<pair<int, int>> q;
    q.emplace(0, 1);
    dis[1] = 0;

    while (!q.empty()) {
        int x = q.top().second;
        q.pop();

        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = hed[x]; i; i = nxt[i]) {
            int y = to[i];
            if (dis[y] > dis[x] + wt[i]) {
                dis[y] = dis[x] + wt[i];
                q.emplace(-dis[y], y);
            }
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     cout << "dis[" << i << "]: " << dis[i] << '\n';
    // }
    ll ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans += dis[i] * p[i];
    }
    cout << ans << '\n';
    return 0;
}