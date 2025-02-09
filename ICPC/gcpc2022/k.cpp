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
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int dir = 0;
    for (int i = 0; i < n; i++) {
        if (dir == 0) {
            if (s[i] != 'L') {
                dir = 0;
                m--;
            }
            else {
                dir = 1;
            }
        }
        else {
            if (s[i] != 'R') {
                dir = 1;
                m--;
            }
            else {
                dir = 0;
            }
        }
    }
    cout << chmax(0, m) << endl;
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
