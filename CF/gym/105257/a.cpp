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

string getPermission(char digit) {
    switch (digit) {
        case '0': return "---";
        case '1': return "--x";
        case '2': return "-w-";
        case '3': return "-wx";
        case '4': return "r--";
        case '5': return "r-x";
        case '6': return "rw-";
        case '7': return "rwx";
        default: return "---";
    }
}

void solve(){
    string s;
    cin >> s;

    string permissions;
    for (int i = 0; i < 3; i++) {
        permissions += getPermission(s[i]);
    }

    cout << permissions << "\n";
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}