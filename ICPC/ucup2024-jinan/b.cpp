#include <bits/stdc++.h>
using namespace std;

inline int calc(int num[]) {
    int ans = 0;
    for (int i = 1; i <= 4; ++i) {
        ans += num[i] / 5;
    }
}

inline void solve() {
    int n;
    cin >> n;
    int num[10];
    int star, moon, sun, world, lovers, death;
    for (int i = 1; i <= n; ++i) {
        string str;
        cin >> str;
        if (str[1] == 'H') ++num[1];
        else if (str[1] == 'D') ++num[2];
        else if (str[1] == 'S') ++num[3];
        else ++num[4];
    }
    cin >> star >> moon >> sun >> world >> lovers >> death;

    int ans = calc(num);
    for (int i = 1; i <= 4; ++i) {
        num[i] %= 5;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}