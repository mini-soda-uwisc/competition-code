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
    int n, k, t;
    cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> b;
    ll qwq = 0;

    for(int i = 0; i < n; i++){
        b.pb((a[i] / k + 1) * k - a[i]);
        qwq += a[i] / k;
    }

    sort(b.begin(), b.end());
    cin >> t;

    for(int i = 0; i < b.size(); i++){
        if(t >= b[i]){
            qwq += 1;
            t -= b[i];
        }
    }

    qwq += t / k;
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