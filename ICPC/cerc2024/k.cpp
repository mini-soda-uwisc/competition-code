#include <bits/stdc++.h>
using namespace std;

const int BIT = 4000;
bitset<BIT> a[65];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    auto ans = [&](string s) -> pair<int, string> {
        int n = s.size();

        bitset<BIT> st;
        for (int i = 0; i < n; i++) {
            bitset<BIT> bit;
            bit.set(0);
            if (s[i] == '#') {
                for (int j = 0; j < n; j++) {
                    st |= bit << (j * n + j);
                    st |= bit << (i * n + j);
                    st |= bit << (j * n + i);
                }

                for (int x = i, y = i; x < n && y >= 0; x++, y--) {
                    st |= bit << (x * n + y);
                }
                for (int x = i, y = i; x >= 0 && y < n; x--, y++) {
                    st |= bit << (x * n + y);
                }
            }
            else {
                for (int j = 0; j < n; j++) {
                    a[i] |= bit << (j * n + j);
                    a[i] |= bit << (i * n + j);
                    a[i] |= bit << (j * n + i);
                }

                for (int x = i, y = i; x < n && y >= 0; x++, y--) {
                    a[i] |= bit << (x * n + y);
                }
                for (int x = i, y = i; x >= 0 && y < n; x--, y++) {
                    a[i] |= bit << (x * n + y);
                }
            }
        }

        unordered_map<bitset<BIT>, int> mp;
        bitset<BIT> t;
        string ans = "";

        // cout << s << "\n";
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << st.test(i * n + j);
        //     }
        //     cout << "\n";
        // }

        for (int i = 0; i < n * n; i++) {
            t.set(i);
        }
        // cout << s << " " << st.count() << '\n';

        auto dfs = [&](auto& self, int id, bitset<BIT> p, int x) -> void {
            if (p.count() == n * n) {
                t = p;
                if (!mp.count(p)) {
                    ans = s;
                    mp[p] = x;
                }
                else {
                    if (mp[p] > x) {
                        mp[p] = x;
                        ans = s;
                    }
                }
                return;
            }


            mp[p] = x;
            for (int i = id; i < n; i++) {
                if (s[i] == '#') {
                    continue;
                }
                s[i] = '#';
                auto dp = p;
                dp |= a[i];
                self(self, i + 1, dp, x + 1);
                s[i] = '.';
            }
        };

        dfs(dfs, 0, st, 0);

        return make_pair(count(ans.begin(), ans.end(), '#'), ans);
    };

    string l = s, r = s;
    for (int i = 0; i < s.size(); i += 2) {
        l[i] = '#';
    }
    for (int i = 1; i < s.size(); i += 2) {
        r[i] = '#';
    }

    auto p1 = ans(l), p2 = ans(r);
    if (p1.first > p2.first) {
        cout << p2.first << "\n" << p2.second << "\n";
    }
    else {
        cout << p1.first << "\n" << p1.second << "\n";
    }
    return 0;
}