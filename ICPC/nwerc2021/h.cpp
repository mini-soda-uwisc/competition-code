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

struct DSU{
    vector<int> node, size;
    vector<int> l, r;
    vector<ll> val;
 
    DSU(){}
    DSU(int n){
        init(n);
    }
 
    void init(int n){
        node.resize(n);
        size.resize(n);
        val.resize(n);
        l.resize(n);
        r.resize(n);
 
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

        l[x] = chmin(l[x], l[y]);
        r[x] = chmax(r[x], r[y]);
        val[x] += val[y];
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
        return val[find(x)];
    }
};

void solve(){
    int n;
    cin >> n;

    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll l = 0, r = *max_element(a, a + n);
    while (l < r) {
        ll mid = l + r >> 1;
        DSU dsu(n + 1);

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
        for (int i = 0; i < n; i++) {
            q.push({a[i], i});
            dsu.l[i] = (i - 1 + n) % n;
            dsu.r[i] = (i + 1) % n;
            dsu.val[i] = a[i];
        }

        int owo = 0;
        while (!q.empty()) {
            auto p = q.top();
            q.pop();

            ll x = p.first;
            int id = p.second;
            if (x <= mid) {
                for (int i = (id - 1 + n) % n, j = (id + 1) % n; ; ) {
                    if (dsu.get(i) <= dsu.get(id) + mid && !dsu.set(i, id)) {
                        int L = dsu.l[dsu.find(i)];
                        dsu.merge(id, i);
                        i = L;
                    }
                    else if (dsu.get(j) <= dsu.get(id) + mid && !dsu.set(j, id)) {
                        int R = dsu.r[dsu.find(j)];
                        dsu.merge(id, j);
                        j = R;
                    }
                    else {
                        // cout << id << " " << i << " " <<j << " " << dsu.set(i, id) <<" " << dsu.set(j, id)<< endl;
                        break;
                    }
                }
            }
            owo = (dsu.find(id) == n);
            if (owo) {
                break;
            }
        }

        if (owo) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l << endl;
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
