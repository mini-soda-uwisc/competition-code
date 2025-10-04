#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ld = long double;
using ll = long long;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b){
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b){
    return a > b ? b : a;
}

const int N = (int)1e6 + 1, M = N * 10;

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

    void pushdown(int u) {
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
    int add = 0;
    Mark(int p = 0) {
        add = p;
    }

    void modify(const Mark &v){
        if (v.add) {
            add = 1;
        }
    }
};

struct Operation {
    int sum = 0;
    Operation(int p = 0) {
        sum = p;
    }

    void modify(const Mark &v){
        if (v.add) {
            sum = 0;
        }
    }
};

Operation operator+(Operation a, Operation b){
    return {a.sum + b.sum};
}

void solve() {
    ll n, b, r, w;
    cin >> n >> b >> r >> w;

    int d[b + 1], t[n + 1];
    ll ps[b + 1];
    ps[0] = 0;

    for (int i = 1; i <= b; i++) {
        cin >> d[i];
        ps[i] = ps[i - 1] + d[i];
    }

    int max = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        max = chmax(max, t[i]);
    }

    SegTree<Operation, Mark> tr(max + 2), tr2(max + 2);

    auto check = [&](ll x) -> bool {
        ll T = 0, bus = 1;
        int D = 0;
        tr.range_update(1, max + 1, 1);
        tr2.range_update(1, max + 1, 1);

        unordered_map<int, int> mp;

        for (int i = 1; i <= n; i++) {
            int pre = (t[i] == 1 ? 0 : tr.query(1, t[i] - 1).sum);
            int suf = (t[i] == max ? 0 : tr2.query(t[i] + 1, max).sum);

            if (mp[t[i]]) {
                suf = 0;
            }
            D = chmax(D, t[i]);

            if (T + (suf + pre + 1) * w * 2 + ps[D] <= x) {
                T += (suf + pre + 1) * w * 2;
            }
            else {
                mp.clear();
                T = bus * r + 2 * w;
                D = t[i];
                bus++;

                if (T + ps[D] > x) {
                    return 0;
                }

                tr.range_update(1, max + 1, 1);
                tr2.range_update(1, max + 1, 1);
            }

            tr2.update(t[i], tr2.query(t[i], t[i]).sum + 1);
            tr.update(t[i], 1);
            mp[t[i]] = 1;
        }
        return 1;
    };

    ll L = 0, R = (ll)1e18;
    while (L < R) {
        ll mid = L + R >> 1;
        if (check(mid)) {
            R = mid;
        }
        else {
            L = mid + 1;
        }
    }

    cout << L << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}