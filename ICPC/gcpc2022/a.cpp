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
    ll n, m;
    cin >> n >> m;
    n--, m--;

    ll qwq = (n == m ? 1 : 2), owo = 0;

    for (ll i = 1, y = n; i < n; i++) {
        while (i * i + y * y > n * n) {
            y--;
        }
        if (i * i + y * y == n * n) {
            if (m * i % n == 0 || m * y % n == 0) {
                owo += qwq;
            }
        }
    }

    cout << qwq + owo << endl;
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
