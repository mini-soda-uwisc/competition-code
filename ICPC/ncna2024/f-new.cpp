//
// Created by EHPC6 on 11/9/2024.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;

void dfs(int step, const string& status) {
    if (step == m) {
        cout << "1\n";
        exit(0);
    }

    for (int i = 0; i < n - 1; ++i) {
        if (status[i] != 'R' && status[i + 1] != 'L') {
            string next_status = status;
            next_status[i] = 'R';
            next_status[i + 1] = 'L';
            dfs(step + 1, next_status);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    string s;
    cin >> s;
    dfs(0, s);
    cout << "0\n";
    return 0;
}