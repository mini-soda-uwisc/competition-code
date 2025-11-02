#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, k;
map<int, int> forb, f;

inline int getnum(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    return c - 'A' + 10;
}
inline char getc(int x) {
    if (0 <= x && x <= 9) return x + '0';
    return x - 10 + 'A';
}

inline void solve() {
    forb.clear();
    f.clear();
    cin >> n >> k >> m;
    for (int i = 1; i <= m; ++i) {
        string s;
        cin >> s;
        forb[getnum(s[0])] = 1;
    }

    if (k == 0) {
        cout << "0\n";
        return;
    }

    f[0] = 0;
    for (int i = 1, j = 1; i < n; ++i) {
        if (!forb[i]) {
            f[j] = i;
            ++j;
        }
    }

    int new_n = n - m;
    vector<int> ans;
    int jw = 0;
    while (k || jw) {
        int p = k % new_n + jw;
        if (p >= new_n) {
            p -= new_n;
            jw = 1;
        }
        ans.emplace_back(p);
        k /= new_n;
    }

    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << getc(f[ans[i]]);
    }
    cout << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}