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

const int N = (int) 3e5 + 1, M = N * 2;

int h[N], dep[N], deg[N], e[M], ne[M], idx;
vector<vector<int>> vec;

bool cmp(int u, int v) {
    return dep[u] < dep[v];
}

void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void get_h(int u, int fa, int depth) {
    dep[u] = depth;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == fa) continue;
        get_h(j, u, depth + 1);
    }
}

vector<int> dfs(int u, int fa) {
    vector<int> rem;

    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == fa) continue;
        if (deg[j] > 1) { //找到非叶子
            vector<int> cur = dfs(j, u);
            if (cur.size() > 0) {
                for (auto vt: cur) {
                    rem.pb(vt); //存储非匹配点
                }
            }
        }
        else if (deg[j] == 1) {
            rem.pb(j); //存储叶子节点
        }
    }
    sort(rem.begin(), rem.end(), cmp); //按高度排序，满足合法

    for (int i = 1; i < rem.size() - 1; i += 2) { //匹配节点，1对两个
        vec.pb({rem[i - 1], rem[i]});
    }

    if(rem.size() > 1){
        if(rem.size() % 2){
            rem = {rem.back()};
        }
        else{

        }
    }
    return rem;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        deg[i] = dep[i] = 0;
        h[i] = -1;
    }
    idx = 0;
    vec.clear();

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
        deg[u]++, deg[v]++;
    }

    get_h(1, 1, 0);
    auto rem = dfs(1, 1);
    sort(rem.begin(), rem.end(), cmp);

    for (int i = 1; i < rem.size(); i += 2) { //每个不同链连接
        vec.pb({rem[i], rem[i - 1]});
    }

    if (rem.size() % 2 && abs(dep[rem.back()] - dep[1]) <= 1) { //剩一个给1，看高度
        cout << -1 << endl;
        return;
    }
    else if (rem.size() > 0 && rem.size() % 2) {
        vec.pb({rem.back(), 1});
    }

    if (vec.empty()) {
        cout << -1 << endl;
        return;
    }
    else {
        cout << vec.size() << endl;
    }
    for (auto edge: vec) {
        cout << edge[0] << " " << edge[1] << endl;
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

    while (t--) {
        solve();
    }

    return 0;
}