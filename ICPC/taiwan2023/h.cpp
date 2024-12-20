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
    int c;
    cin >> c;

    int f[c + 1];
    memset(f, 0, sizeof f);
    getchar();

    vector<int> a, b;
    string buf;
    getline(cin, buf);
    do {
        stringstream ss(buf);
        int t;
        while (ss >> t) {
            a.pb(t);
        }
    } while (0);

    getline(cin, buf);
    do {
        stringstream ss(buf);
        int t;
        while (ss >> t) {
            b.pb(t);
        }
    } while (0);

    for(int i = 0; i < a.size(); i++){
        for(int j = c; j >= b[i]; j--){
            f[j] = chmax(f[j], f[j - b[i]] + a[i]);
        }
    }

    cout << f[c] << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}