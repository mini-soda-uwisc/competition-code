#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;
const double MAXN = 1e4 + 0.1;

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
    ll n, k, p;
    cin >> n >> k >> p;
    vector<ll> a;
    for (ll d = 1; d <= sqrt(n); ++d) {
        if (n % d == 0) {
            if (d <= k && n / d <= p) {
                a.pb(d);
            }
            if (d != n / d) {
                if (n / d <= k && d <= p) {
                    a.pb(n / d);
                }
            }
        }
    }
    sort(a.begin(), a.end());
    cout << a.size() << '\n';
    for (const ll x : a) {
        cout << x << '\n';
    }
    cout << '\n';
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    double ans = MAXN;

    while (t--) {
        solve();
    }

    return 0;
}
