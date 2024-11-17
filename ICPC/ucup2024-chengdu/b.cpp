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
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    ll f[n + 1][n + 1][n + 1];
    s = " " + s;

    memset(f, 0, sizeof f);

    map<int, int> mp;
    int empty = 0;

    f[0][0][0] = 1;

    for(int i = 1; i <= n; i++){
        if(s[i] == '?'){
            empty++;
            mp[empty] = i;
        }
        for(int j = 0; j <= i; j++){
            for(int k = 0; k + j <= i; k++){
                if(s[i] != '?'){
                    f[i][j][k] = f[i - 1][j][k];
                }
                else{
                    if(i == 1 && i + 1 <= n){
                        if(s[i + 1] == 'a'){
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1]) % mod;
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j][k]) % mod;
                        }
                        if(s[i + 1] == 'b'){
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k]) % mod;
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j][k]) % mod;
                        }
                        if(s[i + 1] == 'c'){
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k]) % mod;
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1]) % mod;
                        }
                    }
                    if(i == n && i - 1 >= 1){
                        if(s[i + 1] == 'a'){
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1]) % mod;
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j][k]) % mod;
                        }
                        if(s[i + 1] == 'b'){
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k]) % mod;
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j][k]) % mod;
                        }
                        if(s[i + 1] == 'c'){
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k]) % mod;
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1]) % mod;
                        }
                    }
                    else{
                        if((s[i - 1] == 'a' && s[i + 1] == 'b') && (s[i - 1] == 'b' && s[i + 1] == 'a')){
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j][k]) % mod;
                        }
                        if((s[i - 1] == 'a' && s[i + 1] == 'c') || (s[i - 1] == 'c' && s[i + 1] == 'a')){
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1]) % mod;
                        }
                        if((s[i - 1] == 'b' && s[i + 1] == 'c') || (s[i - 1] == 'c' && s[i + 1] == 'b')){
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k]) % mod;
                        }
                        if(s[i - 1] == 'a' && s[i + 1] == 'a'){
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1]) % mod;
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j][k]) % mod;
                        }
                        if(s[i - 1] == 'b' && s[i + 1] == 'b'){
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k]) % mod;
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j][k]) % mod;
                        }
                        if(s[i - 1] == 'c' && s[i + 1] == 'c'){
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k]) % mod;
                            f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1]) % mod;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cout << f[mp[a + b + c]][a][b] << endl;
    }
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