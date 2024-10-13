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
    ll c;
    cin >> c;

//    if (sqrt(c) == (ll)sqrt(c)) {
//        cout << "yes\n";
//        return;
//    }
    // calculate c ^ 1/3
    ll triple_root = (ll)(int)cbrt(c);
//    cout << "triple root: " << triple_root << '\n';

    for (ll p = 2; p <= triple_root; ++p) {
        ll psquare = p * p;
        if (c % psquare != 0) continue;
        cout << "yes\n";
        return;
    }
    for (ll q = 1; q <= triple_root; q++) {
        if (c % q != 0) continue;
        ll psquare = c / q;
        ll p = (ll)(int)sqrt(psquare);
        if (p * p == psquare) {
            cout << "yes\n";
            return;
        }
    }

    cout << "no\n";
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}