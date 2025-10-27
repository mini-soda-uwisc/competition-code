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
    int n;
    cin >> n;
    string str;
    cin >> str;
    int index = 0;
    for (int i = 1; i <= n; i++) {
        int x = i;
        string s;
        while (x > 0) {
            char ch = x % 10 +'0';
            x /= 10;
            s.push_back(ch);
        }
        reverse(s.begin(), s.end());

        if (index+s.length() > str.length()) {
            cout << i << "\n";
            exit(0);
        }
        for (int j = 0; j < s.length(); j++) {
            if (str[j + index] != s[j]) {
                cout << i << "\n";
                exit(0);
            }
        }

        index += s.length();
    }
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
