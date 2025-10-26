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

string s;
int states[10];

void solve(){
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c == 'A') {
            if (states[6]) {
                --states[6];
                ++states[0];
            } else if (states[2]) {
                --states[2];
                ++states[4];
            } else if (states[3]) {
                --states[3];
                ++states[5];
            } else if (states[0]) {
                --states[0];
                ++states[1];
            } else {
                ++states[1];
            }
        } else if (c == 'B') {
            if (states[5]) {
                --states[5];
                ++states[0];
            } else if (states[1]) {
                --states[1];
                ++states[4];
            } else if (states[3]) {
                --states[3];
                ++states[6];
            } else if (states[0]) {
                --states[0];
                ++states[2];
            } else {
                ++states[2];
            }
        } else {
            if (states[4]) {
                --states[4];
                ++states[0];
            } else if (states[1]) {
                --states[1];
                ++states[5];
            } else if (states[2]) {
                --states[2];
                ++states[6];
            } else if (states[0]) {
                --states[0];
                ++states[3];
            } else {
                ++states[3];
            }
        }
    }

    for (int i = 1; i <= 6; ++i) {
        assert(states[i] == 0);
    }

    cout << states[0] << '\n';
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
