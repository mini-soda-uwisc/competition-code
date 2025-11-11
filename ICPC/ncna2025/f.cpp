#include <bits/stdc++.h>
using namespace std;

const int N = 10001;

int node[N], b[1001][1001];

int find(int x) {
    return x == node[x] ? x : node[x] = find(node[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < N; i++) {
        node[i] = i;
    }

    int n, m;
    cin >> n >> m;

    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                continue;
            }

            int cnt = 0;
            for (int k = max(0, i - 3); k < min(n, i + 4); k++) {
                for (int l = max(0, j - 3); l < min(m, j + 4); l++) {
                    if (a[k][l] == 0 || (i == k && j == l)) {
                        continue;
                    }
                    if (abs(i - k) + abs(j - l) <= 3) {
                        cnt++;
                    }
                }
            }

            if (cnt >= 7) {
                b[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j]) {
                for (int k = max(0, i - 3); k < min(n, i + 4); k++) {
                    for (int l = max(0, j - 3); l < min(m, j + 4); l++) {
                        if (a[k][l] == 0) {
                            continue;
                        }
                        if (abs(i - k) + abs(j - l) <= 3) {
                            int x = i * m + j, y = k * m + l;
                            if (x > y) {
                                swap(x, y);
                            }
                            if (find(x) != find(y)) {
                                node[find(y)] = find(x);
                            }
                        }
                    }
                }
            }
        }
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                mp[find(i * m + j)]++;
            }
        }
    }

    int ans = 0;
    for (auto& [k, v] : mp) {
        if (v >= 8) {
            // cout << v / m << " " << v % m << "\n";
            ans++;
        }
    }

    if (ans) {
        cout << "Yes\n";
        cout << ans - 1 << "\n";
        cout << mp.size() - ans << "\n";
    }
    else {
        cout << "No\n";
        cout << ans << "\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += a[i][j];
            }
        }

        cout << ans << "\n";
    }

    return 0;
}