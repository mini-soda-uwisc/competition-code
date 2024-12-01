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

template <typename T>
struct Z{
    static const T Mod = (T)998244353;
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

const int N = (int)2e5 + 1, M = N * 2;
int h[N], ne[M], e[M], idx, n;
Z<ll> qwq, f[N], p[N];

void add(int u, int v){
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void dfs(int u, int fa){
    p[u] = 1, f[u] = 0;
    Z<ll> owo = n, uwu = 2;

    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == fa) continue;
        dfs(j, u);
        qwq = qwq + uwu * (f[u] * f[j]);
        qwq = qwq + uwu * (owo - p[j]) * (owo - p[j]) * (f[j] - p[j] * p[j]);
        p[u] = p[u] + p[j];
        f[u] = f[u] + f[j];
    }
    f[u] = f[u] + p[u] * p[u];
    qwq = qwq + (p[u] * p[u]) * (owo - p[u]) * (owo - p[u]);
}

void solve(){
    cin >> n;

    for(int i = 0; i <= n; i++){
        h[i] = -1;
    }
    idx = 0;
    qwq = 0;

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    dfs(1, 1);

    Z<ll> base = n * 1ll * (n - 1) / 2;
    cout << qwq * base.inverse(base * base) << endl;
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