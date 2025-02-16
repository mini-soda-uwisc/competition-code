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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] += (int)2e5;
    }

    auto f = [&](int x) -> ll {
        ll qwq = 0;
        for (int i = 0, j = x; i < n; i++, j++) {
            qwq += abs(a[i] - j);
        }
        return qwq;
    };

    ll uwu = INF;
    auto search1 = [&](int l, int r) -> void{
        while(l < r - 1){
           int mid  = (l + r) / 2;
           int mmid = (mid + r) / 2;

           uwu = chmin(f(mid), chmin(uwu, f(mmid)));
           if(f(mid) <= f(mmid)){
               r = mmid;
           }
           else{
               l = mid;
           }
        }
        for (int i = l; i <= r; i++) {
            uwu = chmin(uwu, f(i));
        }
    };

    auto search2 = [&](int l, int r) -> void{
        while(l < r - 1){
            int mid  = (l + r) / 2;
            int mmid = (mid + r) / 2;

            uwu = chmin(f(mid), chmin(uwu, f(mmid)));
            if(f(mid) < f(mmid)){
                r = mmid;
            }
            else{
                l = mid;
            }
        }
        for (int i = l; i <= r; i++) {
            uwu = chmin(uwu, f(i));
        }
    };

    search1(0, (int)5e5);
    search2(0, (int)5e5);
    cout << uwu << endl;
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
