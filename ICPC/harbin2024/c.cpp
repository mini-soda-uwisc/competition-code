#include <bits/stdc++.h>

using namespace std;

map<string, string> mp = {{"ES", "R"},
                          {"SW", "R"},
                          {"WN", "R"},
                          {"NE", "R"},
                          {"EN", "L"},
                          {"NW", "L"},
                          {"WS", "L"},
                          {"SE", "L"}};

inline string dirToNum(const string &x, const string &y) {
    assert(mp.find(x + y) != mp.end());
    return mp[x + y];
}

inline void solve() {
    vector<pair<string, int>> dir;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string d;
        int len;
        cin >> d >> len;
        dir.emplace_back(d, len);
    }
    vector<string> ans;
    for (int i = 1; i < n; ++i) {
        string d = dirToNum(dir[i - 1].first, dir[i].first);
        ans.emplace_back(d);
        ans.emplace_back("Z " + to_string(dir[i].second));
    }
    cout << ans.size() + 1 << " " << dir[0].first << endl;
    cout << "Z " << dir[0].second << endl;
    for (auto &a: ans) {
        cout << a << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}