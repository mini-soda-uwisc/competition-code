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
    int a[4][4] = {0};
    string s;
    cin >> s;
//    cout << s << endl;
    for (int i = 0; i < s.length(); ++i) {
        int x = s[i] - '0';
        int j = 3;
        while (x) {
            a[i][j] = x & 1;
            x >>= 1;
            j--;
        }
    }
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            cout << a[i][j];
//        }
//        cout << endl;
//    }
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            if (a[i][j]) {
                cout << "*";
            } else {
                cout << ".";
            }
            if (i != 3) {
                cout << " ";
            }
            if (i == 1)
                cout << " ";
        }
        cout << endl;
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