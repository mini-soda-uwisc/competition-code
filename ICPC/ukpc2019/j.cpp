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

const int N = (int)1e5 + 1, M = N * 2;

ld dp[101][101];

void solve() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    int b[m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = INF;
        }
    }

    ld cir = 360.0 / m, inc = cir;
    vector<vector<ld>> p;
    for (int i = 0; i < m; i++) {
        p.push_back({cos(cir * pi / 180.0), sin(cir * pi / 180.0)});
        cir += inc;

    }

    for (int i = 0; i < m; i++) {
        if (b[i] == a[0]) {
            dp[0][i] = sqrt(p[i][0] * p[i][0] + p[i][1] * p[i][1]);
        }
    }

    auto dist = [&](int x, int y) -> ld {
        ld dx = p[x][0] - p[y][0], dy = p[x][1] - p[y][1];
        return sqrt(dx * dx + dy * dy);
    };

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[j] != a[i - 1]) {
                continue;
            }
            for (int k = 0; k < m; k++) {
                if (b[k] == a[i]) {
                    dp[i][k] = chmin(dp[i][k], dp[i - 1][j] + dist(j, k));
                }
            }
        }
    }

    ld ans = INF;
    for (int i = 0; i < m; i++) {
        if (b[i] == a[n - 1]) {
            ans = chmin(ans, dp[n - 1][i]);
        }
    }
    cout << setprecision(20) << ans << "\n";
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
