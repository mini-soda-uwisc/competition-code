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
    set<int> s;
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        a[i] = x;
        s.insert(x);
    }

    s.insert(0);
    for(int i = 1; i < n; i++){
        int qwq = a[i - 1], owo = a[i], uwu = qwq | owo;
        s.insert(a[i] ^ a[i - 1]);
        s.insert(a[i] | a[i - 1]);
        s.insert(a[i] & a[i - 1]);
        s.insert(uwu ^ qwq);
        s.insert(uwu ^ owo);
    }

    cout << s.size() << endl;
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