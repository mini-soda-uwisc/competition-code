#include <bits/stdc++.h>
using namespace std;

const int N = 150 * 150, M = N * N;
vector<vector<int>> G;
map<int, int> in_s;
vector<int> s;

map<int, int> in_t;
vector<int> t;

int n, m;
int a[150][150];
int dis1[N], dis2[N], dis3[N];


void dij(int s, int dis[]) {
    priority_queue<pair<int, int>> q;
    fill(dis, dis + N, INT_MAX);
    dis[s] = 1;
    q.emplace(-1, s);

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        d = -d;
        if (d != dis[u]) continue;
        for (int v : G[u]) {
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.emplace(-dis[v], v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    G.resize(n * m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = n; i > 1; --i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] != a[i - 1][j]) {
                G[a[i - 1][j]].push_back(a[i][j]);
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (!in_s[a[1][i]]) {
            in_s[a[1][i]] = 1;
            s.push_back(a[1][i]);
        }

        if (!in_t[a[n][i]]) {
            in_t[a[n][i]] = 1;
            t.push_back(a[n][i]);
        }
    }

    if (s.size() == 1) {
        dij(s[0], dis1);

        int ans = INT_MAX;
        for (int i = 0; i < t.size(); ++i) {
            if (dis1[t[i]] != INT_MAX) {
                ans = min(ans, dis1[t[i]]);
            }
        }
        cout << ans << '\n';
    } else {
        dij(s[0], dis1);
        dij(s[1], dis2);

        int ans = INT_MAX;
        for (int i = 0; i < t.size(); ++i) {
            for (int j = 0; j < t.size(); ++j) {
//                cout << "i: " << i << " j: " << j << '\n';
//                cout << "t[i]: " << t[i] << " t[j]: " << t[j] << '\n';
//                cout << dis1[t[i]] << ' ' << dis2[t[j]] << '\n';
//                cout << "\n\n";
                if (dis1[t[i]] == INT_MAX || dis2[t[j]] == INT_MAX) continue;
                ans = min(ans, dis1[t[i]] + dis2[t[j]]);
            }
        }

        for (int p = 1; p <= n * m; ++p) {
            if (dis1[p] == INT_MAX || dis2[p] == INT_MAX) continue;
            dij(p, dis3);

            for (int i = 0; i < t.size(); ++i) {
                if (dis3[t[i]] == INT_MAX) continue;
                ans = min(ans, dis1[p] - 1 + dis2[p] - 1 + dis3[t[i]]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}