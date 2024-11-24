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

    int a[n], b[n], c[n];
    map<int, int> mp1, mp2, mp3;

    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
        mp1[a[i]]++;
        mp2[b[i]]++;
        mp3[c[i]]++;
    }

    int d[n];
    memset(d, 0, sizeof d);
    for(int i = 0; i < n; i++){
        d[i] = chmax(chmax(mp1[a[i]], mp2[b[i]]), mp3[c[i]]) - 1;
    }

    sort(d, d + n);
    int cnt = 0;

    for(int i = 0, j = 0; j < n; ){
        while(i < n && d[i] < j){
            cnt++;
            i++;
        }
        j++;
        cout << cnt << " ";
    } cout << endl;
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