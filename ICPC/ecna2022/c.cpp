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

void solve() {
    int n;
    cin >> n;

    vector<int> a, ap;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c == 'T' || c == 'J' || c == 'Q' || c == 'K') a.pb(10);
        else if (c == 'A') a.pb(1);
        else a.pb(c - '0');

        if(c == 'A') ap.pb(1);
        else if(c == 'T') ap.pb(10);
        else if(c == 'J') ap.pb(11);
        else if(c == 'Q') ap.pb(12);
        else if(c == 'K') ap.pb(13);
        else ap.pb(c - '0');
    }

    map<int, int> mp;
    for(int i = 0; i < a.size(); i++){
        mp[ap[i]]++;
    }

    sort(a.begin(), a.end());
    sort(ap.begin(), ap.end());

    auto get15= [&]() -> ll{
        ll f[16];
        memset(f, 0, sizeof f);

        f[0] = 1;
        for(int i = 0; i < a.size(); i++){
            for(int j = 15; j >= a[i]; j--){
                f[j] += f[j - a[i]];
            }
        }
        return f[15] * 2;
    };

    auto pairs = [&]() -> ll{
        ll qwq = 0;
        for(int i = 1; i <= 13; i++){
            if(mp[i] >= 2){
                qwq += mp[i] * 1ll * (mp[i] - 1);
            }
        }
        return qwq;
    };

    auto runs = [&]() -> ll{
        ll qwq = 0;
        vector<vector<int>> b;
        for(int i = 0; i < a.size(); i++){
            if(b.empty() || b.back()[0] != ap[i]){
                b.pb({ap[i], 1});
            }
            else{
                b.back()[1]++;
            }
        }

        ll owo = 1, c = 0;
        for(int i = 0; i < b.size(); i++){
            if(i){
                if(b[i][0] - b[i - 1][0] != 1){
                    if(c > 2){
                        qwq += owo * c;
                    }
                    c = 1;
                    owo = b[i][1];
                }
                else{
                    c++;
                    owo *= b[i][1];
                }
            }
            else{
                owo = b[i][1];
                c++;
            }
        }
        if(c > 2){
            qwq += owo * c;
        }
        return qwq;
    };

    cout << get15() + pairs() + runs() << endl;
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