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

bool cmp(pair<int, int>& x, pair<int, int>& y) {
    return x.second > y.second;
}

int what_the_hell = 1;

void solve() {
    int n, k; // hat num, k days
    cin >> n >> k;
    vector<int> seq(k); // k day hat
    for (int i = 0; i < k; ++i) {
        cin >> seq[i];
    }
    vector<int> hook(n - 1); // hat seri
    for (int i = 0; i < n - 1; ++i) {
        hook[i] = i + 2;
    }
    // for (int h : hook) {
    //     cout << h << '\n';
    // }

    if (seq[0] != 1) {
        what_the_hell = seq[0];
        for (int i = 0; i < k; ++i) {
            if (seq[i] == 1) {
                seq[i] = what_the_hell;
            } else if (seq[i] == what_the_hell) {
                seq[i] = 1;
            }
        }
    }

    // for (int i = 0; i < k; ++i) {
    //     cerr << seq[i] << " \n"[i == n - 1];
    // }

    int sum = 0;
    int now = seq[0];
    vector<int> hook_sum(n - 1);
    for (int i = 1; i < k; i++) {
        int nxt = seq[i];
        // cout << "next to be: " << nxt << '\n';
        for (int j = 0; j < n - 1; j++) {
            // cout << "find (" << nxt << ") on hook (" << j << "), which is (" << hook[j] << ")\n";
            if (hook[j] == nxt) {
                swap(now, hook[j]);
                sum += j + 1;
                hook_sum[j]++;
            }
        }
    }
    // cout << sum << '\n';

    vector<pair<int, int>> ans(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        ans[i] = make_pair(i + 2, hook_sum[i]);
    }
    sort(ans.begin(), ans.end(), cmp);

    sum = 0;
    now = seq[0];
    for (int i = 0; i < n - 1; ++i) {
        hook[i] = ans[i].first;
    }

    for (int i = 1; i < k; i++) {
        int nxt = seq[i];
        // cout << "next to be: " << nxt << '\n';
        for (int j = 0; j < n - 1; j++) {
            // cout << "find (" << nxt << ") on hook (" << j << "), which is (" << hook[j] << ")\n";
            if (hook[j] == nxt) {
                swap(now, hook[j]);
                sum += j + 1;
                hook_sum[j]++;
            }
        }
    }
    cout << sum << '\n';

    for (int i = 0; i < n - 1; i++) {
        if (ans[i].first == what_the_hell) {
            cout << 1 << ' ';
        } else if (ans[i].first == 1) {
            cout << what_the_hell << ' ';
        } else {
            cout << ans[i].first << ' ';
        }
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
    //  cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
