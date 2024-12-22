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

const int N = (int) 1e5 + 1, M = N * 2;
const ll A_NUMBER_LARGE_ENOUGH = 1e18;

unordered_map<long long, int> mp;
vector<ll> a;

void pre() {
    ll x = 2;
    while (x <= A_NUMBER_LARGE_ENOUGH) {
        mp[x - 1] = -1;
        a.emplace_back(x - 1);
        x *= 2;
    }
}

int dfs(ll x) {
//    cout << "Hey you motherfucker " << x << '\n';
    if (mp[x] == -1) {
        return 0;
    } else if (mp[x] != 0) {
        return mp[x];
    }
    auto it = lower_bound(a.begin(), a.end(), x);
    --it;
//    cout << "I got " << *it << '\n';
    mp[x] = 1 + dfs(x - *it);
    return mp[x];
}

void solve() {
    ll t;
    cin >> t;
    int ans = 0;

    cout << dfs(t) << '\n';
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pre();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
