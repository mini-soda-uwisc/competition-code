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
    cin >> n;

    ld a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll qwq = 0;
    for(int i = n; i >= 1; i--){
        ll exp = 0;
        for(int j = 0; j < 1 << i; j++){
            ll owo = 1;
            for(int k = 0; k < i; k++){
                if(j >> k & 1) owo *= a[k];
                else owo *= (1 - a[k]);
            }
            exp += owo;
        }
        qwq += exp * 1ll / (i << i);
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