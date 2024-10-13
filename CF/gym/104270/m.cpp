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

ll enclosedAreas[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

ll solveG(ll x, ll k) {
    if (k <= 0) {
        return x;
    }
    if (x == 0) {
        return k % 2;
    }
    ll ans = 0;
    while (x > 0) {
        ll d = x % 10;
        x /= 10;
        ans += enclosedAreas[d];
    }
    return solveG(ans, k - 1);
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        ll x = 0;
        ll k = 0;
        cin >> x >> k;
        cout << solveG(x, k) << endl;
    }

    return 0;
}