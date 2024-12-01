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

bool cmp(vector<ll> a, vector<ll> b){
    return a[0] > b[0];
}

void solve(){
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> a, b;
    ll f[n + 1], p[n + 1];

    ll qwq = 0, uwu = 0;
    for(int i = 0; i < n; i++){
        ll w, l, r;
        cin >> w >> l >> r;
        a.pb({w, l, r});
        b.pb({w, r - l, (r - l) * w, i});
        qwq += l * w;
        m -= l;
    }
    uwu = qwq;

    sort(b.begin(), b.end(), cmp);

    map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[b[i][3]] = i;
    }

    f[0] = b[0][1];
    p[0] = b[0][2];
    for(int i = 1; i < n; i++){
        f[i] = b[i][1] + f[i - 1];
        p[i] = b[i][2] + p[i - 1];
    }

    for(int i = 0; i < n; i++){
        ll w = a[i][0], l = a[i][1], r = a[i][2];
        ll op = m + l, cur = qwq - l * w;

        ll pl = 0, pr = n;
        while(pl < pr){
            ll mid = pl + pr >> 1;
            if(f[mid] > op) pr = mid;
            else pl = mid + 1;
        }
        if(pl >= n || f[pl] > op) pl--;
        pl = chmax(pl, 0ll);

        ll left = op - f[pl];

        if(pl == 0){
            uwu = chmax(uwu, cur + (left > 0 ? b[0][0] * left : 0));
            continue;
        }

        if(pl >= mp[i]){
            uwu = chmax(uwu, cur + p[mp[i]] + (op - f[mp[i]]) * w);
        }
        else {
            uwu = chmax(uwu,
                        p[pl] + cur + (pl + 1 < n ? b[pl + 1][0] * left : 0));
        }
    }
    cout << uwu << endl;
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