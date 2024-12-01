#include <bits/stdc++.h>
using namespace std;

inline int check(const string& s) {
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] != s[i - 1]) return false;
    }
    return true;
}

inline void solve() {
    vector<int> v;
    string s;

    v.clear();
    int cur = 1;
    int ans = 0;
    cin >> s;

    int n = (int)s.length();

    if (check(s)) {
        cout << n / 2 << '\n';
        return;
    }
    int index = 0;
    while (s[index] == s[(index - 1 + n) % n]) {
        index = (index + 1) % n;
        if (index == 0) break;
    }
    s = s.substr(index, s.length() - index) + s.substr(0, index);
//    cout << s << '\n';
    for (int i = 1; i < n; ++i) {
//        cout << i << '\n';
        if (s[i] != s[i - 1]) {
            v.emplace_back(cur);
            ans += cur / 2;
            cur = 1;
        } else {
            ++cur;
        }
    }
//    cout << "xun huan zhong liao!\n";
    v.emplace_back(cur);
    ans += cur / 2;

    for (int length : v) {
        if (length % 2 == 0) {
            cout << ans - 1 << '\n';
            return;
        }
    }

    cout << ans << '\n';
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