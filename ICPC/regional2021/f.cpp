    #include <bits/stdc++.h>

    using namespace std;
    using ll = long long;
    using ld = long double;
    #define int long long

    #define pb push_back

    const ld pi = 3.14159265358979323846;
    const int mod = 1000000007;
    const ll INF = 1e18;

    string p, S, s;

    template<typename T>
    T chmax(T a, T b) {
        return a > b ? a : b;
    }

    template<typename T>
    T chmin(T a, T b) {
        return a > b ? b : a;
    }

    const int N = (int) 1e5 + 5, M = N * 2;

    int ans = 0;
    int f[N][55];
    inline void dp() {
        int n = p.length(), m = s.length();
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m + 1; ++j) {
                f[i][j] = 0;
            }
        }
        f[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (j != m && p[i] == s[j]) {
                    f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j]) % mod;
                }
                f[i + 1][j] = (f[i + 1][j] + f[i][j]) % mod;
            }
        }

        ans = (ans + f[n][m]) % mod;
    }

    map<string, int> mp;

    void solve() {
        cin >> p >> S;
        for (int i = 0; i < S.length(); ++i) {
            s = S.substr(i, S.length() - i) + S.substr(0, i);
            if (mp[s]) continue;
            mp[s] = 1;
    //        cout << s << '\n';
            dp();
        }

        cout << ans << '\n';
    }

    signed main() {
        // freopen(".in", "r", stdin);
        // freopen(".out", "w", stdout);

        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int t = 1;
    //    cin >> t;

        while (t--) {
            solve();
        }

        return 0;
    }