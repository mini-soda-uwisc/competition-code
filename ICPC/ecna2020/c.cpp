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

const int N = (int)1e4 + 1, M = N * 2;

struct SCC{
    vector<int> dfn, low, stk, id, visited, sz;
    vector<vector<int>> adj;
    int timestamp, top, cnt, n;

    SCC(int _n) : dfn(_n), low(_n), stk(_n), id(_n), visited(_n), adj(_n), sz(_n){
        timestamp = top = cnt = 0;
        n = _n;
    }

    void add(int u, int v){
        adj[u].push_back(v);
    }

    void tarjan(int u){
        dfn[u] = low[u] = ++timestamp;
        stk[++top] = u;
        visited[u] = true;

        for(int j : adj[u]){
            if(dfn[j] == 0){
                tarjan(j);
                low[u] = chmin(low[u], low[j]);
            }
            else if (visited[j]){
                low[u] = chmin(low[u], dfn[j]);
            }
        }

        if(dfn[u] == low[u]){
            int y;
            ++cnt;
            do{
                y = stk[top--];
                visited[y] = false;
                id[y] = cnt;
                sz[cnt]++;
            }while(y != u);
        }
    }

    void tarjan(){
        for(int i = 1; i <= n - 1; i++){ //n + 1
            if(!dfn[i]){
                tarjan(i);
            }
        }
    }
};

void solve(){
    int n;
    cin >> n;

    vector<vector<string>> s;
    int id = 0;
    map<string, int> mp;

    SCC scc(3 * n + 1);
    for(int i = 0; i < n; i++){
        string S, u, v;
        cin >> S >> u >> v;

        if (!mp.count(u)) {
            mp[u] = id++;
        }
        if (!mp.count(v)) {
            mp[v] = id++;
        }

        scc.add(mp[u], mp[v]);
    }

    scc.tarjan();

    int max = 0;
    for (auto elt : scc.sz) {
        max = chmax(max, elt);
    }

    if (max >= 2) {
        cout << max << endl;
    }
    else {
        cout << "No trades possible" << endl;
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
