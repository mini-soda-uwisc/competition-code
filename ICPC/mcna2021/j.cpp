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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> ans(m);
    int sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum <= n) {
        for (int i = 0; i < m; ++i) {
            cout << a[i] << endl;
        }
        return;
    }

    sum = 0;
    bool flag = false;
    while (sum <= n) {
        for (int i = 0; i < m; i++) {
            if (a[i] > 0) {
                sum++;
                a[i]--;
                ans[i]++;
            }
            if (sum == n) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << endl;
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}