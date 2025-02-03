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

const int N = (int)2e5 + 1, M = N * 10;

int n, m, q;

struct DSU{
    vector<int> node, size;

    DSU(){}
    DSU(int n){
        init(n);
    }

    void init(int n){
        node.resize(n);
        size.resize(n);

        for(int i = 0; i < n; i++){
            node[i] = i;
            size[i] = 1;
        }
    }

    int find(int x){
        return x == node[x] ? x : node[x] = find(node[x]);
    }

    void erase(int x){
        size[find(x)] -= 1;
        node[x] = x;
    }

    void relocate(int x, int y){ //can't be root
        int dx = find(x), dy = find(y);
        if(dx == dy){
            return;
        }
        node[x] = dy;
        size[dx] -= 1;
        size[dy] += 1;
    }

    int set(int x, int y){
        return find(x) == find(y);
    }

    int merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y){
            return 0;
        }

        size[x] += size[y];
        node[y] = x;
        return 1;
    }

    int heuristic_merge(int x, int y){
        x = find(x);
        y = find(y);
        if(size[x] < size[y]){
            swap(x, y);
        }
        return merge(x, y);
    }

    int get(int x){
        return size[find(x)];
    }
};

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
    array<int, 20> perm;
    Operation(){
        for(int i = 0; i < n; i++){
            perm[i] = i + 1;
        }
    }
     Operation(int p[20]){
        for(int i = 0; i < n; i++){
            perm[i] = p[i];
        }
    }

    Operation(const array<int, 20>& p_arr){
        perm = p_arr;
    }

    void modify(const Mark &v){

    }
};

Operation operator+(Operation a, Operation b){
    Operation c;
    for(int i = 0; i < n; i++){
        c.perm[i] = b.perm[a.perm[i] - 1];
    }
    return c;
}

void solve(){
    cin >> n >> m >> q;

    SegTree<Operation, Mark> tr(m + 1);
    unordered_map<int, int> mp;
    DSU dsu(n);

    for(int i = 0; i < q; i++){
        int y, x1, x2;
        cin >> y >> x1 >> x2;
        x1--, x2--;

        auto p = tr.query(y, y).perm;
        swap(p[x1], p[x2]);
        tr.update(y, p);
        p = tr.query(1, m).perm;

        for(int j = 0; j < n; j++){
            dsu.node[j] = j;
        }
        mp.clear();

        for(int j = 0; j < n; j++){
            dsu.heuristic_merge(j, p[j] - 1);
        }

        int qwq = 0;
        for(int j = 0; j < n; j++){
            int fa = dsu.find(j);
            if(mp[fa]){
                continue;
            }
            mp[fa] = 1;
            qwq++;
        }
        cout << n - qwq << '\n';
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