#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define int long long
#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 1e9 + 7;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

int n, q;
const int N = (int)5e5 + 10, M = N * 2;

inline int fpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

int base = 131;
int a[N];
int p[N], sum[N];

class Segment1 {
public:
    int z[N << 2], col[N << 2], maxn[N << 2];
    void pushup(int l, int r, int rt) {
        int mid = (l + r) >> 1;
        z[rt] = (z[rt << 1] * p[r - mid] % mod + z[rt << 1 | 1]) % mod;
        maxn[rt] = max(maxn[rt << 1], maxn[rt << 1 | 1]);
    }
    void color(int l, int r, int rt, int v) {
        col[rt] = (col[rt] + v) % mod;
        z[rt] = (z[rt] + v * sum[r - l] % mod) % mod;
        maxn[rt] = (maxn[rt] + v) % mod;
    }
    void pushdown(int l, int r, int rt) {
        if(col[rt]) {
            int mid = (l + r) >> 1;
            color(l, mid, rt << 1, col[rt]);
            color(mid + 1, r, rt << 1 | 1, col[rt]);
            col[rt] = 0;
        }
    }
    void build(int l, int r, int rt) {
        if(l == r) {
            z[rt] = a[l] % mod;
            maxn[rt] = a[l] % mod;
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, rt << 1);
        build(mid + 1, r, rt << 1 | 1);
        pushup(l, r, rt);
    }
    void modify1(int l, int r, int rt, int L, int R) {
        if(L <= l && r <= R) {
            color(l, r, rt, 1);
            return;
        }
        pushdown(l, r, rt);
        int mid = (l + r) >> 1;
        if(L <= mid) modify1(l, mid, rt << 1, L, R);
        if(R > mid) modify1(mid + 1, r, rt << 1 | 1, L, R);
        pushup(l, r, rt);
    }
    void modify2(int l, int r, int rt) {
        if (maxn[rt] < 65536) return;
        if(l == r) {
            z[rt] -= 65536;
            maxn[rt] -= 65536;
            return;
        }
        pushdown(l, r, rt);
        int mid = (l + r) >> 1;
        if (maxn[rt << 1] >= 65536) modify2(l, mid, rt << 1);
        if (maxn[rt << 1 | 1] >= 65536) modify2(mid + 1, r, rt << 1 | 1);
        pushup(l, r, rt);
    }
    int query(int l, int r, int rt, int L, int R) {
        if(L <= l && r <= R) return z[rt];
        pushdown(l, r, rt);
        int mid = (l + r) >> 1, res = 0;
        if(L <= mid) res = query(l, mid, rt << 1, L, R) % mod;
        if(R > mid) res = (res * p[max(0ll, min(r, R)) - mid] % mod + query(mid + 1, r, rt << 1 | 1, L, R)) % mod;
        return res;
    }
    int printQuery(int l, int r, int rt, int k) {
        if (l == r) {
            return maxn[rt];
        }
        pushdown(l, r, rt);
        int mid = (l + r) >> 1;
        if (k <= mid) return printQuery(l, mid, rt << 1, k);
        if (mid <  k) return printQuery(mid + 1, r, rt << 1 | 1, k);
    }
    void print() {
        for (int i = 1; i <= n; ++i) {
            cout << printQuery(1, n, 1, i) << ' ';
        }
        cout << '\n';
    }
} tree;


inline void solve(){
    cin >> n >> q;
    p[0] = sum[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = (p[i - 1] * base) % mod;
        sum[i] = (sum[i - 1] + p[i]) % mod;
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    tree.build(1, n, 1);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            tree.modify1(1, n, 1, l, r);
            tree.modify2(1, n, 1);
        } else {
            int x, y, L;
            cin >> x >> y >> L;
            int l1 = x, l2 = y;
            int r1 = x + L - 1, r2 = y + L - 1;
            int ans1 = tree.query(1, n, 1, l1, r1);
            int ans2 = tree.query(1, n, 1, l2, r2);
//            cout << "ans1: " << ans1 << ", ans2: " << ans2 << '\n';
            if (ans1 == ans2) cout << "yes\n";
            else cout << "no\n";
        }
//        tree.print();
    }
}

signed main() {
//     freopen("g.in", "r", stdin);
//     freopen("g.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
/*
5 6
1 2 1 2 1
2 1 2 2
2 1 3 3
1 1 1
1 3 5
2 1 2 4
2 1 2 2
 */