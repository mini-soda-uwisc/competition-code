#include <bits/stdc++.h>
using namespace std;

string opt, s;
int n;

inline void encode() {
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            for (int j = i; j >= 0; --j) {
                s[j] = '2';
            }
            break;
        }
    }
    cout << s << '\n';
}

inline void decode() {
    int cnt = 0;
    int p = 0;
    for (int i = n - 1; i > 0; --i) {
        if (s[i] == '2' && s[i - 1] != '2') {
            p = i;
            break;
        }
    }

    string ans = "";
    for (int i = p; i < n; ++i) {
        ans.push_back(s[i]);
    }
    for (int i = 0; i < p; ++i) {
        ans.push_back(s[i]);
    }
    for (int i = 0; i < n; ++i) {
        // cout << "i: " << i << ", ansi: " << ans[i] << '\n';
        if (ans[i] == '2') {
            if (ans[i + 1] != '2') {
                ans[i] = '1';
                break;
            }
            ans[i] = '0';
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> opt >> n >> s;
    if (opt == "Encode") encode();
    else decode();
    return 0;
}