#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ld = long double;
using ll = long long;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b){
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b){
    return a > b ? b : a;
}

const int N = (int)2e5 + 1, M = N * 10;

template <typename T>
struct Z{
    static const T Mod = (T)1e9 + 7;
    T num;
 
    Z() : num(0) {}
 
    Z(T n) : num(n % Mod) {
        if (num < 0) num += Mod;
    }
 
    Z operator+(const Z& other) const{
        T res = num + other.num;
        if (res >= Mod) res -= Mod;
        return Z(res);
    }
 
    Z operator-(const Z& other) const{
        T res = num - other.num;
        if (res < 0) res = (res + Mod) % Mod;
        return Z(res);
    }
 
    Z operator*(const Z& other) const{
        return Z(num * other.num % Mod);
    }
 
    Z operator/(const Z& other) const{
        return *this * qpow(other, Mod - 2);
    }
 
    bool operator >=(const Z& other) const{
        return num >= other.num;
    }
 
    bool operator <=(const Z& other) const{
        return num <= other.num;
    }
 
    bool operator >(const Z& other) const{
        return num > other.num;
    }
 
    bool operator <(const Z& other) const{
        return num < other.num;
    }
 
    friend constexpr bool operator==(Z a, Z b){
        return a.num == b.num;
    }
 
    friend constexpr bool operator!=(Z a, Z b){
        return a.num != b.num;
    }
 
    constexpr Z &operator*=(Z z) &{
        num = 1LL * num * z.num % Mod;
        return *this;
    }
 
    constexpr Z &operator+=(Z z) &{
        num = (num + z.num + Mod) % Mod;
        return *this;
    }
 
    constexpr Z &operator-=(Z z) &{
        num = (num - z.num + Mod) % Mod;
        return *this;
    }
 
    constexpr Z &operator/=(Z z) &{
        return *this *= inverse(z);
    }
 
    static Z qpow(const Z& v, T k){
        T val = v.num;
        T ret = 1;
        for(k %= Mod - 1; k > 0; k >>= 1, val = val * val % Mod){
            if(k & 1){
                ret = ret * val % Mod;
            }
        }
        return Z(ret);
    }
 
    static Z inverse(const Z& v){
        return qpow(v, Mod - 2);
    }
 
    friend ostream& operator<<(ostream& os, const Z& z){
        os << z.num;
        return os;
    }
};

template <typename T>
struct Binom {
public:
    vector<Z<T>> ft;  
    vector<Z<T>> ift; 
 
    Binom(int n) : ft(n + 1), ift(n + 1) {
        ft[0] = Z<T>(1);
 
        for (int i = 1; i <= n; i++) {
            ft[i] = ft[i - 1] * Z<T>(i);
        }
        ift[n] = Z<T>::inverse(ft[n]);
 
        for (int i = n - 1; i >= 0; i--) {
            ift[i] = ift[i + 1] * Z<T>(i + 1);
        }
        ift[0] = ift[1];
    }
 
    Z<T> operator()(int n, int r) const {
        if (n < 0 || n >= ft.size() || r < 0 || r > n) return Z<T>(0);
        return ft[n] * ift[n - r] * ift[r];
    }
 
    Z<T> comb(int n, int k) const {
        if (k == 0) return Z<T>(1);
        return (*this)(n, k);
    }
 
    Z<T> sumComb(int n) const {
        return Z<T>::pow(Z<T>(2), n) - Z<T>(2);
    }
 
    Z<T> perm(int n, int k) const {
        if (k == 0) return Z<T>(1);
        return (*this)(n, k) * ft[k];
    }
 
    Z<T> fact(int n) const {
        if (n == 0) return Z<T>(1);
        return ft[n];
    }
 
    Z<T> cata(int n) const {
        return (*this)(2 * n, n) / Z<T>(n + 1);
    }
};

void solve(){
    int n, m;
    cin >> n >> m;

    Binom<ll> binom(n * 2);
    ll a[m + 1];

    ll uwu = 0;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
        uwu += a[i];
    }
    vector<Z<ll>> f(m + 2);
    f[m + 1] = binom.fact(n - uwu);

    for(int i = m; i >= 1; i--){
        int qwq = 0;
        for(int j = i; j <= m; j++){
            qwq += a[j];
            f[i] += f[j + 1] * binom.fact(qwq);
        }
        f[i] = binom.fact(qwq + n - uwu) - f[i];
    }
    cout << f[1] << endl;   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}