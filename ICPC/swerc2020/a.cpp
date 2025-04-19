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
    int n, k;
    cin >> n >> k;
    getchar();
    vector<tuple<int, int, string>> a;
    map<string, int> mp, time;

    for(int i = 0; i < 3 * n; i++){
        string s;
        getline(cin, s);

        time[s] = i;
        mp[s]++;
    }

    for (auto [k, v] : mp) {
        a.pb({mp[k], time[k], k});
    }

    auto cmp = [&](tuple<int, int, string> a, tuple<int, int, string> b)-> int{
        return get<0>(a) == get<0>(b) ? get<1>(a) > get<1>(b) : get<0>(a) > get<0>(b);
    };

    sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < chmin(k, (int)a.size()); i++) {
        cout << get<2>(a[i]) << endl;
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
