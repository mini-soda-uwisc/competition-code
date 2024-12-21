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

const int N = (int) 1e5 + 1, M = N * 2;

bool cmp(const string x, const string y) {
    int index_x = 0, index_y = 0;
    while (!(x[index_x] >= 'A' && x[index_x] <= 'Z') && index_x < x.size()) {
        index_x++;
    }
    string sub_x = x.substr(index_x);
    while (!(y[index_y] >= 'A' && y[index_y] <= 'Z') && index_y < y.size()) {
        index_y++;
    }
    string sub_y = y.substr(index_y);
    return sub_x < sub_y;
}

void solve() {
    int n = 0;
    vector<string> a;
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        a.emplace_back(s);
    }
//    for (auto &s: a) {
//        cout << s << "\n";
//    }
    sort(a.begin(), a.end(), cmp);
    for (auto &s: a) {
        cout << s << "\n";
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}