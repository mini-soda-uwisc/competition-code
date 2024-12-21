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
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

//    k += 10;
//    cout << s << endl;
//    for(int i = 0; i < k; i++) {
//        s += s;
//        string t = "";
//        for (int j = 0; j < 2 * n; j += 2) {
//            t += s[j];
//        }
//        s = t;
//        cout << t << endl;
//    }

    string qwq = "";
    for(int i = 0, j = 0; i < n * 2; i += 2, j++){
        qwq += s[(i * qpow(2, k - 1, n)) % n];
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
//    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}