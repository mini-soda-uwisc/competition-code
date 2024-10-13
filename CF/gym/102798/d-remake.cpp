#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll mulmod(ll a, ll b, ll mod) {
    ll result = 0;
    a %= mod;
    while(b) {
        if(b & 1)
            result = (result + a) % mod;
        a = (2*a) % mod;
        b >>= 1;
    }
    return result;
}

ll binpower(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while(e > 0) {
        if(e & 1)
            result = mulmod(result, base, mod);
        base = mulmod(base, base, mod);
        e >>= 1;
    }
    return result;
}

bool is_prime(ll n) {
    if(n < 2)
        return false;
    for(int64_t x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41}) {
        if(n == x)
            return true;
        if(n % x == 0)
            return false;
    }
    ll s = __builtin_ctzll(n - 1);
    ll d = n >> s;
    for(int64_t a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41}) {
        ll x = binpower(a, d, n);
        if(x == 1 || x == n - 1)
            continue;
        bool composite = true;
        for(ll r = 1; r < s; r++) {
            x = mulmod(x, x, n);
            if(x == n - 1) {
                composite = false;
                break;
            }
        }
        if(composite)
            return false;
    }
    return true;
}

ll pollards_rho(ll n) {
    if(n % 2 == 0)
        return 2;
    ll x = uniform_int_distribution<ll>(2, n-1)(rng);
    ll y = x;
    ll c = uniform_int_distribution<ll>(1, n-1)(rng);
    ll d = 1;
    while(d == 1) {
        x = (mulmod(x, x, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        d = __gcd(abs(x - y), n);
        if(d == n)
            return pollards_rho(n);
    }
    return d;
}

void factorize(ll n, map<ll, int>& factors) {
    if(n == 1)
        return;
    if(is_prime(n)) {
        factors[n]++;
        return;
    }
    ll d = pollards_rho(n);
    factorize(d, factors);
    factorize(n / d, factors);
}

void solve() {
    ll c;
    cin >> c;

    map<ll, int> factors;
    factorize(c, factors);

    bool has_square_factor = false;
    for(auto& p : factors) {
        if(p.second >= 2) {
            has_square_factor = true;
            break;
        }
    }

    if(has_square_factor)
        cout << "yes\n";
    else
        cout << "no\n";
}


//void solve(){
//    ll c;
//    cin >> c;
//
//
//}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}