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
        int n, w;
        cin >> n >> w;

        vector<string> s;
        s.pb(" ");
        for (int i = 0; i < n; i++) {
            string t;
            cin >> t;
            s.pb(t);
        }

        auto cmp = [&](string a, string b) -> int {
            for (int i = 0; i < chmin(a.size(), b.size()); i++) {
                if (a[i] > b[i]) {
                    return 0;
                }
                if (a[i] < b[i]) {
                    return 1;
                }
            }
            return a.size() < b.size();
        };

        int l = 1, r = n;
        sort(s.begin() + 1, s.end(), cmp);
        vector<int> idx;

        auto check = [&](int mid) -> int {
            vector<vector<int>> f(n + 1, vector<int>(2, 1e9));
            f[0][0] = 0;

            for (int i = 0; i <= n; i++) {
                f[i][1] = -1;
            }

            for (int i = 1; i <= n; i++) {
                int max = s[i].size();
                for (int j = i; j >= chmax(1, i - mid + 1); j--) {
                    max = chmax(max, (int)s[j].size());
                    if (f[i][0] > f[j - 1][0] + max + (i != n)) {
                        f[i][0] = f[j - 1][0] + max + (i != n);
                        f[i][1] = j - 1;
                    }
                }
            }

            if (f[n][0] <= w) {
                idx.clear();
                int id = n;
                idx.pb(n);
                id = f[n][1];

                while (id != -1) {
                    idx.pb(id);
                    id = f[id][1];
                }

                if (idx.back() != 0) {
                    idx.pb(0);
                }
            }
            return f[n][0];
        };

        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid) <= w) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        vector<int> rmax;
        check(l);
        reverse(idx.begin(), idx.end());

        for (int i = 1; i < idx.size(); i++) {
            int row = 0;
            for (int j = idx[i - 1] + 1; j <= idx[i]; j++) {
                row = chmax(row, (int)s[j].size());
            }
            rmax.pb(row);
        }

        int W = 0;
        cout << l << " " << rmax.size() << endl;
        for (auto rw : rmax) {
            cout << rw << " ";
            W += rw + 1;
        }
        W -= 1;
        cout << endl;

        char g[l][W];
        memset(g, ' ', sizeof(g));

        int pt = 1, row = 0, col = 0;
        for (int i = idx[pt - 1] + 1; i <= idx[pt]; i++) {
            for (int j = row; j < row + s[i].size(); j++) {
                g[col][j] = s[i][j - row];
            }
            col++;
            if (i == idx[pt] && pt + 1 < idx.size()) {
                row += rmax[pt - 1] + 1;
                col = 0;
                pt++;
            }
        }

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < W; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }
        cout << endl;
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
