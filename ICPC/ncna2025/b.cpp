#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string ans, prev;
    int cnt = 1, ans_cnt = 0;
    cin >> prev;
    string s;
    while (cin >> s) {
        if (s != prev) {
            if (cnt > ans_cnt) {
                ans = prev;
                ans_cnt = cnt;
            }
            cnt = 1;
        } else {
            ++cnt;
        }
        prev = s;
    }

    if (cnt > ans_cnt) {
        ans = prev;
    }

    cout << ans << '\n';
}