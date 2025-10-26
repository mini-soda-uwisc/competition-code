#include <bits/stdc++.h>
using namespace std;

inline int ask(int x) {
    cout << x << '\n';
    fflush(stdout);
    int y;
    cin >> y;
    return y;
}

unordered_map<int, int> t;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);

    int len = 33333;

    int x = ask(len * 2 + 2);
    while (1) {
        if (x == -1) {
            cout << "0\n";
            for (int i = 2; i <= 2 * len; i += 2) {
                int p = 3 * (i / 2) - 1, q = 3 * (i / 2) - 2;
                if (t[p]) cout << q << '\n';
                else cout << p << '\n';

                cout << 3 * (i / 2) << '\n';
            }
            cout << "100000\n";
            return 0;
        }

        if (x == 0) {
            x = ask(1);
        } else if (x == 100000) {
            x = ask(len * 2 + 2);
        } else if (x % 3 == 0) {
            x = ask(2 * (x / 3) + 1);
        } else if (x % 3 == 1) {
            if (t[x + 1]) {
                x = ask(2 * (x + 2) / 3);
            } else {
                t[x] = 1;
                x = ask(-1);
            }
        } else {
            if (t[x - 1]) {
                x = ask(2 * (x + 1) / 3);
            } else {
                t[x] = 1;
                x = ask(-1);
            }
        }
    }
    return 0;
}