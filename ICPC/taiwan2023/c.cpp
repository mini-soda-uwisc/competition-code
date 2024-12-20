#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

#define int long long

int n, m;
int p[N], S[N], tot = 0;

#define root 1,n,1
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

int z[N << 2], out[N << 2], col[N << 2];
inline void pushup(int rt) {
    z[rt] = z[rt << 1] + z[rt << 1 | 1];
    out[rt] = out[rt << 1] + out[rt << 1 | 1];
}
inline void color(int l, int r, int rt) {
    z[rt] = (r - l + 1 - out[rt]) - z[rt];
    col[rt] ^= 1;
}
inline void pushdown(int l, int r, int rt) {
    if (col[rt]) {
        int mid = (l + r) >> 1;
        color(lson);
        color(rson);
        col[rt] = 0;
    }
}
void build(int l, int r, int rt) {
    if (l == r) {
        if (S[l] == -1) {
            z[rt] = 0;
            out[rt] = 1;
        } else {
            z[rt] = S[l];
            out[rt] = 0;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void modify(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) {
        color(l, r, rt);
        return;
    }
    pushdown(l, r, rt);
    int mid = (l + r) >> 1;
    if (L <= mid) modify(lson, L, R);
    if (R > mid) modify(rson, L, R);
    pushup(rt);
}
inline int query() {
    return z[1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> S[i] >> p[i];
        tot += p[i];
    }
    build(root);
    for (int i = 1; i <= m; ++i) {
//        cout << "tot: " << tot << '\n';
        string opt;
        cin >> opt;
        if (opt == "W") {
            int l, r;
            cin >> l >> r;
            ++l, ++r;
            modify(root, l, r);
        } else {
            int q;
            cin >> q;
            tot += query() * q;
//            cout << "Modify: \n";
//            cout << "query: " << query() << '\n';
//            cout << "tot: " << tot << '\n';
        }
    }

    cout << tot << '\n';
    return 0;
}