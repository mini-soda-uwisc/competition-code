#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back
//#define int long long

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
int h[N], e[M], ne[M], w[M], idx;

void add(int u, int v, int t){
    e[idx] = v, w[idx] = t, ne[idx] = h[u], h[u] = idx++;
}

int n, m;

struct DP{
    int qwq;
    vector<int> owo;
};

void solve(){
    string buf;
    vector<int> a;

    for(int i = 0; i < n; i++){
        h[i] = -1;
    }
    idx = 0;

    getchar();
    getline(cin, buf);
    do {
        stringstream ss(buf);
        string x;
        while(getline(ss, x, ',')) {
            a.pb(stoi(x));
        }
    } while (0);

    vector<int> indeg(n), outdeg(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w + a[v]);
        outdeg[u]++;
        indeg[v]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> q;
    vector<DP> f(n, {0, {}});

    int qwq = 0, id = 0;
    for(int i = 0; i < n; i++){
        if(!indeg[i]){
            f[i] = {a[i], {i}};
            q.push({a[i], i});
        }
        if(!outdeg[i]){
            id = i;
        }
    }

    while(!q.empty()){
        auto [d, u] = q.top();
        q.pop();

        for(int i = h[u]; i != -1; i = ne[i]){
            int j = e[i];
            if(f[j].qwq < f[u].qwq + w[i]){
                f[j].qwq = f[u].qwq + w[i];
                f[j].owo = f[u].owo;
                f[j].owo.pb(j);
                if(j == id){
                    qwq = 0;
                }
                q.push({f[j].qwq, j});
            }
            else if(j == id && f[j].qwq == f[u].qwq + w[i]){
                qwq = 1;
            }
        }
    }

    cout << f[id].qwq << ",";
    if(qwq){
        cout << "M" << endl;
    }
    else {
        for (int i = 0; i < f[id].owo.size(); i++) {
            if (i == f[id].owo.size() - 1) {
                cout << f[id].owo[i] << endl;
            }
            else {
                cout << f[id].owo[i] << ",";
            }
        }
    }
}

signed main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    while (cin >> n >> m) {
        solve();
    }

    return 0;
}