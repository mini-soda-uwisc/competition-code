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
    int n, k;
    cin >> n >> k;

    vector<string> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.pb(s);
    }

    int s[k + 1][k + 1];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            s[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int p = 0; p < j; p++) {
                s[a[i][p] - 'A'][a[i][j] - 'A'] = 0;
            }
        }
    } // s[i][j] = i > j
    // for (int i = 0; i <k ;i++) {
    //     for (int j = 0; j < k; j++) {
    //         cout << i << " " << j << " " << " is greater?: " << s[i][j] << endl;
    //     }
    //     cout << endl;
    // }

    int qwq = 1, dp[k];
    for (int i = 0; i < k; i++) {
        dp[i] = 1;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < i; j++) {
            if (s[a[0][i] - 'A'][a[0][j] - 'A']) {
                dp[i] = chmax(dp[i], dp[j] + 1);
                qwq = chmax(qwq, dp[i]);
            }
        }
    }
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
