#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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

const int N = (int)1e4 + 1, M = N * 2;

void solve(){
    int n;
    cin >> n;

    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    string s;
    getchar();
    getline(cin, s);

    while (s.size() % n != 0) {
        s += ' ';
    }
    string t = "" ;
    for (int i = n - 1; i < s.size(); i += n) {
        vector<int> mat(n);
        for (int j = i - n + 1, k = 0; j <= i; j++, k++) {
            if (s[j] == ' ') {
                mat[k] = 36;
            }
            else if (s[j] - 'A' >= 0 && s[j] - 'A' <= 25) {
                mat[k] = s[j] - 'A';
            }
            else {
                mat[k] = s[j] - '0' + 26;
            }
        }

        for (int j = 0; j < n; j++) {
            int qwq = 0;
            for (int k = 0; k < n; k++) {
                qwq += mat[k] * a[j][k];
                qwq %= 37;
            }

            if (qwq <= 25) {
                t += (char)('A' + qwq);
            }
            else if (qwq == 36) {
                t += ' ';
            }
            else {
                t += to_string(qwq - 26);
            }
        }
    }
    cout << t << endl;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
