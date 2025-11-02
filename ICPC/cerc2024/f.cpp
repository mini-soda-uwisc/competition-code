#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

template<class Operation, class Mark>
struct SegTree{
    const int n;
    vector<Operation> op;
    vector<Mark> mrk;

    SegTree(int n) : n(n), op(4 << __lg(n)), mrk(4 << __lg(n)){
        function<void(int, int, int)> build = [&](int u, int l, int r){
            op[u] = Operation();
            if(l == r) return;
            int mid = l + r >> 1;
            build(u << 1, l, mid);
            build(u << 1 | 1, mid + 1, r);
            pushup(u);
        };

        build(1, 1, n);
    }

    void pushup(int u){
        op[u] = op[u << 1] + op[u << 1 | 1];
    }

    void modify(int u, const Mark &mk){
        op[u].modify(mk);
        mrk[u].modify(mk);
    }

    void pushdown(int u){
        modify(u << 1, mrk[u]);
        modify(u << 1 | 1, mrk[u]);
        mrk[u] = Mark();
    }

    void update(int u, int l, int r, int x, const Operation &v){
        if(l == r){
            op[u] = v;
            return;
        }
        int m = (l + r) >> 1;
        pushdown(u);

        if(x <= m){
            update(u << 1, l, m, x, v);
        }
        else{
            update(u << 1 | 1, m + 1, r, x, v);
        }
        pushup(u);
    }

    void update(int u, const Operation &v){
        update(1, 1, n, u, v);
    }

    Operation query(int u, int l, int r, int x, int y){
        if(x <= l && r <= y) {
            return op[u];
        }

        int m = (l + r) >> 1;
        Operation cur;
        pushdown(u);
        if(x <= m){
            cur = query(u << 1, l, m, x, y);
        }
        if(y > m){
            cur = cur + query(u << 1 | 1, m + 1, r, x, y);
        }
        return cur;
    }

    Operation query(int l, int r){
        return query(1, 1, n, l, r);
    }

    void range_update(int u, int l, int r, int x, int y, const Mark &v){
        if(l >= x && r <= y){
            modify(u, v);
            return;
        }

        int m = (l + r) >> 1;
        pushdown(u);
        if(x <= m){
            range_update(u << 1, l, m, x, y, v);
        }
        if(y > m){
            range_update(u << 1 | 1, m + 1, r, x, y, v);
        }
        pushup(u);
    }

    void range_update(int l, int r, const Mark &v){
        return range_update(1, 1, n, l, r, v);
    }
};

struct Mark{
    int add;
    Mark(int p = 0) {
        add = p;
    }

    void modify(const Mark &v){
        add += v.add;
    }
};

struct Operation{
    int l, r, lh, rh, max, sum;
    Operation(int _l = 0, int _r = 0, int _lh = 0, int _rh = 0, int _max = 0) {
        l = _l;
        r = _r;
        lh = _lh;
        rh = _rh;
        max = _max;
        sum = 0;
    }

    void modify(const Mark &v){
        if (v.add) {
            lh = rh = max = v.add;
            sum = 0;
        }
    }
};

Operation operator+(Operation a, Operation b){
    Operation c;
    c.sum = a.sum + b.sum;
    if (a.r != b.l || (a.max == b.max && a.rh != b.lh)) {
        c.sum++;
    }
    c.max = chmax(a.max, b.max);
    c.l = a.l;
    c.r = b.r;
    c.lh = a.lh;
    c.rh = b.rh;
    return c;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> a;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        int l, r, x;
        cin >> l >> r >> x;

        a.push_back({l, r, x});
        b.push_back(l);
        b.push_back(r);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()));


}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
