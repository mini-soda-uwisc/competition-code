#include <bits/stdc++.h>
using namespace std;

int n, m, k;
map<string, int> mp;
map<string, pair<int, int>> tb;

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j += k) {
            ++mp[s.substr(j, k)];
            tb[s.substr(j, k)] = {i, (j / k) + 1};
        }
    }

    for (auto& [s, v] : mp) {
        if (v == 1) {
            cout << tb[s].first << ' ' << tb[s].second << '\n';
            break;
        }
    }
    return 0;
}