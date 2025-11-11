#include <bits/stdc++.h>
using namespace std;

// struct score {
//     int f1, f2;
// } s[15];
pair<int, int> s[15];
int tot, c, cnt, knots = 10;
int mi = INT_MAX;
int mx = INT_MIN;


int a[30];

inline int calc() {
    int strike = 0, spare = 0;
    int score = 0;
    int n = 0;
    for (int i = 1; i <= 10; ++i) {
        a[++n] = s[i].first;
        if (s[i].first != cnt) a[++n] = s[i].second;
    }

    for (int i = 1; i <= n; ++i) {
        score += a[i];
    }

    for (int i = 1; i <= n; ++i) {
        if (a[i] == knots) {
            if (i + 1 <= n) score += a[i + 1];
            if (i + 2 <= n) score += a[i + 2];
        }


    }
    return score;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> tot >> c;
    for (int i = 1; i <= 10; ++i) {
        cin >> s[i].first >> s[i].second;
    }

    cout << calc() <<'\n';

    // do {
    //     int p = calc();
    //     if (p == tot) {
    //         cout << tot << " Yes\n";
    //         return 0;
    //     }
    //     mi = min(mi, p);
    //     mx = max(mx, p);
    // } while (next_permutation(s + 1, s + 11));
    //
    // cout << tot << ' ' << mx << ' ' << mi << '\n';
    return 0;
}