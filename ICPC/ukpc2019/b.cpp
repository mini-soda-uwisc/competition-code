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
    string str;
    cin >> str;
    if (str.length() == 1) {
        cout << str[0] << "\n";
    } else {
        if (str[1] <= '4') {
            cout << str[0];
        } else {
            if (str[0] == '9') {
                cout << "10";
            } else {
                cout << char(str[0] + 1);
            }
        }
        for (int i = 0; i < str.length() - 1; ++i) {
            cout << "0";
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
    //  cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
