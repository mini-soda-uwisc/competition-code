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

bool cmp(vector<ll> a, vector<ll> b){
    return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
}

void solve(){
    map<ll, ll> f, g, v;
    int n, m, q;
    cin >> n >> m >> q;

    int t = m, lvl = -1;
    for(int i = 0; i < q; i++){
        int op;
        cin >> op;

        if(op == 1){
            cin >> lvl;
            t = m;
            v.clear();
            g.clear();
        }
        else if(op == 2){
            int id, x;
            cin >> id >> x;
            if(g[id] || v[id]){
                continue;
            }
            if(x == lvl){
                f[id] += t;
                v[id] = 1;
                t--;
            }
        }
        else if(op == 3){
            int id, x;
            cin >> id >> x;
            if(x == lvl){
                g[id] = 1;
            }
        }
    }

    vector<vector<ll>> a;
    for(int i = 1; i <= m; i++){
        a.pb({f[i], i});
    }

    sort(a.begin(), a.end(), cmp);
    for(auto v : a){
        cout << v[1] << " " << v[0] << endl;
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

    while(t--){
        solve();
    }

    return 0;
}