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

int dp[N][10];

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (j != k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                }
            }
        }
    }
}

void solve(){
    string s, t;
    cin >> s >> t;

    auto calc = [&](string s) -> ll {
        if (s.size() < 2) {
            return s[0] - '0';
        }
        vector<int> a;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            a.pb(s[i] - '0');
        }

        ll qwq = 0, owo = -1, uwu = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            for (int j = 0; j < a[i]; j++) {
                if (j == owo) {
                    continue;#include <bits/stdc++.h>
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

int dp[N][10];

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (j != k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                }
            }
        }
    }
}

void solve(){
    string s, t;
    cin >> s >> t;

    auto calc = [&](string s) -> ll {
        if (s.size() < 2) {
            return s[0] - '0';
        }
        vector<int> a;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            a.pb(s[i] - '0');
        }

        ll qwq = 0, owo = -1, uwu = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            for (int j = 0; j < a[i]; j++) {
                if (j == owo) {
                    continue;
                }
                qwq = (qwq + dp[i + 1][j]) % mod;
            }

            if (i != a.size() - 1 && a[i] == a[i + 1]) {
                uwu = 1;
            }
            owo = a[i];
            if (i == 0 && !uwu) {
                qwq++;
            }
        }

        // for (int i = 1; i < a.size(); i++) {
        //     for (int j = 1; j <= 9; j++) {
        //         qwq += dp[i][j];
        //     }
        // }
        cout << qwq << endl;
        return qwq;
    };

    int rep = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            rep = 0;
        }
    }
    cout << (calc(t) - calc(s) + rep + mod) % mod << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;
    init();

    while(t--){
        solve();
    }

    return 0;
}

                }
                qwq = (qwq + dp[i + 1][j]) % mod;
            }

            if (i != a.size() - 1 && a[i] == a[i + 1]) {
                uwu = 1;
            }
            owo = a[i];
            if (i == 0 && !uwu) {
                qwq++;
            }
        }

        // for (int i = 1; i < a.size(); i++) {
        //     for (int j = 1; j <= 9; j++) {
        //         qwq += dp[i][j];
        //     }
        // }
        cout << qwq << endl;
        return qwq;
    };

    int rep = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            rep = 0;
        }
    }
    cout << (calc(t) - calc(s) + rep + mod) % mod << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;
    init();

    while(t--){
        solve();
    }

    return 0;
}
