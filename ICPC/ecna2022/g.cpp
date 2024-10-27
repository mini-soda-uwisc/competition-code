#include <bits/stdc++.h>
using namespace std;

string cur, target;

int main() {
    cin >> cur >> target;

    for (int i = 1; i <= 2000; ++i) {
        if (cur == target) {
            cout << i << '\n';
            return 0;
        }

        map<int, int> cnt;
        for (int j = 0; j < cur.size(); ++j) {
            ++cnt[cur[j] - '0'];
        }

        string nxt = "";
        for (int j = 0; j <= 9; ++j) {
            if (cnt[j] == 0) continue;
            nxt += to_string(cnt[j]);
            nxt += to_string(j);
        }

        cur = nxt;
    }
    cout << "Does not appear\n";
    return 0;
}