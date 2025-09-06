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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }
    reverse(a.begin(), a.end());

    vector<int> c;
    map<int, int> ndp;
    for (int i = 0; i < (1 << m); i++) {
        if (__popcount(i) & 1) {
            continue;
        }

        int flag = 1;
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                if (j + 1 >= m || (i >> (j + 1) & 1) == 0) {
                    flag = 0;
                    break;
                }
                j++;
            }
        }

        if (flag) {
            c.push_back(i);
            ndp[i] = __popcount(i) >> 1;
        }
    }

    map<int, vector<int>> mp;
    for (int i = 0; i < c.size(); i++) {
        for (int j = 0; j < c.size(); j++) {
            int flag = 1;
            for (int k = 0; k < m; k++) {
                if (c[i] >> k & 1){
                    if (k + 1 >= m || !((c[j] >> k & 1) || (c[j] >> (k + 1) & 1))) {
                        flag = 0;
                    }
                    k++;
                }
            }


            if (flag) {
                mp[c[i]].push_back(c[j]);
            }
        }
    }

    auto get = [&](int i) -> int {
        int need = 0;
        for (int j = i; j <= i + 1; j++) {
            for (int k = 0; k < m; k++) {
                if (a[j][k] == '#') {
                    need |= 1 << k;
                }
            }
        }
        return need;
    };

    ll dp[n][1 << m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << m); j++) {
            dp[i][j] = INF;
        }
    }
    int bit = get(0);
    for (int i = 0; i < c.size(); i++) {
        if ((c[i] | bit) != c[i]) {
            continue;
        }
        dp[0][c[i]] = ndp[c[i]];
    }

    for (int i = 2; i < n; i += 2) {
        int need = get(i);
        for (int j = 0; j < c.size(); j++) {
            int mask = c[j];
            if ((mask | need) != mask) {
                continue;
            }
            for (auto& v : mp[mask]) {
                // cout << mask << " " << v << " " << dp[i - 2][v] << "\n";
                dp[i][mask] = chmin(dp[i][mask], dp[i - 2][v] + ndp[mask]);
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i < c.size(); i++) {
        ans = chmin(ans, dp[n - 2][c[i]]);
    }
    cout << ans << "\n";
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
