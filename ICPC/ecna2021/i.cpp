#include <bits/stdc++.h>
using namespace std;

int n, m, p, u;
int a[150], b[150], c[150], d[150];
int f[150], g[150];
map<int, int> t1, t2;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    cin >> p >> u;
    for (int i = 1; i <= p; ++i) cin >> c[i];
    for (int i = 1; i <= u; ++i) cin >> d[i];

    int front_len = 0, last_len = 0;
    for (int i1 = 1, i2 = 1; i1 <= n && i2 <= p; ++i2) {
        while (i1 <= n && a[i1] != c[i2]) ++i1;
        if (a[i1] == c[i2]) ++front_len;
    }
    for (int i1 = m, i2 = u; i1 >= 1 && i2 >= 1; --i2) {
        while (i1 >= 1 && b[i1] != d[i2]) --i1;
        if (b[i1] == d[i2]) ++last_len;
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++i) t1[a[i]] = 1;
    for (int i = 1; i <= m; ++i) t2[b[i]] = 1;

    for (int i = 1; i <= p; ++i) if (t2[c[i]]) ++cnt1;
    for (int i = 1; i <= u; ++i) if (t1[d[i]]) ++cnt2;

//    cout << "front_len: " << front_len << '\n';
//    cout << "last_len: " << last_len << '\n';
//    cout << "cnt1: " << cnt1 << '\n';
//    cout << "cnt2: " << cnt2 << '\n';
    int ans = cnt1 + cnt2 + (p + u - cnt1 - cnt2 - front_len - last_len) * 2;
    cout << ans << '\n';
    return 0;
}