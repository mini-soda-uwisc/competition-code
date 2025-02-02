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

const int N = (int)2e6 + 1, M = N * 2;

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
    int sum = 0;
    Operation(int p = 0){
        sum = p;
    }

    void modify(const Mark &v){

    }
};

Operation operator+(Operation a, Operation b){
    return {a.sum + b.sum};
}

void solve(){
    int n;
    cin >> n;

    SegTree<Operation, Mark> tr(N);

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    map<int, int> mp;
    int max = n;
    for(int i = 0; i < n; i++){
        tr.update(a[i], 1);
        mp[i + 1] = a[i];
        max = chmax(max, a[i] + 1);
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;

        int pos = mp[x];
        int l = pos + 1, r = max + 1;
        while(l < r){
            int mid = l + r >> 1;
            if(tr.query(pos, mid).sum < (mid - pos + 1)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }

        if(tr.query(l, l).sum == 1){
            l++;
        }
        mp[x] = l;
        tr.update(pos, 0);
        tr.update(l, 1);
        max = chmax(max, l);
        cout << l << endl;
    }
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