#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template <typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

void solve() {
    ll H = 0, n = 0;
    cin >> n >> H;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        vector<ll> b(3);
        for (auto& x : b) cin >> x;
        sort(b.begin(), b.end());
        int flag = -1;

        for (int k = 0; k < 3; k++) {
            if (b[k] <= H) {
                flag = k;
            }
        }

        if (flag == -1) {
            cout << "impossible\n";
            return;
        }
        for (int k = 0; k < 3; k++) {
            if (k != flag) {
                ans += b[k];
                break;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
