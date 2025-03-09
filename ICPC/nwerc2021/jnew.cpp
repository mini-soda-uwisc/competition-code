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
    int n;
    cin >> n;

    vector<vector<int>> a;
    int min = 1e9, id = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a.pb({x, y});
        min = chmin(min, y);
        if(min == y){
            id = i;
        }
    }

    vector<vector<int>> b;
    for (int i = 0; i < n; i++) {
        a[i][1] += abs(min);
        a[i][1] *= 2;
        a[i][1] += 1;
    }

    for (int i = id; i < id + n; i++) {
         b.pb(a[i % n]);
    }

    b.pb(a[id]);
    b[b.size() - 1][1] += 721;

    for (int i = 0; i < b.size(); i++) {
        cout << b[i][1] << " ";
    }
    cout << endl;

    vector<int> v(N);
    for (int i = 1; i < b.size(); i++) {
        for (int j = chmin(b[i - 1][1], b[i][1]); j <= chmax(b[i - 1][1], b[i][1]); j++) {
            v[j] = 1;
        }
    }

    for (int i = 1; i <= 721; i++) {
        if (!v[i]) {
            cout << "no" << endl;
            cout << ((i - 1) / 2) - abs(min) << endl;
            return;
        }
    }
    cout << "yes" << endl;
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
