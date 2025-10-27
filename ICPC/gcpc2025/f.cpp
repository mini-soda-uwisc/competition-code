#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ld = long double;
using ll = long long;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b){
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b){
    return a > b ? b : a;
}

const int N = (int)2e5 + 1, M = N * 10;

int vis[2501][2501];

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') {
                cnt++;
            }
            else {
                max = chmax(max, cnt);
                cnt = 0;
            }
        }
        max = chmax(max, cnt);
    }

    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j][i] == '#') {
                cnt++;
            }
            else {
                max = chmax(max, cnt);
                cnt = 0;
            }
        }
        max = chmax(max, cnt);
    }

    auto check = [&](int x) -> bool {
        memset(vis, 0, sizeof vis);
        for (int i = 0; i <= n - x; i++) {
            for (int j = 0; j <= m - x; j++) {
                if (vis[i][j] || a[i][j] == '.') {
                    continue;
                }
                for (int k = i; k < i + x; k++) {
                    for (int l = j; l < j + x; l++) {
                        if (a[k][l] == '#') {
                            vis[k][l] = 1;
                        }
                        else {
                            return 0;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] &&a[i][j] == '#') {
                    return 0;
                }
            }
        }
        return 1;
    };

    int ans = 1;
    for (int i = 1; i * i <= max; i++) {
        if (max % i == 0) {
            if (check(i)) {
                ans = chmax(ans, i);
            }
            if (check(max / i)) {
                ans = chmax(ans, max / i);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}