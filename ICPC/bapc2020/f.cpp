#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
const int M = 1e5 + 10;

typedef long long ll;

int n, m, p;
ll g;

int f[N];

int hed[N], to[M], nxt[M], edcnt;
ll wt[M];
inline void ADD(int x, int y, ll w) {
    nxt[++edcnt] = hed[x];
    hed[x] = edcnt;
    to[edcnt] = y;
    wt[edcnt] = w;
}

int vis[N];
ll dis[N];
vector<int> pre[N];

inline void dij() {
    priority_queue<pair<int, int>> q;
    fill(dis + 1, dis + n + 1, 0x3f3f3f3f);
    dis[1] = 0;
    q.emplace(0, 1);
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = hed[x]; i; i = nxt[i]) {
            int y = to[i];
            ll w = wt[i];
            if (dis[y] > dis[x] + w) {
                dis[y] = dis[x] + w;
                q.emplace(-dis[y], y);
                pre[y].clear();
                pre[y].emplace_back(x);
            } else if (dis[y] == dis[x] + w) {
                pre[y].emplace_back(x);
            }
        }
    }
}

vector<int> tags[N];

void dfs(int x, int tag) {
    tags[x].emplace_back(tag);
    if (x == 1) {
        return;
    }
    for (int i : pre[x]) {
        dfs(i, tag);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> p >> g;
    for (int i = 1; i <= p; ++i) {
        cin >> f[i];
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        ADD(u, v, w);
        ADD(v, u, w);
    }

    dij();
    // cerr << "dis: \n";
    // for (int i = 1; i <= n; ++i) {
    //     cerr << i << ": " << dis[i] << '\n';
    // }

    ll ans_i = 0;
    for (int i = 1; i <= p; ++i) {
        dfs(f[i], f[i]);
        ans_i += dis[f[i]];
    }

    ll ans = ans_i;
    // cerr << "init ans: " << ans_i << '\n';

    for (int i = 1; i <= n; ++i) {
        // cerr << "now: " << i << '\n';
        // cerr << "dis: " << dis[i] << '\n';
        ll res = ans_i;
        // cerr << "init res: " << res << '\n';
        for (int tag : tags[i]) {
            // cerr << "find tag: " << tag << ", dis: " << dis[tag] << '\n';
            ll newroute = g + (dis[tag] - dis[i]);
            if (newroute < dis[tag]) {
                res -=  dis[tag];
                res += newroute;
            }
            // cerr << "now res: " << res << '\n';
        }

        // cerr << "result: " << res << '\n';
        ans = min(ans, res);
    }

    cout << ans << '\n';
    return 0;
}