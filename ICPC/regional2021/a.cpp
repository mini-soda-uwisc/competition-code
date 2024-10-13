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
    int add;

    Mark(int p = 0){
        add = p;
    }

    void modify(const Mark &v){
        if(v.add){
            add ^= v.add;
        }
    }
};

struct Operation {
    int bits[64];

    Operation(int p = -1){
        for(int i = 0; i < 64; i++){
            bits[i] = 0;
        }

        if(p >= 0){
            bits[p]++;
        }
    }

    void modify(const Mark &v){
        if(v.add){
            int a[64];
            for(int i = 0; i < 64; i++){
                a[i] = 0;
            } 
            for(int i = 0; i < 64; i++){
                // if(bits[i] > 0){
                //     cout << (i ^ v.add) << " " << i << " " << bits[i] << " " << endl;
                // }
                a[i ^ v.add] += bits[i];
                bits[i] = 0;
            }
            for(int i = 0; i < 64; i++){
                bits[i] = a[i];
            }
        }
    }
};

Operation operator+(Operation a, Operation b){
    Operation c;
    for(int i = 0; i < 64; i++){
        c.bits[i] = a.bits[i] + b.bits[i];
    }
    return c;
}

void solve(){
    string s;
    cin >> s;

    int n;
    cin >> n;

    SegTree<Operation, Mark> tr(n + 1);
    vector<int> t(s.length() + 2);

    for(int i = 1; i <= s.length(); i++){
        t[i] = t[i - 1] ^ (1 << s[i - 1] - 'a');
        tr.update(i + 1, t[i]);
    }
    tr.update(1, 0);

    // for(int i = 0; i <= s.length(); i++){
    //     cout << t[i] << " ";
    // } cout << endl;

    for(int i = 0; i < n; i++){
        int op;
        cin >> op;

        if(op == 1){
            int l, r;
            cin >> l >> r;

            auto p = tr.query(l, r + 1);
            ll qwq = 0;

            for(int j = 0; j < 64; j++){
                // cout << p.bits[j] << " ";
                qwq += p.bits[j] * 1ll * (p.bits[j] - 1) / 2;
            } 
            // cout << endl;
            cout << qwq << endl;
        }
        else{
            int x;
            char c;
            cin >> x >> c;

            char ch = s[x - 1];
            int qwq = (1 << ch - 'a') ^ (1 << c - 'a');

            s[x - 1] = c;
            tr.range_update(x + 1, n + 1, qwq);
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
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
