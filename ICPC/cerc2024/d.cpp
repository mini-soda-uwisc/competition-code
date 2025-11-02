#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        string s = to_string(n);
        sort(s.begin(), s.end());

        int cnt = 0;
        for (int i = 2; i <= 9; i++) {
            if (n % i == 0) {
                string t = to_string(n / i);
                sort(t.begin(), t.end());
                cnt += (s.size() == t.size() && t == s);
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}