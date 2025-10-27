#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ld = long double;
using ll = long long;

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

const int N = (int)1e6 + 1, M = N * 10;

int clampUp(const int x, const int down) {
    return x < down ? down : x;
}

void solve() {
    int n, d;
    unordered_map<int, vector<int>> mp;
    cin >> n >> d;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x].emplace_back(i);
    }

    if (mp.find(0) == mp.end() || mp.size() == 1 && mp[0].size() <= d) {
        cout << "0\n";
        exit(0);
    }

    for (int i = 0; i < n; i++) {
        const auto len = mp[i].size();
        bool flag = true;

        int pre = INT_MIN; // last shield open time
        if (len <= 1) {
            cout << i << '\n';
            exit(0);
        }

        for (int j = 0; j < len; ++j) {
            const int x = mp[i][j];
            int s = clampUp(max(pre + 2 * d, x - d), 0);

            pre = s;
        }
        if (flag) {
            cout << i << '\n';
            exit(0);
        }
    }
    cout << n << '\n';
}

int main() {
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
