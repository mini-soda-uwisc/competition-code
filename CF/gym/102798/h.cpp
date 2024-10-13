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

void solve(){
    map<int, int> m1, send, st;
    map<int, map<int, int>> m2;

    int n, m, s;
    cin >> n >> m >> s;

    vector<multiset<int>> v(n + 1);

    for(int i = 0; i < s; i++){
        int op, x, y;
        cin >> op >> x >> y;

        if(op == 1){
            m2[x][y] = st[y];
            v[y].insert(x);
        }
        else if(op == 2){
            m1[x] += st[y] - m2[x][y];
            m2[x][y] = st[y];
            v[y].erase(v[y].find(x));
        }
        else{
            st[y] += 1;
            send[x] += 1;
        }
    }

    for(int i = 1; i <= n; i++){
        for(auto x : v[i]){
            m1[x] += st[i] - m2[x][i];
        }
    }

    for(int i = 1; i <= m; i++){
        cout << m1[i] - send[i] << endl;
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}