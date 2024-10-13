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

const int N = (int)3e4 + 1, M = N * 2;

vector<int> primes;
int isComposite[N];
ld f[N];

void euler() {
    for (int i = 2; i < N; ++i) {
        if (!isComposite[i]) {
            primes.push_back(i);
        }
        for (size_t j = 0; j < primes.size() && i * primes[j] < N; ++j) {
            isComposite[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    cout << setprecision(20) << f[n] << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    int t = 1;
    cin >> t;

    for(int i = 0; i < N; i++){
        f[i] = 0;
    }

    euler();
    for(int i = 0; i < primes.size(); i++){
        for(int j = N - 1 ; j >= primes[i]; j--){
            f[j] = chmax(f[j], f[j - primes[i]] + log(primes[i]));
        }
    }

    while(t--){
        solve();
    }

    return 0;
}