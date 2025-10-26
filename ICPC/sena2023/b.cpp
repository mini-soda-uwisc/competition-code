#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e3 + 1;

vector<int> adj[N];
int vis[N][N];

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        auto check = [&](char a, char b) -> bool {
            if (a == '(' && b == ')') {
                return 1;
            }
            if (a == '[' && b == ']') {
                return 1;
            }
            if (a == '{' && b == '}') {
                return 1;
            }
            return 0;
        };

        stack<char> t;

        auto dfs = [&](auto& self, int u, int fa) -> void {
            char ch = '0';
            if (!t.empty()) {
                if (check(t.top(), s[u])) {
                    ch = t.top();
                    t.pop();

                    if (t.empty()) {
                        vis[i][u] = 1;
                    }

                    // cout << "in1 " << u << " " << ch << "\n";
                }
                else {
                    t.push(s[u]);
                    // cout << "in2 " << u << "\n";
                }
            }
            else {
                t.push(s[u]);
                // cout << "in3 " << u << "\n";
            }

            for (auto& v : adj[u]) {
                if (v == fa) {
                    continue;
                }
                self(self, v, u);
            }
            if (ch == '(' || ch == '[' || ch == '{') {
                t.push(ch);
            }
            else {
                assert(!t.empty());
                t.pop();
            }
        };

        if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            continue;
        }

        dfs(dfs, i, i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || !vis[i][j]) {
                continue;
            }
            ans += vis[i][j];
            assert(vis[i][j] != vis[j][i]);
        }
    }

    cout << ans << "\n";
}