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

const int N = (int)2e5 + 1, M = N * 2;
ll pre[N];

void simulate(int A, int B, int C) {
    cout << "Get: " << A << ' ' << B << ' ' << C << '\n';
    while (A != 0 && B != 0
        || A != 0 && C != 0
        || B != 0 && C != 0) {
        int a = A, b = B, c = C;
        // A attack
        if (A != 0) {
            if (B > C) {
                b--;
            } else if (C > B) {
                c--;
            } else if (C == B) {
                b--;
            }
        }

        // B attack
        if (B != 0) {
            if (A > C) {
                a--;
            } else if (C > A) {
                c--;
            } else if (C == A) {
                c--;
            }
        }

        // C attack
        if (C != 0) {
            if (A > B) {
                a--;
            } else if (B > A) {
                b--;
            } else if (A == B) {
                a--;
            }
        }

        A = a;
        B = b;
        C = c;
    }

    if (A == 0 && B == 0 && C == 0) {
        cout << "Rubble!\n";
    } else if (A > 0) {
        cout << "A " << A << '\n';
    } else if (B > 0) {
        cout << "B " << B << '\n';
    } else if (C > 0) {
        cout << "C " << C << '\n';
    }
    // exit(0);
}

void solve() {
    for (int i = 0; i < 100; i++) {
        simulate(i, 100, 100);
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
