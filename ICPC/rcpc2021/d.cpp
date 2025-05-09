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

    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    map<int, int> mp;
    int l = 0, sz1 = 0, sz2 = 0;
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
        mp[b[i]]--;

        if (mp[b[i]] == 0) {
            mp.erase(b[i]);
        }
        if (mp[a[i]] == 0) {
            mp.erase(a[i]);
        }

        if (mp.size() == 0) {
            for (int j = l; j <= i; j++) {
                cout << b[j] << " ";
            }
            if (i != n - 1) {
                cout << "# ";
            }
            l = i + 1;
        }
    }
    cout << endl;
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
