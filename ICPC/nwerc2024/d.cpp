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

ll qpow(ll a, ll b, ll m){
    ll res = 1;
    a = a % m;

    while(b > 0){
        if(b % 2 == 1){
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }

    return res;
}

void solve(){
    int n;
    cin >> n;

    int a[n], owo = 0;
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        owo = chmax(a[i], owo);
    }

    ll qwq = 0;
    sort(a, a + n);
    for(int i = 1; i <= n; i++){
        qwq += a[i];
    }
    qwq /= 2;

    ll f[n + 1][n + 1][qwq + owo + 1];
    memset(f, 0, sizeof f);

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            f[i][j][0] = 1;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = i - 1; j <= n; j++){
            for(int k = qwq + a[j]; k >= a[i]; k--){
                if(k - a[j] > qwq){
                    continue;
                }
                f[i][j][k] |= f[i - 1][j][k - a[i]];
            }
        }
    }

    map<int, int> mp;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            for (int k = qwq + 1; k <= qwq + owo; k++) {
                if (f[i][j][k]) {
                    mp[k] = 1;
                }
            }
        }
    }
    cout << mp.size() << endl;
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