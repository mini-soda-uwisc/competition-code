#include <bits/stdc++.h>
using namespace std;

auto read() {
    string str;
    getline(cin, str);

    int n = str.length();
    map<int, int> parents;

    int cur_number = 0;
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        char c = str[i];
        if (isdigit(c)) {
            cur_number = cur_number * 10 + c - '0';
        } else if (c == '(') {
            s.push(cur_number);
            cur_number = 0;
        } else if (c == ')') {
            int parent = s.top();
            parents[cur_number] = parent;
            s.pop();
            cur_number = parent;
        }
    }

    parents[cur_number] = -1;
    return parents;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    auto x = read();
    auto y = read();
    cout << (x == y ? "Yes" : "No") << '\n';
    return 0;
}