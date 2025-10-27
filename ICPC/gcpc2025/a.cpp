#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int l, r;
    cin >> l >> r;
    int n = l + r;
    if (r == l - 1) cout << n <<'\n';
    else if (r == l || r == l - 2) cout << 3 * n / 2 << '\n';
    else cout << n * 2 << '\n';
    return 0;
}