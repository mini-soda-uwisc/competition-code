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

    vector<vector<int>> ddbb;
    for (int k = 1; k <= 3; ++k) {
        vector<int> ans, idx;
        int cnt = 1;
        for (int i = 1; i <= n && cnt < n / 2; ++i) {
            if (mp[i] == i) {
                continue;
            }

            int x = i;
            while (mp[x] != x && cnt < n / 2) {
                ans.emplace_back(x);
                idx.push_back(mp[x]);
                x = a[x];
                cnt++;
            }

            if (mp[x] != x) {
                ans.emplace_back(x);
                idx.push_back(mp[x]);
            }

            // for (const int c : idx) {
            //     cout << c << " ";
            // }
            // cout << "\n";

            vector<int> pick;
            for (int j = 1; j <= n; j++) {
                if (mp[j] == j) {
                    pick.push_back(j);
                }
            }

            sort(ans.begin(), ans.end());
            sort(idx.begin(), idx.end());

            for (int j = 0; j < ans.size(); j++) {
                mp[ans[j]] = idx[j];
                a[idx[j]] = ans[j];
            }

            ans.erase(unique(ans.begin(), ans.end()), ans.end());
            while (pick.size() && ans.size() < n / 2) {
                ans.push_back(pick.back());
                pick.pop_back();
            }
            ddbb.push_back(ans);
        }

        // for (int j = 1; j <= n; j++) {
        //     cout << a[j] << " \n"[j == n];
        // }
    }

    cout << ddbb.size() << "\n";
    for (auto DDBB : ddbb) {
        for (auto DDBB520 : DDBB) {
            cout << DDBB520 << " ";
        }
        cout << "\n";
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
