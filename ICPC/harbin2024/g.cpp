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
int h[N], v[N], inq[N], c[N], ne[M], e[M], idx, tp;
map<pair<int, int>, vector<int>> mp;

void add(int u, int v){
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void dfs(int u){
    if(inq[u]){
        for(int i = h[u]; i != -1; i = ne[i]){
            int j = e[i];
            if(!inq[j]){
                mp[{tp, u}].pb(j);
                inq[j] = 1;
            }
        }
        tp++;
    }

    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(v[j] || c[j]) continue;
        v[j] = 1;
        dfs(j);
    }
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i <= n; i++){
        v[i] = inq[i] = 0;
        h[i] = -1;
    }
    idx = tp = 0;

    for(int i = 0; i < k; i++){
        int u;
        cin >> u;
        c[u] = 1;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    for(int i = 1; i <= n; i++) {
        if(!v[i] && c[i] == 0) {
            v[i] = inq[i] = 1;
            dfs(i);
            break;
        }
    }

    for(int i = 1; i <= n; i++){
        if(!inq[i]){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
    cout << mp.size() << endl;

    for(auto [k, vl] : mp){
        cout << k.second << " " << vl.size() << " ";
        for(auto el : vl){
            cout << el << " ";
        }
        cout << endl;
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}