#include <bits/stdc++.h>
using namespace std;

int n, m;

int dfs(int cur, vector<vector<int>> &G, vector<int> &vis) {
    if (vis[cur]) return 0;
    vis[cur] = 1;
    int ans = 1;
    for (int i = 0; i < G[cur].size(); ++i) {
        ans += dfs(G[cur][i], G, vis);
    }
    return ans;
}

inline int solve(vector<vector<int>> &f, vector<vector<int>>& target) {
//    cout << "=======solve======\n";
    int ans = 0;
    vector<vector<int>> G(n + 50);
    vector<int> vis(n * m + 50, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (f[i][j] != target[i][j]) {
                G[target[i][j]].push_back(f[i][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!vis[f[i][j]] && f[i][j] != -1) {
                int t = dfs(f[i][j], G, vis);
//                cout << "found block: " << t << '\n';
                ans += t - 1;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;

    vector<vector<int>> f(n + 50, vector<int>(m + 50));
    vector<int> a;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> f[i][j];
            if(f[i][j] != -1) {
                a.push_back(f[i][j]);
            }
        }
    }

    sort(a.begin(), a.end());
    map<int, int> mp;
    mp[-1] = -1;

    int idx = 0;
    for(int i = 0; i < a.size(); i++){
        if (i != 0 && a[i] == a[i - 1]) continue;
//        cout << "a[i]: " << a[i] << '\n';
        mp[a[i]] = ++idx;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            f[i][j] = mp[f[i][j]];
        }
    }

    vector<vector<int>> t1(n + 50, vector<int>(m + 50));
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        int r = i, c = 1;
        while (r >= 1 && c <= m) {
            if (f[r][c] != -1) {
                t1[r][c] = ++cur;
            } else {
                t1[r][c] = -1;
            }

            r--;
            c++;
        }
    }
    for (int i = 2; i <= m; ++i) {
        int r = n, c = i;
        while (r >= 1 && c <= m) {
            if (f[r][c] != -1) {
                t1[r][c] = ++cur;
            } else {
                t1[r][c] = -1;
            }

            r--;
            c++;
        }
    }

    vector<vector<int>> t2(n + 50, vector<int>(m + 50));
    cur = 0;
    for (int i = 1; i <= m; ++i) {
        int r = n, c = i;
        while (r >= 1 && c >= 1) {
            if (f[r][c] != -1) {
                t2[r][c] = ++cur;
            } else {
                t2[r][c] = -1;
            }

            r--;
            c--;
        }
    }
    for (int i = n - 1; i >= 1; --i) {
        int r = i, c = m;
        while (r >= 1 && c >= 1) {
            if (f[r][c] != -1) {
                t2[r][c] = ++cur;
            } else {
                t2[r][c] = -1;
            }

            r--;
            c--;
        }
    }

//    cout << "======== f =======\n";
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            cout << f[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//
//    cout << "======== t1 =======\n";
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            cout << t1[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//
//    cout << "======== t2 =======\n";
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            cout << t2[i][j] << ' ';
//        }
//        cout << '\n';
//    }

    int ans1 = solve(f, t1);
    int ans2 = solve(f, t2);
//    cout << "ans1: " << ans1 << ", ans2: " << ans2 << '\n';
    int ans = min(ans1, ans2);
    cout << ans << '\n';
    return 0;
}