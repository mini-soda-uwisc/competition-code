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

struct CartesianTree{
    int n;
    vector<int> a, l, r;

    CartesianTree(int _n) : n(_n), a(_n), l(_n, -1), r(_n, -1){

    }

    int work(){
        stack<int> s;
        for(int i = 0; i < n; i++){
            int last = -1;
            while(!s.empty() && a[s.top()] < a[i]){
                last = s.top();
                s.pop();
            }
            if(!s.empty()){
                r[s.top()] = i;
            }
            if(last != -1){
                l[i] = last;
            }
            s.push(i);
        }

        int rt = 0;
        while(!s.empty()){
            rt = s.top();
            s.pop();
        }
        return rt;
    }
};

void solve(){
    int n;
    cin >> n;

    CartesianTree tr(n + 1);
    for(int i = 0; i < n; i++){
        cin >> tr.a[i];
    }
    int rt = tr.work();

    ll qwq = 0;
    vector<vector<ll>> dp(n + 1, vector<ll>(2));

    auto dfs = [&](auto& self, int u) -> void {
        if (u < 0 || u >= n) {
            return;
        }
        dp[u][0] = dp[u][1] = 1;

        if (tr.l[u] != -1) {
            self(self, tr.l[u]);
            qwq += dp[tr.l[u]][1];
            // cout << u << " " << tr.l[u] << " " << dp[tr.l[u]][1] << endl;
            dp[u][0] += dp[tr.l[u]][0];
        }
        if (tr.r[u] != -1) {
            self(self, tr.r[u]);
            qwq += dp[tr.r[u]][0];
            // cout << u << " " << tr.r[u] << " " << dp[tr.r[u]][0] << endl;
            dp[u][1] += dp[tr.r[u]][1];
        }
    };

    dfs(dfs, rt);
    cout << qwq << endl;
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
