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

const int N = (int)1e5 + 1, M = N * 2;

void solve() {
    int n, p;
    cin >> n >> p;
    int sum = 0;
    vector<int> a(n);
    vector<int> b(n);
    cin >> a[0];
    b[0] = 0;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        if (a[i] < a[i - 1] || (a[i] == 0 && a[i - 1] != 0)) {
            sum++;
        }
        // else if (a[i] == a[i - 1] && a[i] != 0 && p > 1) {
        //     cout << "ambiguous\n";
        //     // cout << "at case 0 : " << i << "\n";
        //     return;
        // }
        b[i] = sum;
    }
    if (a[n - 1] != 0) {
        sum++;
    }

    if (a[0] == 0 && sum == 0) {
        for (int i = 0; i < n; ++i) {
            cout << "0\n";
        }
        return;
    }
    if (sum != p) {
        cout << "ambiguous\n";
        // cout << "at case 1" << "\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (sum - b[i] == 0 && a[i] != 0) {
            cout << "ambiguous\n";
            // cout << "at case 2" << "\n";
            return;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << sum - b[i] << "\n";
    }
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
