#include <bits/stdc++.h>
using namespace std;

int n;
map<string, stack<string>> nicks;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        nicks[s.substr(0, 4)].push(s);
    }

    vector<pair<string, string>> ans;

    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        string t = s.substr(0, 4);
        if (nicks[t].empty()) {
            cout << "NO\n";
            return 0;
        }

        ans.emplace_back(nicks[t].top(), s);
        nicks[t].pop();
    }

    cout << "YES\n";
    for (auto& [s, t] : ans) {
        cout << s << ' ' << t << '\n';
    }
    return 0;
}