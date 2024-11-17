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

    int n = s.size();
    if(s[0] == '-' || s.find('-') == string::npos || s.substr(n - 3, 3) != ">>>"){
        cout << "No\n";
        return;
    }

    cout << "Yes" << " ";
    vector<tuple<int, int>> a;
    s = " " + s;
    int last_minus = -1;
    for (int i = n; i >= 1; --i) {
        if (s[i] == '-') {
            last_minus = i;
            break;
        }
    }

    int last_jianjian = -1;
    for (int i = 1; i < last_minus; ++i) {
        if (s[i] == '>') {
            a.emplace_back(i, n);
            last_jianjian = i;
        }
    }

    for (int i = n - 3; i > last_minus; --i) {
        if (s[i] == '>') {
            a.emplace_back(last_jianjian, i + 2);
        }
    }

    assert(a.size() <= n);

    cout << a.size() << "\n";
    for (auto [x, y] : a) {
        cout << x << " " << (y - x + 1) << "\n";
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