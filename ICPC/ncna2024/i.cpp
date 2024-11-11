#include <bits/stdc++.h>
using namespace std;

int odd_(string s, int idx) {
    int cnt = 0;
    for(int i = idx, j = idx; i >= 0 && j < s.length(); i--, j++) {
        if(i == j) cnt++;
        else {
            if(s[i] != s[j]) {
                return cnt;
            }
            else {
                cnt += 2;
            }
        }
    }
    return cnt;
}

int even_(string s, int idx) {
    int cnt = 0;
    for(int i = idx, j = idx + 1; i >= 0 && j < s.length(); i--, j++) {;
        if(s[i] != s[j]) {
            return cnt;
        }
        else {
            cnt += 2;
        }
    }
    return cnt;
}

inline void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> c, d;
    int f[n][m], p[n][m];
    memset(f, 0, sizeof f);
    memset(p, 0, sizeof p);

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        c.push_back(s);
    }

    for(int i = 0; i < m; i++) {
        string s = "";
        for(int j = 0; j < n; j++) {
            s += c[j][i];
        }
        d.push_back(s);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            string s = c[i];
            int l = 0, r = 0;
            int odd = odd_(s, j);
            l = j - odd / 2, r = j + odd / 2;

           for(int k = l; k <= r; k++) {
                f[i][k] = max(f[i][k], odd);
            }

            int even = even_(s, j) - 2;
            if(even >= 0) {
                l = j - even / 2, r = j + 1 + even / 2;
                for(int k = l; k <= r; k++) {
                    f[i][k] = max(f[i][k], even + 2);
                }
            }
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            string s = d[i];
            int l = 0, r = 0;
            int odd = odd_(s, j);
            l = j - odd / 2, r = j + odd / 2;

            for(int k = l; k <= r; k++) {
                p[k][i] = max(p[k][i], odd);
            }

            int even = even_(s, j) - 2;
            if(even >= 0) {
                l = j - even / 2, r = j + 1 + even / 2;
                for(int k = l; k <= r; k++) {
                    p[k][i] = max(p[k][i], even + 2);
                }
            }
        }
    }

    long long qwq = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            qwq = max(qwq, f[i][j] * 1ll * p[i][j]);
        }
    }
    cout << qwq << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}