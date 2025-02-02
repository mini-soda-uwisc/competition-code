#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ld = long double;
using ll = long long;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b){
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b){
    return a > b ? b : a;
}

const int N = (int)2e5 + 1, M = N * 2;

void solve(){
    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++){
        s[i] = (char)(s[i] - 'A' + 'a');
    }

    cout << s << endl;
    map<string, int> mp;
    for(int i = 1; i < s.size(); i++){
        if(s[i - 1] == 's' && s[i] == 's'){
            string s1 = s.substr(0, i - 1) + "B" + s.substr(i + 1, s.size() - i - 1);
            mp[s1] = 1;
        }
    }

    for (auto [k, v] : mp) {
        cout << k << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}