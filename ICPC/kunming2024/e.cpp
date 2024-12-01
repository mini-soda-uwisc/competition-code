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
    int n;
    ll k;
    cin >> n >> k;

    ll A[n + 2], a[n + 2], b[n + 2];
    memset(A, 0, sizeof A);
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);

    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }

    for(int i = 1; i <= n; i++){
        a[i] = __gcd(A[i], a[i - 1]);
    }
    for(int i = n; i >= 1; i--){
        b[i] = __gcd(A[i], b[i + 1]);
    }

    ll qwq = a[n];
    for(int i = 1; i <= n; i++){
        if(a[i] != a[i - 1]){
            ll gcd = 0;
            for(int j = i; j <= n; j++){
                gcd = __gcd(gcd, A[j] + k);
//                cout << i << " " << a[i - 1] << " " << gcd << " " << b[j + 1] << endl;
//                cout << __gcd(a[i - 1], __gcd(gcd, b[j + 1])) << endl;
                qwq = chmax(qwq, __gcd(a[i - 1], __gcd(gcd, b[j + 1])));
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
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}