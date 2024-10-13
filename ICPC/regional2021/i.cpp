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

void solve() {
    int n, m;
    cin >> n >> m;
    int f[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = 0;
        }
    }

    char c[n + 1][m + 1];
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++){
            c[i][j] = s[j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + (c[i][j] == '#');
        }
    }

    ld dp[n + 1][m + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = i + j;
        }
    }

    ld b = 1.0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 0; k <= i; k++){
                for(int l = 0; l <= j; l++){
                    int car = f[i][j] - f[k][j] - f[i][l] + f[k][l];
                    if(car == 0){
                        dp[i][j] = chmin(dp[i][j], dp[k][l] + sqrt(b * (i - k) * (i - k) + (j - l) * (j - l)));
                    }
                    dp[i][j] = chmin(dp[i][j], dp[k][l] + abs(i - k) + abs(j - l));
                }
            }
        }
    }
    cout << setprecision(20) << dp[n][m] << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}