#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), mp(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mp[a[i]] = i;
    }

    cout << "3\n";
    vector<int> b;
    int limt = n / 4;
    for (int i = 1; i <= limt; ++i) {
        cout << i << " " << mp[i] << " ";

    }
    cout << "\n";


    mp.clear();
    for (int i = 1; i <= n; ++i) {
        mp[a[i]] = i;
    }
    for (int i = n / 4 + 1; i <= n / 2; ++i) {
        cout << i << " " << mp[i] << " ";

    }
    cout << "\n";

    for (int i = n / 2 + 1; i <= n; ++i) {
        cout << i << " ";
    }
    cout << "\n";
}


int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
