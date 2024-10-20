#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

#define int long long

int n;
int a[N];
int beg, ed;

inline int check(int x) {
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= x) {
            beg = i;
            break;
        }
    }

    for (int i = beg + 1; i <= n; ++i) {
        if (a[i] < x) {
            ed = i - 1;
            break;
        }
    }


}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int l = INT_MAX, r = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        l = min(l, a[i]);
        r = max(r, a[i]);
    }

    // binary search
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }

    return 0;
}