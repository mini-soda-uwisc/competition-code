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

    stack<int> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> mp;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        while (!q.empty() && a[q.top()] > a[i]) {
            mp[a[q.top()]] = 1;
            q.pop();
        }
        cnt += mp.size();
        mp.clear();
        q.push(i);
    }

    while (!q.empty()) {
        mp[a[q.top()]] = 1;
        q.pop();
    }
    cout << cnt + mp.size() << "\n";
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
