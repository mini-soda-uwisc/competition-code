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
    int n, m;
    cin >> n >> m;

    vector<string> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.pb(s);
    }

    int qwq = 0;
    for (int i = 0; i < 1 << m; i++) {
        int owo = (int)1e9;
        for (int j = 0; j < n; j++) {
            int uwu = 0;
            for (int k = 0; k < m; k++) {
                if (a[j][k] == 'T' && (i >> k & 1)) {
                    uwu++;
                }
                if (a[j][k] == 'F' && !(i >> k & 1)) {
                    uwu++;
                }
            }
            owo = chmin(uwu, owo);
        }
        qwq = chmax(qwq, owo);
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
