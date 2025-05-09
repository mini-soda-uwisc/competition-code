#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template <typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)2e5 + 1, M = N * 2;
ll pre[N];

void solve() {
    int n, m;
    cin >> n >> m;

    ll a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    b[0] = a[0];
    for(int i = 1; i < n; i++){
        b[i] = b[i - 1] + a[i];
    }

    ll qwq = 0;
    for(int i = 0, j = 0; j < n; ){
        if(j <= i){
            pre[j] += 1;
            pre[i + 1] -= 1;
        }

        if(i + 1 >= n){
            j++;
        }
        else if(b[i + 1] - (j == 0 ? 0 : b[j - 1]) > m){
            qwq -= a[j++];
        }
        else{
            i++;
        }
    }

    for(int i = 1; i <= n; i++){
        pre[i] += pre[i - 1];
    }

    for(int i = 0; i < n; i++){
        cout << pre[i] << endl;
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
