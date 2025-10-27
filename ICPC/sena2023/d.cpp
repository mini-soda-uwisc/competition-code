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

string s;
int states[10];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    bool has_sol = false;
    for (int seg_num = 2; seg_num <= n; ++seg_num) {
        if (n % seg_num != 0) continue;

        const int seg_len = n / seg_num;
        vector<int> min_seg(seg_num + 1, INT_MAX);
        vector<int> max_seg(seg_num + 1, INT_MIN);
        for (int seg_idx = 1; seg_idx <= seg_num; ++seg_idx) {
            for (int i = 1; i <= seg_len; ++i) {
                const int idx = (seg_idx - 1) * seg_len + i;
                min_seg[seg_idx] = min(min_seg[seg_idx], a[idx]);
                max_seg[seg_idx] = max(max_seg[seg_idx], a[idx]);
            }
        }

        // debug
        // cerr << seg_num << ":\n";
        // cerr << "min_seg:\n";
        // for (int seg_idx = 1; seg_idx <= seg_num; ++seg_idx) {
        //     cerr << min_seg[seg_idx] << ' ';
        // }
        // cerr << '\n';
        // cerr << "max_seg:\n";
        // for (int seg_idx = 1; seg_idx <= seg_num; ++seg_idx) {
        //     cerr << max_seg[seg_idx] << ' ';
        // }
        // cerr << '\n';

        bool flag = true;
        // check min max
        for (int seg = 2; seg <= seg_num; ++seg) {
            if (min_seg[seg] < max_seg[seg - 1]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            has_sol = true;
            cout << seg_num << '\n';
        }
    }
    if (!has_sol) {
        cout << "-1\n";
    }
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
