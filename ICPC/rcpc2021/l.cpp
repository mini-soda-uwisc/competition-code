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

const int N = (int)1e5 + 1, M = N * 2;

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

void solve() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.heuristic_merge(u, v);
    }

    map<int, int> mp;
    ld qwq = n * 1ll * (n - 1) / 2, uwu = 0;
    for (int i = 1; i <= n; i++) {
        if (mp[dsu.find(i)]) {
            continue;
        }
        mp[dsu.find(i)] = 1;
        ld owo = dsu.get(i);
        uwu += owo * (owo - 1) / 2;
    }
    cout << setprecision(20) << uwu / qwq << endl;
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
