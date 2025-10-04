#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

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

const int N = (int)2e5 + 1, M = N * 2;

vector<int> adj[N];
int vis[N], miss[N];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int a, b;
    cin >> a >> b;

    queue<int> q;
    q.push(a);
    vis[a] = 1;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (auto& v : adj[u]) {
            if (vis[v]) {
                continue;
            }
            vis[v] = 1;
            q.push(v);
        }
    }

    q.push(b);
    miss[b] = 1;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (auto&v : adj[u]) {
            if (miss[v]) {
                continue;
            }
            miss[v] = 1;
            q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] && miss[i]) {
            cout << "yes\n" << i << "\n";
            return;
        }
    }
    cout << "no\n";
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
