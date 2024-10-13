#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const ll mod = 1e9 + 7;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

ll fpow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

void solve(){
    int r, c;
    cin >> r >> c;

    vector<vector<int>> a(r + 5, vector<int>(c + 5));

    vector<vector<int>> place_of_1(c + 5);
    for (int i = 1; i <= r; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= c; j++) {
            a[i][j] = s[j - 1] - '0';
            if (a[i][j] == 1) {
                place_of_1[j].pb(i);
            }
        }
    }

    vector<vector<int>> G(r * 2 + 5);
    for (int i = 1; i <= c; ++i) {
        int j = c - i + 1;
        if (i == j) {
            if (place_of_1[i].size() >= 2) {
                cout << "0\n";
                return;
            }
        } else {
            if (place_of_1[i].size() + place_of_1[j].size() > 2) {
                cout << "0\n";
                return;
            }
        }
    }

    for (int i = 1; i <= c / 2; ++i) {
        int j = c - i + 1;

        if (place_of_1[i].size() + place_of_1[j].size() < 2) {
            continue;
        }
        if (place_of_1[i].size() == 2) {
            int x = place_of_1[i][0], y = place_of_1[i][1];
            int xp = x + r, yp = y + r;
            G[x].pb(yp);
            G[yp].pb(x);
            G[y].pb(xp);
            G[xp].pb(y);
        } else if (place_of_1[j].size() == 2) {
            int x = place_of_1[j][0], y = place_of_1[j][1];
            int xp = x + r, yp = y + r;
            G[x].pb(yp);
            G[yp].pb(x);
            G[y].pb(xp);
            G[xp].pb(y);
        } else {
            int x = place_of_1[i][0], y = place_of_1[j][0];
            int xp = x + r, yp = y + r;
            G[x].pb(y);
            G[y].pb(x);
            G[xp].pb(yp);
            G[yp].pb(xp);
        }
    }

    int blocks = 0;
    vector<int> vis(r * 2 + 5, 0);
    auto bfs = [&](int x) {
        queue<int> q;
        while (!q.empty()) q.pop();
        q.push(x);
        vis[x] = blocks;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) {
                if (!vis[v]) {
                    vis[v] = blocks;
                    q.push(v);
                }
            }
        }
    };


    for (int i = 1; i <= 2 * r; ++i) {
        if (!vis[i]) {
            ++blocks;
            bfs(i);
        }
    }

    for (int i = 1; i <= r; ++i) {
        if (vis[i] == vis[i + r]) {
            cout << "0\n";
            return;
        }
    }

    cout << fpow(2, blocks / 2) << '\n';
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}