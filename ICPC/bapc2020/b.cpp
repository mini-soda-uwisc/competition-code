#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

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

ll pw[19];

void solve() {
    ll n;
    cin >> n;

    pw[0] = 1;
    for (int i = 1; i <= 18; i++) {
        pw[i] = pw[i - 1] * 10;
    }

    vector<ll> a;
    while (n) {
        string s = to_string(n);
        ll pal = 0, rev = 0;

        if (n < 10) {
            a.push_back(n);
            n = 0;
        }
        else {
            int m = s.size();
            if (n % 10 == 0) {
                pal = 0;
                while (pal * 10 + 9 <= n) {
                    pal = pal *10 + 9;
                }
                a.push_back(pal);
                n -= pal;
                continue;
            }

            for (int i = 0; i < (m + 1) / 2; i++) {
                pal += (s[i] - '0') * pw[m - i - 1];
                rev += (s[i] - '0') * pw[i];

                if (s.size() % 2) {
                    if (i == s.size() / 2) {
                        rev -= (s[i] - '0') * pw[i];
                        if (pal + rev > n) {
                            pal -= pw[m - i - 1];
                        }
                    }
                    else {
                        if (pal + rev > n) {
                            pal -= pw[m - i - 1];
                            rev -= pw[i];
                        }
                    }
                }
                else {
                    if (pal + rev > n) {
                        pal -= pw[m - i - 1];
                        rev -= pw[i];
                    }
                }
            }
            n -= pal + rev;
            a.push_back(pal + rev);
        }
    }

    assert(a.size() <=10);
    cout << a.size() << "\n";
    for (auto A : a) {
        cout << A << "\n";
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

    while (t--) {
        solve();
    }
    // for (int i = 1; i <= 100000; i++) {
    //     solve(i);
    // }
    return 0;
}
