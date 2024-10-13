#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;

int mod = (int)1e9 + 7;
ll inf = (ll)1e18;

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

bool cmp(vector<ll> a, vector<ll> b){
    return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1];
}

void solve(){
    int n, m;
    cin >> n >> m;

    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    vector<vector<ll>> vec, v1, v2, q, p;
    for(int i = 0; i < n; i++){
        vec.pb({a[i], b[i]});
    }

    sort(vec.begin(), vec.end(), cmp);

    int k = n / 2, l = n - k;
    for(int i = 0; i < k; i++){
        v1.pb(vec[i]);
    }
    for(int i = k; i < n; i++){
        v2.pb(vec[i]);
    }

    for(int i = 0; i <= 1 << k; i++){
        vector<ll> uwu, cp;
        ll owo = 0, qwq = 0, qaq = 0;
        for(int j = 0; j < k; j++){
            if(i >> j & 1){
                uwu.pb(v1[i][1]);
                owo += v1[i][0];
            }
        }
        if(m >= owo && owo){
            sort(uwu.begin(), uwu.end());
            for(int i = 0; i < uwu.size(); i++){
                qwq += uwu[i] * i;
                qaq += uwu[i];
            }
            q.pb({owo, qwq, uwu});
        }
    }

    for(int i = 0; i <= 1 << l; i++){
        vector<ll> uwu, cp;
        ll owo = 0, qwq = 0;
        for(int j = 0; j < l; j++){
            if(i >> j & 1){
                uwu.pb(v2[i][1]);
                owo += v2[i][0];
            }
        }
        if(m >= owo && owo){
            sort(uwu.begin(), uwu.end());
            for(int i = 0; i < uwu.size(); i++){
                qwq += uwu[i] * i;
            }
            p.pb({uwu.size(), owo, qwq});
        }
    }

    sort(p.begin(), p.end());
    ll f[p.size() + 1][2];
    for(int i = 0; i < p.size(); i++){
        f[i][0] = f[i][1] = 0;
    }

    for(int i = 0; i < p.size(); i++){
        if(!i){
            f[i][0] = p[i][0];
            f[i][1] = p[i][2];
        }
        else{
            if(f[i - 1][0] < p[i][0]){
                f[i][0] = p[i][0];
                f[i][1] = p[i][2];
            }
            else if(f[i - 1][0] == p[i][0]){
                f[i][0] = p[i][0];
                f[i][1] = chmax(p[i][2], f[i - 1][1]);
            }
            else{
                f[i] = f[i - 1];
            }
        }
    }

    ll orz = 0;
    for(int i = 0; i < q.size(); i++){
        ll d = m - q[i][0];
        int l = 0, r = p.size();
        while(l < r){
            int mid = l + r >> 1;
            if(p[mid][1] > d) r = mid;
            else l = mid + 1;
        }
        orz = chmax(orz, q[i][0] + f[l][0] * q[i][2] + f[l][1]);
    }
    cout << orz << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
