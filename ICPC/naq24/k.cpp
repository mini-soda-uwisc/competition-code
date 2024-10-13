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

int n = 0, m = 0;

int find_range(int number) {
    if (number <= 15) {
        return 7;
    } else if (number <= 23) {
        return 6;
    } else if (number <= 43) {
        return 4;
    } else if (number <= 102) {
        return 2;
    } else {
        return 0;
    }

}

void compute_dp(const vector<int> &a, const vector<int> &b, vector<vector<int>> &dp, int &max_score) {
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int no_match = chmax(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = chmax(dp[i - 1][j - 1], no_match);

            int current = dp[i - 1][j - 1] + find_range(abs(b[i - 1] - a[j - 1]));
            dp[i][j] = chmax(dp[i][j], current);
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            max_score = chmax(max_score, dp[i][j]);
        }
    }
}

void solve() {
    cin >> n >> m;

    vector<int> a(n + 1), b(m + 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int max_score = 0;

    compute_dp(a, b, dp, max_score);

    cout << max_score << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
