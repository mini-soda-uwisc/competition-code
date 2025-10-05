#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template <typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)2e5 + 1, M = N * 2;

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
        // pushdown(u);

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
        // pushdown(u);
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
        // pushdown(u);
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
    void modify(const Mark &v){

    }
};

struct Operation {
    int max = 0;
    Operation(int p = 0) {
        max = p;
    }
    void modify(const Mark &v){

    }
};

Operation operator+(Operation a, Operation b){
    return chmax(a.max, b.max);
}

struct P {
    int l, r, id;
};

int cnt[N], a[N], ans[N], len;
vector<int> fac[N];
P q[N];

int get(int i){
    return i / len;
}

bool cmp(const P& a, const P& b){
    int al = get(a.l), bl = get(b.l);
    int ar = get(a.r), br = get(b.r);

    if(al != bl){
        return al < bl;
    }
    return al & 1 ? ar < br : ar > br;
}

void solve() {
    int n, max = 0;
    cin >> n;

    len = sqrt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                fac[i].push_back(j);
                if (a[i] / j != j) {
                    fac[i].push_back(a[i] / j);
                }
            }
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        q[i] = {l - 1, r - 1, i};
    }

    sort(q, q + Q, cmp);

    SegTree<Operation, Mark> tr(N);

    auto add = [&](int x) -> void {
        for (auto& z : fac[x]) {
            cnt[z]++;
            if (cnt[z] >= 2) {
                max = chmax(max, z);
            }
        }
    };

    auto del = [&](int x) -> void {
        for (auto& z : fac[x]) {
            cnt[z]--;
        }

        while (cnt[max] < 2) {
            max--;
        }
    };

    for(int k = 0, i = 0, j = 1; k < Q; k++){
        int id = q[k].id, l = q[k].l, r = q[k].r;
        while(i < r) {
            add(++i);
        }
        while(i > r) {
            del(i--);
        }
        while(j < l) {
            del(j++);
        }
        while(j > l) {
            add(--j);
        }
        ans[id] = max;
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
