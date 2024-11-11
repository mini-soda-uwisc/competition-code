#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n;
    cin >> n;

    map<int, string> mp;
    mp[1] = "Sunday";
    mp[2] = "Monday";
    mp[3] = "Tuesday";
    mp[4] = "Wednesday";
    mp[5] = "Thursday";
    mp[6] = "Friday";
    mp[7] = "Saturday";

    long double wk, wd, exp, sum = 0, ep = 1;
    cin >> wk >> wd >> exp;

    wk /= 100;
    wd /= 100;
    exp /= 100;

    int cnt = 0, cnt_index = n;
    for(int i = n - 1; sum < exp; i--) {
        if (i == 0) i = 7;
        int cur = i;
        if(cur == 1 || cur == 7) {
            sum += wd * ep;
        }
        else {
            sum += wk * ep;
        }
        ep *= (1 - ((cur == 1 || cur == 7) ? wd : wk));
        cnt++;
        --cnt_index;
        if (cnt_index == 0) cnt_index = 7;
    }
    // cout << cnt << endl;
    cout << "Try to leave on " << mp[cnt_index] + ", " << cnt << " " << (cnt == 1 ? "day " : "days ") << "before the " << mp[n] << " meeting.";
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