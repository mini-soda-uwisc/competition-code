#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;
const double MAXN = 1e4 + 0.1;

template <typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

struct team {
    int id, school, rank;

    bool operator<(const team& other) const {
        return rank < other.rank;
    }

    bool chosen = false;
};

void solve() {
    int n, k, c;
    cin >> n >> k >> c;
    vector<team> a(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int id, school;
        cin >> id >> school;
        a[i] = {id, school, i + 1};
    }

    vector<team> ans(k);
    int cnt = 0;
    // first round: search for normal team
    for (int i = 0; i < n && cnt < k; i++) {
        if (mp[a[i].school] < c) {
            mp[a[i].school]++;
            a[i].chosen = true;
            ans[cnt++] = a[i];
        }
    }

    // second round: search for remaining team
    for (int i = 0; i < n && cnt < k; i++) {
        if (!a[i].chosen) {
            a[i].chosen = true;
            ans[cnt++] = a[i];
        }
    }

    // output
    sort(ans.begin(), ans.end());
    for (int i = 0; i < k; i++) {
        cout << ans[i].id << '\n';
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

    double ans = MAXN;

    while (t--) {
        solve();
    }

    return 0;
}
