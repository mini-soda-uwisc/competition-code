#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

#define int long long

inline int fpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

inline void solve() {
//    while(1) {
        int p, q;
        string a, b;
        cin >> p >> q >> a >> b;
//        p = rand() % 5 + 1, q = rand() % 5 + 1;
//        for(int i = 0; i < p; i++){
//            a += rand() % 10 + '0';
//        }
//        for(int i = 0; i < q; i++){
//            b += rand() % 10 + '0';
//        }
//        cout << p << " " << q << endl;
//        cout << a << " " << b << endl;

        int up = stoll(a + b) * 1ll - stoll(a) * 1ll;
        int down = fpow(10, p + q) - fpow(10, p);
        if (up == 0) {
            cout << 0 << ' ' << 1 << '\n';
            return;
        }
        //    cout << "up: " << up << " down: " << down << '\n';
        int d = __gcd(up, down);
        up /= d;
        down /= d;
        cout << up << ' ' << down << '\n';
//    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}