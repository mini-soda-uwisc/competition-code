#include <bits/stdc++.h>
using namespace std;

int n, m;
string guesses[20], status[20];

int check(string &x) {
    for (int i = 1; i <= n; ++i) {
        map<char, int> remains_cnt;
        map<char, int> limited;
        for (char c = 'A'; c <= 'Z'; c += 1) {
            remains_cnt[c] = 0;
            limited[c] = 0;
        }

        string &guess = guesses[i];
        string &state = status[i];
        for (int k = 0; k < 5; ++k) {
            if (state[k] == 'G') {
                if (guess[k] != x[k]) return 0;
            } else if (state[k] == '-') {
                if (guess[k] == x[k]) return 0;
                limited[guess[k]] = 1;
            } else {
                if (guess[k] == x[k]) return 0;
                ++remains_cnt[guess[k]];
            }
        }
        map<char, int> cnt;
        for (char c = 'A'; c <= 'Z'; c += 1) {
            cnt[c] = 0;
        }
        for (int k = 0; k < 5; ++k) {
            if (state[k] == 'G') continue;
            ++cnt[x[k]];
        }

        for (char c = 'A'; c <= 'Z'; c += 1) {
            if (limited[c]) {
                if (cnt[c] != remains_cnt[c]) return 0;
            } else {
                if (cnt[c] < remains_cnt[c]) return 0;
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> guesses[i] >> status[i];
    }

    for (int i = 1; i <= m; ++i) {
        string x;
        cin >> x;
        if (check(x)) {
            cout << x << '\n';
        }
    }
    return 0;
}
/*
1 3
BAAAA YG---
AABCD
BACDE
CABDE

4 5
FRUIT -G--Y
NUTTY --Y--
ROOTS Y--YG
SEEDS -YG-G
TREES

*/