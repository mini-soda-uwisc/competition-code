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

int f(int x) {
    if (x == 0) return 0;
    int mx = INT_MIN;
    while (x) {
        mx = max(mx, x % 10);
        x /= 10;
    }
    return mx;
}

void solve(){
    int la, ra, lb, rb;
    cin >> la >> ra >> lb >> rb;
    int l = la + lb, r = ra + rb;

    if (r - l + 1 >= 10) {
        cout << "9\n";
        return;
    }

    int ans = INT_MIN;
    for (int i = l; i <= r; ++i) {
        ans = max(ans, f(i));
    }
    cout << ans << '\n';
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