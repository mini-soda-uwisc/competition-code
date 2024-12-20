#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back
#define int long long

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
    int n;
    cin >> n;

    vector<vector<int>> a;
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        a.pb({u, v, i});
    }

    sort(a.begin(), a.end(), [](vector<int>& a, vector<int>& b) {
//        return a[1] * b[0] > a[0] * b[1];
        int left = a[1] * b[0], right = a[0] * b[1];
        if (left != right) return left > right;
        return a[2] < b[2];
    });

    for (int i = 0; i < n; ++i) {
        cout << a[i][2] + 1 << ' ';
    }
    cout << '\n';
}

signed main() {
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