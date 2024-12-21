#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;
const double eps = 1e-9;

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
        int x, y, h;
        cin >> x >> y >> h;
        a.pb({x, y, h});
    }
    vector<int> b(n);

    for(int i = 0; i < n; i++){
        int qwq = (int)1e9, owo = 0;
        for(int j = 0; j < n; j++){
            if(i != j && a[i][2] <= a[j][2]){
                ld x1 = a[i][0], y1 = a[i][1], h1 = a[i][2];
                ld x2 = a[j][0], y2 = a[j][1], h2 = a[j][2];
                ld dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
                if(h2 == h1) {
                    qwq = chmin(qwq, (int)(dist / 2));
                }
                else{
                    qwq = chmin(qwq, (int)dist);
                }
                owo = 1;
            }
        }
        if(owo){
            b[i] = chmin(a[i][2], qwq);
        }
        else{
            b[i] = a[i][2];
        }
    }

    for(auto e : b){
        cout << e << endl;
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