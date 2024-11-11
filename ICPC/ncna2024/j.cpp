#include <bits/stdc++.h>
using namespace std;

int n;
long long m;

inline long long get_min(long long a[]) {
    sort(a, a + n);
    double p = a[0];
    int k = 1;
    long long c = 0;

    while (ceil(p / (1 << (k - 1)) > 1)) {
        c += ceil(p / (1 << (k - 1)));
        ++k;
    }

    return c;
}

inline void solve() {
    cin >> n >> m;
    long long a[n + 10000];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (get_min(a) <= m) {
        cout << "YES\n";
        return;
    }

    vector<vector<int>> b(100);
    for(int i = 0; i < n; i++) {
        long long cur = a[i];
        int cnt = 1;
        while(cnt < 31) {
            b[cnt].push_back(cur);
            cur = (long long)ceil(cur / 2.0);
            cnt++;
        }
    }

    int f[100][m + 1000];
    memset(f, 0, sizeof f);
    f[0][0] = 1;

    int qwq = 0;
    for(int i = 0; i < 31; i++) {
        for(int j = 0; j < b[i].size(); j++) {
            for(int k = m; k >= b[i][j]; k--) {
                f[i][k] |= f[i - 1][k - b[i][j]];
                if((k == m && f[i][k]) || (i == 15 && f[i][k])) qwq = 1;
            }
        }
    }

    cout << (qwq ? "YES" : "NO") << endl;
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