#include <bits/stdc++.h>
using namespace std;

string a[110];
int ans[110][110];
int DataIndex = 0;
int n, m, d1, d2;

inline int isvalid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

inline void solve() {
    memset(ans, 0, sizeof(ans));
    cin >> n >> m >> d1 >> d2;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = " " + a[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'V') {
                if (isvalid(i, j + 1)) ans[i][j + 1] = d1;
                if (isvalid(i, j - 1)) ans[i][j - 1] = d1;
                if (isvalid(i + 1, j)) ans[i + 1][j] = d1;
                if (isvalid(i - 1, j)) ans[i - 1][j] = d1;

                if (isvalid(i + 1, j + 1)) ans[i + 1][j + 1] = max(ans[i + 1][j + 1], d2);
                if (isvalid(i + 1, j - 1)) ans[i + 1][j - 1] = max(ans[i + 1][j - 1], d2);
                if (isvalid(i - 1, j + 1)) ans[i - 1][j + 1] = max(ans[i - 1][j + 1], d2);
                if (isvalid(i - 1, j - 1)) ans[i - 1][j - 1] = max(ans[i - 1][j - 1], d2);
            }
        }
    }

    cout << "Airplane #" << ++DataIndex << ":\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'V') cout << 'V';
            else cout << ans[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}