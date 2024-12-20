#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 1e9 + 7;
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
    ll x;
    cin >> x;
    if(x <= 8){
        cout << x << endl;
    }
    else if(x % 2 == 0){
        cout << x / 2 % mod << endl;
    }
    else{
        if(x <= 29){
            int qwq = 0;
            auto dfs = [&](auto& self, int x, int t, vector<int> a) -> void{
                int sum = 0, c = 9, f[c + 1];
                memset(f, 0, sizeof f);
                f[0] = 1;

                for(int i = 0; i < a.size(); i++){
                    for(int j = c; j >= a[i]; j--){
                        f[j] |= f[j - a[i]];
                    }
                }

                if(f[c]) return;

                for(int i = 0; i < a.size(); i++){
                    sum += a[i];
                }
                if(sum == t){
                    qwq = chmax(qwq, (int)a.size());
                }

                for(int i = 1; i <= x; i++){
                    a.pb(i);
                    self(self, x - i, t, a);
                    a.pop_back();
                }
            };

            vector<int> a;
            dfs(dfs, x, x, a);
            cout << qwq << endl;
        }
        else{
            cout << ((x - 11) / 2 % mod + 1) % mod << endl;
        }
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}