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



ll exgcd(ll a, ll b, ll& x, ll& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll crt(vector<ll>& a, vector<ll>& m, ll f){
    ll x = 0, m1 = m[0], a1 = a[0];

    for(int i = 1; i < a.size(); i++){
        ll m2 = m[i], a2 = a[i], k1 = 0, k2 = 0;
        ll d = exgcd(m1, m2, k1, k2);
        if((a2 - a1) % d > 0){
            x = -1;
            break;
        }
        k1 *= (a2 - a1) / d;
        k1 = (k1 % (m2 / d) + m2 / d) % (m2 / d);
        x = k1 * m1 + a1;
        ll c = fabs(m1 / d * m2);
        a1 = k1 * m1 + a1;
        m1 = c;
    }

    if (x < f) {
        ll dx = f - x;
        ll k = (dx + m1 - 1) / m1;
        x += k * m1;
    }
    return x;
}

void solve(){
    ll a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    vector<ll> p;

    for (int k = 1; k < chmin(a / 2, b / 2); k++) {
        p.pb((a - 2 * k) * (b - 2 * k) * k);
    }

    while (p.size() < 3) {
        p.pb(0);
    }
    vector<ll> A(3), X(3);
    A[0] = c;
    A[1] = d;
    A[2] = e;

    sort(p.begin(), p.end(), greater<ll>());
    X[0] = p[0];
    X[1] = p[1];
    X[2] = p[2];

    cout << crt(A, X, f) << endl;
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
