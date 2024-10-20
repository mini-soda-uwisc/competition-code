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

const int N = (int)2e5 + 1, M = 25;

ll f[N][M], w[N];
int n;

void upd() {
    for (int j = 0; j < M; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            if (j == 0) {
                f[i][j] = w[i];
            } else {
                f[i][j] = chmin(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
}

ll qr(int l, int r) {
    int len = r - l + 1;
    int k = log2(len);
    return chmin(f[l][k], f[r - (1 << k) + 1][k]);
}

int get_left(int i) {
    int l = 1, r = i;
    while (l < r) {
        int m = (l + r) / 2;
        if (qr(m, i) >= w[i]) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    while(l <= n && qr(l, i) < w[i]){
        l++;
    }
    while(l >= 0 && qr(l - 1, i) >= w[i]){
        l--;
    }
    return l;
}

int get_right(int i) {
    int l = i, r = n;
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (qr(i, m) >= w[i]) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    while(l >= 0 && qr(i, l) < w[i]){
        l--;
    }
    while(l <= n && qr(i, l + 1) >= w[i]){
        l++;
    }
    return l;
}

void solve(){
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            f[i][j] = -1;
        }
    }

    upd();

    ll ans = -1, dl = 0, dr = 0;
    for(int i = 1; i <= n; i++){
        ll l = get_left(i), r = get_right(i);
        if((r - l + 1) * w[i] > ans){
            ans = (r - l + 1) * w[i];
            dl = l;
            dr = r;
        }
    }
    cout << dl << " " << dr << " " << ans << endl;
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