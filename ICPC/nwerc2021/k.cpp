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
    unordered_map<string, pair<int, bool>> mp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string name, type;
        int x;
        cin >> name >> type >> x;
        if (type == "any") {
            mp[name].first = 1;
            if (x <= 1) {
                mp[name].second = false;
            } else {
                mp[name].second = true;
            }
        } else {
            if (mp.find(name) != mp.end()) {
                mp[name].first = max(mp[name].first, x);
                mp[name].second = true;
            } else {
                mp[name].first = x;
                mp[name].second = false;
            }
        }
    }

    bool flag = false;
    for (const auto& [name, pair] : mp) {
        if (pair.second) {
            flag = true;
            break;
        }
    }
    if (flag == false) {
        cout << "impossible\n";
        return;
    }

    int ans = 0;
    for (const auto& [name, pair] : mp) {
        ans += pair.first;
    }
    cout << ans + 1 << '\n';
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
