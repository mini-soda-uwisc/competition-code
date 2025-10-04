#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i <= t; ++i) {
        int ok = 0;
        if (t - i <= 6 * 60) ok = 1;
        if (t - i <= 9 * 60 && i >= 30) ok = 1;
        if (t - i <= 10 * 60 && i >= 45) ok = 1;
        if (ok) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}
