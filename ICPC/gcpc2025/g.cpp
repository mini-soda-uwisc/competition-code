#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<char> s1, s2, s3, s4;
    for (char i = 'a'; i <= 'z'; ++i) s1.emplace_back(i);
    for (char i = '0'; i <= '9'; ++i) s2.emplace_back(i);
    for (char i = 'A'; i <= 'Z'; ++i) s3.emplace_back(i);
    for (char i = 33; i <= 47; ++i) s4.emplace_back(i);
    for (char i = 58; i <= 64; ++i) s4.emplace_back(i);
    for (char i = 91; i <= 96; ++i) s4.emplace_back(i);

    vector<string> ans;

    for (char a : s1) for (char b : s2) for (char c : s3) for (char d : s4) {
        if (ans.size() == n) break;
        string s;
        for (int i = 1; i <= 3; ++i) {
            s.push_back(a);
            s.push_back(b);
            s.push_back(c);
            s.push_back(d);
        }
        ans.emplace_back(s);
    }

    for (string& s : ans) {
        cout << s << '\n';
    }
    return 0;
}