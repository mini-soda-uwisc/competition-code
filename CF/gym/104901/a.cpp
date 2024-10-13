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

int getType(char c) {
    if (c == '(' || c == ')') return 1;
    return 2;
}

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    s = " " + s;

    vector<pair<int, int>> ranges[5];
    int beg = 0;
    for (int i = 1; i <= n; ++i) {
        if (getType(s[i]) != getType(s[beg])) {
            ranges[getType(s[beg])].pb({beg, i - 1});
            beg = i;
        }
    }
    ranges[getType(s[beg])].pb({beg, n});

//    for (int type = 1; type <= 2; ++type) {
//        cout << "vector[" << type << "]:\n";
//        for (auto [l, r] : ranges[type]) {
//            cout << "{" << l << ", " << r << "}\n";
//        }
//    }

    for (int type = 1; type <= 2; ++type) {
        int count2 = 0;
        for (auto [l, r] : ranges[type]) {
            if (r - l + 1 >= 3) {
                cout << "No\n";
                return;
            } else if (r - l + 1 == 2) {
                ++count2;
            }
        }
        if (count2 >= 2) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
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