#include <bits/stdc++.h>
using namespace std;

int n;
int ans1 = 0, ans2 = 0, ans3 = 0;
string s;

int a[1000][10];

inline int to10(char c) {
    if ('0' <= c && c <= '9') return c - '0' + 0;
    else if ('a' <= c && c <= 'f') return c - 'a' + 10;
    assert(false);
}

inline void work(int idx, char p, char q) {
    int x = to10(p), y = to10(q);
    for (int i = 3; i >= 0; --i) {
        a[idx][i] = x % 2;
        x /= 2;
    }
    for (int i = 7; i >= 4; --i) {
        a[idx][i] = y % 2;
        y /= 2;
    }
}

inline int is10(int p) {
    return a[p][0] == 1 && a[p][1] == 0;
}

inline void solve() {
    n = 0;
    for (int j = 0; j < s.length(); j += 2) {
        work(++n, s[j], s[j + 1]);
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= 8; ++j) {
    //         cout << a[i][j];
    //     }
    //     cout << ' ';
    // }
    // cout << '\n';

    int p = 1;
    int is_first = 1;
    int is_third = 0;
    while (p <= n) {
        if (is_third) break;
        if (a[p][0] == 0) {
            ++p;
            continue;
        }
        is_first = 0;
        if (a[p][0] == 1 && a[p][1] == 1 && a[p][2] == 0) {
            if (p + 1 > n || !is10(p + 1)) {
                is_third = 1;
                break;
            }
            p += 2;
        } else if (a[p][0] == 1 && a[p][1] == 1 && a[p][2] == 1 && a[p][3] == 0) {
            if (p + 2 > n || !is10(p + 1) || !is10(p + 2)) {
                is_third = 1;
                break;
            }
            p += 3;
        } else if (a[p][0] == 1 && a[p][1] == 1 && a[p][2] == 1 && a[p][3] == 1 && a[p][4] == 0) {
            if (p + 3 > n || !is10(p + 1) || !is10(p + 2) || !is10(p + 3)) {
                is_third = 1;
                break;
            }
            p += 4;
        } else {
            is_third = 1;
            break;
        }
    }

    if (is_third) {
        ++ans3;
    } else if (is_first) {
        ++ans1;
    } else {
        ++ans2;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> s;
        solve();
    }
    cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
    return 0;
}