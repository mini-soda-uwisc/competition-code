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
    string s;
    cin >> s;

    int n = s.size(), dp[10][10];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i < n; i++) {
        dp[s[i - 1] - '0'][s[i] - '0']++;
    }

    int p[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ll qwq = INF;
    do {
        int ndp[10][10];
        memset(ndp, 0, sizeof ndp);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                ndp[p[i]][p[j]] = abs(i - j) + 1;
            }
        }

        ll owo = 0;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                owo += dp[i][j] * ndp[i][j];
            }
        }
        int offset = 0;

        for (int i = 0; i < 9; i++) {
            if (p[i] == s[0] - '0') {
                offset = i + 1;
            }
        }
        qwq = chmin(qwq, owo + offset);
    } while (next_permutation(p, p + 9));

    cout << qwq << endl;
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
