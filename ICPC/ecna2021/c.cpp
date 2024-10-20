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

void solve() {
    int a1 = 0, a2 = 0, a3 = 0;

    for (int i = 0; i < 3; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if ((x >= 1 && x <= 5) || (x >= 26 && x <= 30)) {
                a1++;
            }
            if ((x >= 6 && x <= 10) || (x >= 21 && x <= 25)) {
                a2++;
            }
            if (x >= 11 && x <= 20) {
                a3++;
            }
        }
    }


    if (a1 + a2 == 20 && a3 == 10) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}