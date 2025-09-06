#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
pair<int, int> a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    if (n % 2 != 0) {
        cout << "impossible\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a + 1, a + n + 1);
    int x = a[1].first + a[n].first, y = a[1].second + a[n].second;
    for (int i = 1; i <= n; ++i) {
        int j = n - i + 1;
        if (a[i].first + a[j].first != x || a[i].second + a[j].second != y) {
            cout << "impossible\n";
            return 0;
        }
    }

    cout << "possible\n";
    return 0;
}