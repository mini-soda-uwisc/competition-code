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
    ll n, m, a, c, x0;
    cin >> n >> m >> a >> c >> x0;

    vector<ll> A(n + 1);
    A[0] = x0;
    A[0] %= m;

    for (int i = 1; i <= n; i++) {
        A[i] = ((A[i - 1] * a % m) + c) % m;
    }

    auto dv = [&](auto& self, int l, int r, ll x, ll y) -> int {
        if (x > y || l > r) {
            return 0;
        }
        if (l == r) {
            return A[l] >= x && A[l] <= y;
        }

        int mid = l + r >> 1;
        //cout << A[mid] << " " << mid << " " << l << " " << r << " " << x << " " << y << endl;
        int L = self(self, l, mid - 1, x, chmin(A[mid] - 1, y));
        int R = self(self, mid + 1, r, chmax(A[mid] + 1, x), y);
        return (x <= A[mid] && A[mid] <= y) + L + R;
    };

    cout << dv(dv, 1, n, 0, m - 1) << endl;
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
