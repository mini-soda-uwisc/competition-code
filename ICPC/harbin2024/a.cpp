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


struct Trie{
    vector<vector<int>> f;
    vector<int> cnt;

    int n, idx;

    Trie(int _n){
        n = _n;
        idx = 0;

        f.resize(n + 1, vector<int>(26));
        cnt.resize(n + 1);
    }

    void insert(int num){
        int p = 0;
        for(int i = 0; i < 31; i++){
            int u = (num >> i & 1);
            if(!f[p][u]) f[p][u] = ++idx;
            p = f[p][u];
        }
        cnt[p]++;
    }

    int search(int num){
        int p = 0;
        for(int i = 0; i < 31; i++){
            int u = (num >> i & 1);
            if(!f[p][u]) return 0;
            p = f[p][u];
        }
        return cnt[p];
    }
};

void solve(){
    int l, r;
    cin >> l >> r;

    Trie tr(N);
    for(int i = l; i <= r; i++) {
        tr.insert(i);
    }


}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}