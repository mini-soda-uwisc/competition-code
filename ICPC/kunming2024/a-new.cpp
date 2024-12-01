#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, k;

struct Contest {
    int index;
    int s;
    vector<int> a;
    vector<int> neg_index;
    int neg_count = 0;
    int sum = 0;
    Contest() {
        a.resize(m);
    }

    void input() {
        cin >> s;
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
            if (a[i] == -1) {
                neg_index.emplace_back(i);
                ++neg_count;
            } else {
                sum += a[i];
            }
        }
    }
    void output() {
        for (int i = 0; i < m; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
};



inline void solve() {
    cin >> n >> m >> k;
    vector<Contest> c(n);
    for (int i = 0; i < n; ++i) {
        c[i].index = i;
        c[i].input();
    }

    sort(c.begin(), c.end(), [](Contest &a, Contest &b) {
        return a.s < b.s;
    });

    int last_biggest_sum = -1;
    int this_biggest_sum = -1;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            for (int j = 0; j < c[i].neg_count; ++j) {
                c[i].a[c[i].neg_index[j]] = 0;
            }
            this_biggest_sum = c[i].sum;

            continue;
        }

        Contest &cur = c[i], &pre = c[i - 1];

        if (cur.s == pre.s) {

        } else {
            last_biggest_sum = this_biggest_sum;
            this_biggest_sum = -1;
        }

        // set cur to be greater than last one
        if (cur.sum > last_biggest_sum) {
            for (int j = 0; j < cur.neg_count; ++j) {
                cur.a[cur.neg_index[j]] = 0;
            }
        } else {
            if (cur.neg_count * k + cur.sum <= last_biggest_sum) {
//                cout << "neg_count * k: " << cur.neg_count * k << '\n';
                cout << "No\n";
                return;
            }
            int target = last_biggest_sum + 1 - cur.sum;

            for (int j = 0; j < cur.neg_count; ++j) {
                cur.a[cur.neg_index[j]] = min(target, k);
                cur.sum += min(target, k);
                target -= k;

                if (target <= 0) {
                    for (int k = j + 1; k < cur.neg_count; ++k) {
                        cur.a[cur.neg_index[k]] = 0;
                    }
                    break;
                }
            }
        }

        this_biggest_sum = max(this_biggest_sum, cur.sum);
    }

    sort(c.begin(), c.end(), [](Contest &a, Contest &b) {
        return a.index < b.index;
    });
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        c[i].output();
    }
}

signed main() {
//    freopen("D:\\Documents\\doc\\coding\\competition-code\\ICPC\\kunming2024\\a.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}