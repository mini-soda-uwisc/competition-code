#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;
const double MAXN = 1e4 + 0.1;

template <typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> a;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x - 1, y - 1});
    }

    vector<vector<int>> a1(n, vector<int>(m)), a2(n, vector<int>(m));
    priority_queue<vector<int>, vector<vector<int>>, greater<>> q;

    for (int i = 0; i < k; i++) {
        q.push({0, i + 1, a[i].first, a[i].second});
    }

    int dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};
    while (!q.empty()) {
        auto p = q.top();
        q.pop();

        int d = p[0], id = p[1], x = p[2], y = p[3];
        if (!a1[x][y]) {
            a1[x][y] = id;
        }
        else if (a1[x][y] && a1[x][y] != id && !a2[x][y]) {
            a2[x][y] = id;
        }
        else {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int dx = x + dirx[i], dy = y + diry[i];
            if (dx < 0 || dy < 0 || dx >= n || dy >= m) {
                continue;
            }
            q.push({d + 1, id, dx, dy});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a1[i][j] << " \n"[j == m - 1];
        }
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a2[i][j] << " \n"[j == m - 1];
        }
    }
    cout << "\n";
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    double ans = MAXN;

    while (t--) {
        solve();
    }

    return 0;
}
