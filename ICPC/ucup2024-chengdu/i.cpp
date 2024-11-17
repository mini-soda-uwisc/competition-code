#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

struct Segment {
    vector<int> z;
    Segment(int n) : z(n * 4 + 10) {
        fill(z.begin(), z.end(), 0);
    }
void pushup(int rt) {
//    int left = z[rt * 2], right = z[rt * 2 + 1];
//    if (left != 0 && right != 0) {
//        z[rt] = gcd(left, right);
//    } else if (left == 0) {
//        z[rt] = right;
//    } else if (right == 0) {
//        z[rt] = left;
//    } else {
//        z[rt] = 0;
//    }
    z[rt] = __gcd(z[rt * 2], z[rt * 2 + 1]);
}
void modify(int l, int r, int rt, int pos, int val) {
    if (l == r) {
        z[rt] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        modify(l, mid, rt * 2, pos, val);
    } else {
        modify(mid + 1, r, rt * 2 + 1, pos, val);
    }
    pushup(rt);
}
};

int n, q;

int a[N], ans[N];

inline int getans(int x) {
    if (x == 0) {
        return n;
    }
    int cnt = 0;
    int s = sqrt(x);
    for (int i = 1; i <= s; ++i) {
        if (s % i == 0) cnt += 2;
    }
    if (s * s == x) cnt--;
    return cnt;
}

inline void solve() {
    cin >> n >> q;
    ans[0] = n;

    fill(a + 1, a + n + 1, 0);

    Segment seg(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            seg.modify(1, n, 1, i, i);
        }
    }

    cout << ans[seg.z[1]] << '\n';

    for (int i = 1; i <= q; ++i) {
        int pos, val;
        cin >> pos >> val;

        if (pos != n) seg.modify(1, n, 1, pos, 0);
        if (pos != 1) seg.modify(1, n, 1, pos - 1, 0);

        a[pos] = val;
        if (pos != n && a[pos] > a[pos + 1]) seg.modify(1, n, 1, pos, pos);
        if (pos != 1 && a[pos - 1] > a[pos]) seg.modify(1, n, 1, pos - 1, pos - 1);

        cout << ans[seg.z[1]] << '\n';
    }
}

signed main() {
    for (int i = 1; i <= 2e5; ++i) {
        for (int j = i; j <= 2e5; j += i) {
            ++ans[j];
        }
    }
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}