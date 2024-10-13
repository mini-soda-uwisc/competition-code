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

unordered_map<ld, vector<ld>> gear_group;

void solve_input() {
    int s, c;
    cin >> s >> c;
    gear_group[s].pb(c);
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve_input();
    }

    ld total_log_ratio = 0.0;

    for (auto &[size, counts]: gear_group) {
        sort(counts.begin(), counts.end(), greater<>());
        int counts_size = (int)counts.size();
        for (int i = 0, j = counts_size; i < j; ++i, --j) {
            total_log_ratio += log((ld) counts[i]) - log((ld) counts[counts_size - 1 - i]);
        }
    }

    cout << fixed << setprecision(20) << total_log_ratio << "\n";
    return 0;
}