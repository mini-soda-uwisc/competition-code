#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
int qwq = 0, t = 0;

void dfs(string pre, string s){


    for(int i = 1; i < s.size(); i++){
        char l = s[i - 1], r = s[i];
        string t = s;
        if(l == 'F' && r == 'R') {
            s[i - 1] = 'R';
            s[i] = 'F';
            dfs(t, s);
            s[i - 1] = 'F';
            s[i] = 'R';
        }
        if(l == 'L' && r == 'F') {
            s[i - 1] = 'F';
            s[i] = 'R';
            dfs(t, s);
            s[i - 1] = 'L';
            s[i] = 'F';
        }
        if(l == 'L' && r == 'R') {
            s[i - 1] = 'F';
            s[i] = 'F';
            dfs(t, s);
            s[i - 1] = 'L';
            s[i] = 'R';
        }
        if(l == 'F' && r == 'F') {
            s[i - 1] = 'L';
            s[i] = 'R';
            dfs(t, s);
            s[i - 1] = 'F';
            s[i] = 'F';
        }
    }
}

inline void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    dfs("", s);
    cout << (qwq >= m) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}