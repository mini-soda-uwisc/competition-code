#include <bits/stdc++.h>
using namespace std;

string s, t;

int n, m;

int isvowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

void to_lower(string& s) {
    for (char &c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
}

int main() {
    cin >> s >> t;
    s += "#";
    t += "#";

    to_lower(s);
    to_lower(t);

    n = s.size();
    m = t.size();

    int p = 0;
    for (int i = 0; i < n; ++i, ++p) {
        while (p < m && t[p] != s[i]) {
            if (isvowel(t[p])) ++p;
            else {
                cout << "Different\n";
                return 0;
            }
        }
    }

    cout << "Same\n";
    return 0;
}