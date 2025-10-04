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

constexpr int NINE = 540;
constexpr int SIX = 360;
constexpr int TEN = 600;

void solve() {
    int mint;
    cin >> mint;
    if (mint >= TEN + 45) {
        cout << 45 + (mint - NINE) << '\n';
    } else if (mint >= NINE + 45) {
        cout << "45\n";
    } else if (mint > NINE) {
        cout << mint - NINE + 30 << '\n';
    } else if (mint >= SIX + 30) {
        cout << "30\n";
    } else if (mint > SIX) {
        cout << mint - SIX << '\n';
    } else {
        cout << "0\n";
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
