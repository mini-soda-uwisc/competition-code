#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string ans = "";
    for (int i = 1;; i++) {
        ans += to_string(i);
        if (ans.length() == s.length()) {
            if (ans != s) break;
            cout << i << '\n';
            return 0;
        }
        if (ans.length() > s.length()) break;
    }

    cout << "-1\n";
    return 0;
}