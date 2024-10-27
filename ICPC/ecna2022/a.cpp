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

    const int N = (int)1e4 + 1, M = N * 2;

    void solve(){
        int n, m;
        cin >> n >> m;

        ll a[m + 1];
        for(int i = 1; i <= m; i++){
            cin >> a[i];
        }

        vector<bitset<N>> f(n + 1);
        f[0][0] = 1;

        for(int i = 1; i <= m; i++){
            for(int j = n; j >= 0; j--){
                f[j] |= f[j] << a[i];
                if(j >= a[i]){
                    f[j] |= f[j - a[i]];
                }
            }
        }

        ll l = 0, r = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= i; j++){
                if(f[i][j]) {
                    if (i + j > l + r) {
                        l = i;
                        r = j;
                    }
                    else if (i + j == l + r) {
                        if (i - j < l - r) {
                            l = i;
                            r = j;
                        }
                    }
                }
            }
        }

        cout << l << " " << r << endl;
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