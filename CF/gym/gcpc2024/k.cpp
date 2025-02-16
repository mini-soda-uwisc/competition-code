#include <bits/stdc++.h>
using namespace std;

string s, t;

bool getnum(char c) {
    bool flag = false;
    for (char p : t) {
        if (p == c) flag = !flag;
    }

    return flag;
}

void horizontal() {
    string tmp;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == 'q') tmp.push_back('p');
        if (s[i] == 'p') tmp.push_back('q');
        if (s[i] == 'b') tmp.push_back('d');
        if (s[i] == 'd') tmp.push_back('b');
    }
    s = tmp;
}

void vertical() {
    string tmp;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'q') tmp.push_back('d');
        if (s[i] == 'p') tmp.push_back('b');
        if (s[i] == 'b') tmp.push_back('p');
        if (s[i] == 'd') tmp.push_back('q');
    }
    s = tmp;
}

void rotation() {
    string tmp;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == 'q') tmp.push_back('b');
        if (s[i] == 'p') tmp.push_back('d');
        if (s[i] == 'b') tmp.push_back('q');
        if (s[i] == 'd') tmp.push_back('p');
    }
    s = tmp;
}

int main() {
    cin >> s >> t;
    if (getnum('h')) horizontal();
    if (getnum('v')) vertical();
    if (getnum('r')) rotation();

    cout << s << '\n';
    return 0;
}