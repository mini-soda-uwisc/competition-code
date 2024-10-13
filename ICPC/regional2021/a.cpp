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
    void modify(const Mark &v){

    }
};

struct Operation {
    int a[6];
    Operation(int p = 114514){
        for(int i = 0; i < 6; i++){
            a[i] = 0;
        }
        if(p != 114514) {
            a[p]++;
        }
    }

    void modify(const Mark &v){

    }
};

Operation operator+(Operation a, Operation b){
    Operation c;
    for(int i = 0; i < 6; i++){
        c.a[i] += a.a[i] + b.a[i];
    }
    return c;
}

template <typename T>
struct Binom {
public:
    vector<Z<T>> ft;
    vector<Z<T>> ift;

    Binom(int n) : ft(n + 1), ift(n + 1) {
        ft[0] = Z<T>(1);

        for (int i = 1; i <= n; i++) {
            ft[i] = ft[i - 1] * Z<T>(i);
        }
        ift[n] = Z<T>::inverse(ft[n]);

        for (int i = n - 1; i >= 0; i--) {
            ift[i] = ift[i + 1] * Z<T>(i + 1);
        }
        ift[0] = ift[1];
    }

    Z<T> operator()(int n, int r) const {
        if (n < 0 || n >= ft.size() || r < 0 || r > n) return Z<T>(0);
        return ft[n] * ift[n - r] * ift[r];
    }

    Z<T> comb(int n, int k) const {
        if (k == 0) return Z<T>(1);
        return (*this)(n, k);
    }

    Z<T> sumComb(int n) const {
        return Z<T>::pow(Z<T>(2), n) - Z<T>(2);
    }

    Z<T> perm(int n, int k) const {
        if (k == 0) return Z<T>(1);
        return (*this)(n, k) * ft[k];
    }

    Z<T> fact(int n) const {
        if (n == 0) return Z<T>(1);
        return ft[n];
    }

    Z<T> cata(int n) const {
        return (*this)(2 * n, n) / Z<T>(n + 1);
    }
};

void solve(){
    string s;
    cin >> s;

    int n;
    cin >> n;

    SegTree<Operation, Mark> tr(n + 1);
    for(int i = 1; i <= n; i++){
        tr.update(i, {s[i] - 'a'});
    }
    for(int i = 0; i < n; i++){
        int op;
        cin >> op;

        if(op == 1){
            int l, r;
            cin >> l >> r;
            auto p = tr.query(l, r);


        }
        else{
            int id;
            char c;
            cin >> id >> c;
            tr.update(id, {c - 'a'});
        }
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}