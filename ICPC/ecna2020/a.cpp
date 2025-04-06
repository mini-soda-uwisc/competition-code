#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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

const int N = (int)1e6 + 1, M = N * 2;

struct LCA{
    vector<int> h, w, e, ne, dep;
    vector<vector<int>> fa;
    int n, idx;

    const int depth = 18;

    LCA(int _n){
        n = _n;
        idx = 0;

        dep.resize(n, (int)1e9);
        fa.resize(n);

        ne.resize(n * 2, 0);
        h.resize(n * 2, -1);
        e.resize(n * 2, 0);

        for(int i = 0; i < n; i++){
            fa[i] = vector<int>(depth + 1);
        }
    }

    void add(int u, int v) {
        e[idx] = v, ne[idx] = h[u], h[u] = idx++;
        e[idx] = u, ne[idx] = h[v], h[v] = idx++;
    }

    void bfs(int rt) {
        dep[rt] = 1;
        dep[0] = 0;

        queue<int> q;
        q.push(rt);

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i = h[u]; i != -1; i = ne[i]){
                int j = e[i];
                if(dep[j] > dep[u] + 1){
                    dep[j] = dep[u] + 1;

                    q.push(j);
                    fa[j][0] = u;

                    for(int k = 0; k < depth; k++){
                        fa[j][k + 1] = fa[fa[j][k]][k];
                    }
                }
            }
        }
    }

    int lca(int u, int v){
        if(dep[u] < dep[v]) swap(u, v);

        for(int i = depth - 1; i >= 0; i--){
            if(dep[fa[u][i]] >= dep[v]){
                u = fa[u][i];
            }
        }
        if(u == v) return u;

        for(int i = depth - 1; i >= 0; i--){
            if (fa[u][i] != fa[v][i]){
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return fa[u][0];
    }
};

string mysth(int x) {
    int t = x % 100;
    if (11 <= t && t <= 20) {
        return to_string(x) + "th";
    }
    t %= 10;
    if (t == 1) {
        return to_string(x) + "st";
    } else if (t == 2) {
        return to_string(x) + "nd";
    } else if (t == 3) {
        return to_string(x) + "rd";
    } else {
        return to_string(x) + "th";
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    LCA lca(N);
    map<string, int> mp;

    int id = 1;
    vector<int> deg(N);
    for (int i = 0; i < n; i++) {
        string u;
        cin >> u;

        if (!mp.count(u)) {
            mp[u] = id++;
        }

        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            string v;
            cin >> v;

            if (!mp.count(v)) {
                mp[v] = id++;
            }
            lca.add(mp[u], mp[v]);
            deg[mp[v]]++;
        }
    }

    int rt = 0;
    for (int i = 1; i < id; i++) {
        if (!deg[i]) {
            rt = i;
        }
    }

    assert(rt);
    lca.bfs(rt);

    auto type1 = [&](string s1, string s2, int dist) -> void {
        if (dist == 1) {
            cout << s2 << " " << "is the child of" << " " << s1 << '\n';
        }
        else {
            string s3 = "is the ";
            for (int i = 0; i < dist - 2; i++) {
                s3 += "great ";
            }
            s3 += "grandchild of";
            cout << s2 << " " << s3 << " " << s1 << '\n';
        }
    };

    auto type2 = [&](string s1, string s2, int d1, int d2) -> void {
        if (d1 == 1 && d2 == 1) {
            cout << s1 << " and " << s2 << " are siblings" << '\n';
        }
        else if (d1 == d2) {
            cout << s1 << " and " << s2 << " are " << mysth(d1 - 1) << " cousins" << '\n';
        }
        else {
            int diff = chmax(d1, d2) - chmin(d1, d2);
            string time = (diff == 1 ? "1 time removed" : to_string(diff) + " times removed");
            cout << s1 << " and " << s2 << " are " << mysth(chmin(d1 - 1, d2 - 1)) << " cousins, " << time << '\n';
        }
    };

    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        int u = mp[s1], v = mp[s2];
        int anc = lca.lca(u, v);
        //cout << u << " " << v << " " << anc << endl;
        if (anc == u) {
             type1(s1, s2, lca.dep[v] - lca.dep[u]);
        }
        else if (anc == v) {
            type1(s2, s1, lca.dep[u] - lca.dep[v]);
        }
        else {
            type2(s1, s2, lca.dep[u] - lca.dep[anc], lca.dep[v] - lca.dep[anc]);
        }
    }
}

int main(){
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
