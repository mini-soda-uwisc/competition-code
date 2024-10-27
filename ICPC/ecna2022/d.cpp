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
    string s;
    cin >> s;

    int n = s.length(), m;
    cin >> m;

    int f[n + 1][4];
    memset(f, 0, sizeof f);

    map<char, int> mp;
    mp['A'] = 0;
    mp['T'] = 1;
    mp['G'] = 2;
    mp['C'] = 3;

    map<int, int> rec;
    rec[0] = 'A';
    rec[1] = 'T';
    rec[2] = 'G';
    rec[3] = 'C';

    for(int i = 1; i <= n; i++){
        f[i][mp[s[i - 1]]]++;
        for(int j = 0; j < 4; j++){
            f[i][j] += f[i - 1][j];
        }
    }

    while(m--){
        int l, r;
        cin >> l >> r;

        vector<vector<int>> b;

        for(int i = 0; i < 4; i++){
            b.pb({-(f[r][i] - f[l - 1][i]), i});
        }

        sort(b.begin(), b.end());
        string s = "";
        for(int i = 0; i < 4; i++){
            s += rec[b[i][1]];
        }
        cout << s << endl;
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