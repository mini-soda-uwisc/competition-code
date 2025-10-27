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
    int n;
    cin >> n;

    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<int>> c;
    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            c.push_back({a[i], b[i]});
        }
    }

    auto cmp = [&](const vector<int>& a, const vector<int>& b) -> bool {
        return a[1] < b[1];
    };
    sort(c.begin(), c.end(), cmp);

    ll l = 1, r = (ll)1e12;
    while (l < r) {
        ll mid = l + r >> 1;
        ll sum = 0;
        int flag = 1;

        for (int i = 0; i < c.size(); i++) {
            sum += c[i][0];
            if ((sum + mid - 1) / mid > c[i][1]) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
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
