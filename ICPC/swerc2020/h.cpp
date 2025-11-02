#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

inline void readPattern(vector<pair<char, int>>& a) {
    string s;
    getline(cin, s);
    s += ' ';
    pair<char, int> cur;
    int x = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') {
            cur.second = x;
            a.emplace_back(cur);
            cur = pair<char, int>();
            x = 0;
        } else if (s[i] == '+' || s[i] == '-') {
            cur.first = s[i];
        } else {
            x = x * 10 + s[i] - '0';
        }
    }//9 0 6 0 8 3 7 0 9 8
}

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

template<class Operation>
struct SegTree{
    const ll n, len;
    ll pos, root;

    struct Node {
        ll l, r;
        Operation op;
    };

    vector<Node> f;

    SegTree(ll n, ll len) : n(n), len(len), f(4 << __lg(n)), pos(0), root(0){}

    void pushup(ll u) {
        f[u].op = f[f[u].l].op + f[f[u].r].op;
    }

    void update(ll &u, ll l, ll r, ll x, const Operation &v){
        if(!u){
            u = ++pos;
            f[u].op = {};
            f[u].l = f[u].r = 0;
        }
        if(l == r){
            f[u].op = v; //也许会变
            return;
        }
        ll m = (l + r) >> 1;
        if(x <= m) {
            update(f[u].l, l, m, x, v);
        }
        else{
            update(f[u].r, m + 1, r, x, v);
        }

        pushup(u);
    }

    void update(ll &root, ll u, const Operation &v){
        update(root, 0, len - 1, u, v);
    }

    void modify(ll u, ll v){
        //值合并操作

    }

    ll merge(ll u, ll v, ll l, ll r){
        if(!u){
            return v;
        }
        if(!v){
            return u;
        }
        if(l == r){
            modify(u, v);
            return u;
        }

        ll m = (l + r) >> 1;
        f[u].l = merge(f[u].l, f[v].l, l, m);
        f[u].r = merge(f[u].r, f[v].r, m + 1, r);
        pushup(u);
        return u;
    }

    Operation query(ll u, ll l, ll r, ll x, ll y){
        if(!u){
            return {};
        }
        if(x <= l && r <= y) {
            return f[u].op;
        }

        ll m = (l + r) >> 1;
        Operation cur;
        if(x <= m) {
            cur = query(f[u].l, l, m, x, y);
        }
        if(y > m) {
            cur = cur + query(f[u].r, m + 1, r, x, y);
        }
        return cur;
    }

    Operation query(ll &root, ll l, ll r){
        return query(root, 0, len - 1, l, r);
    }

    // Operation kth(ll u, ll l, ll r, ll t){
    //     if(!u){
    //         return {};
    //     }
    //     if(l == r){
    //         return f[u].op;
    //     }

    //     int m = l + r >> 1;

    //     if(f[f[u].l].op.cnt >= t){
    //         return kth(f[u].l, l, m, t);
    //     }
    //     else{
    //         return kth(f[u].r, m + 1, r, t - f[f[u].l].op.cnt);
    //     }
    // }

    // Operation kth(ll &root, ll t){
    //     return kth(root, 1, len, t);
    // }
};

//预处理根

struct Operation{
    int sum = 0;
    Operation(int p = 0){
        sum = p;
    }
};

Operation operator+(Operation a, Operation b){
    return {a.sum + b.sum};
}
char trashbin[1];
void solve(){
    int n;
    cin >> n;
    cin.getline(trashbin, 1);

    vector<vector<pair<char, int>>> q;
    for (int i = 0; i < n; ++i) {
        vector<pair<char, int>> a;
        readPattern(a);
        q.pb(a);
    }

    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    SegTree<Operation> tr(n, n);
    ll rt[n + 1];
    for (int i = 0; i <= n; i++) {
        rt[i] = i;
    }

    tr.pos = n - 1;

    for (int i = 0; i < q.size(); i++){
        for (auto [k, v] : q[i]) {
            if (k == '-') {
                tr.update(rt[i], v, 0);
            }
            else {
                tr.update(rt[i], v, 1);
            }
        }

        if (i) {
            rt[i] = tr.merge(rt[i], rt[i - 1], 0, n - 1);
        }
    }

    ll qwq = 0;
    for (int i = 0; i < q.size(); i++) {
        qwq = (qwq + tr.query(rt[d[i]], qwq, n - 1).sum) % n;
    }

    /*
    *0 9 0
    0 0 2
    2 6 6
    8 0 0
    8 8 2
    0 3 5
    5 7 4
    9 0 0
    9 9 0
    9 8 1
    */
    cout << qwq << endl;
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
