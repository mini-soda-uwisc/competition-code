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

const int N = (int)1e5 + 1, M = N * 2;

void solve(){
    int n, m;
    cin >> n >> m;

    int qwq = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        qwq += a[i];
    }
    sort(a.begin(), a.end());

    bitset<N> f;
    int idx = n - 1;
    f[0] = 1;

    int pp = m + 1;
    for (int i = 1; i <= m; i++) {
        if (idx >= 0 && a[idx] > m - i) {
            qwq -= a[idx];
            f |= f << a[idx];
            idx--;
        }

        if (qwq > i) {
            continue;
        }
        if (f[i - qwq]) {
            pp = chmin(pp, i);
        }
    }
    cout << pp << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
