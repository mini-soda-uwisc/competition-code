#include <bits/stdc++.h>
using namespace std;

#define int long long

map<int, int> table;
int n, m, idx = 0, total = 0;
int unread[1010];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int sender;
        cin >> sender;
        if (table.find(sender) == table.end()) {
            table[sender] = ++idx;
            sender = idx;
            total -= i - 1;
        } else {
            sender = table[sender];
        }

        total += n - idx;
        int t = 0;
        for (int j = 1; j <= idx; ++j) {
            ++unread[j];
            t += unread[j];
        }
        t -= unread[sender];
        unread[sender] = 0;

        cout << total + t << '\n';
        // cout << "idx: " << idx << '\n';
        // cout << "unread\n";
        // for (int j = 1; j <= m; ++j) {
        //     cout << unread[j] << ' ';
        // }
        // cout << "\n";
    }
    return 0;
}