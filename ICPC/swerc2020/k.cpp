#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using uLL = unsigned long long;

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

struct StringHash {
    string s;
    int n, p1, p2, b1, b2;
    vector <uLL> pre1, pw1, pre2, pw2;

    void init(string _s, int _p1, int _p2, int _b1, int _b2) {
        s = _s, p1 = _p1, p2 = _p2;
        b1 = _b1, b2 = _b2;
        n = s.size();
        pre1.resize(n + 1, 0);
        pre2.resize(n + 1, 0);
        pw1.resize(n + 1, 1);
        pw2.resize(n + 1, 1);

        for (int i = 1; i <= n; ++i) {
            pre1[i] = ((pre1[i - 1] * p1) + s[i - 1]) % b1;
        }
        for (int i = 1; i <= n; ++i) {
            pw1[i] = pw1[i - 1] * p1 % b1;
        }
        for (int i = 1; i <= n; ++i) {
            pre2[i] = ((pre2[i - 1] * p2) + s[i - 1]) % b2;
        }
        for (int i = 1; i <= n; ++i) {
            pw2[i] = pw2[i - 1] * p2 % b2;
        }
    }

    uLL query1(int l, int r) {
        return (pre1[r] - (pre1[l - 1] * pw1[r - l + 1]) % b1 + b1) % b1;;
    }

    uLL query2(int l, int r) {
        return (pre2[r] - (pre2[l - 1] * pw2[r - l + 1]) % b2 + b2) % b2;
    }
}ha;

/*
    ha1.init(s, , 1e9 + 9, 131, 1211221);
    ha2.init(s, 1e9 + 7, 1e9 + 9, 131, 1211221);
    // s = '#' + s;
*/

struct Info {
    int t, id;
};

void solve(){
    string s, t = "";
    cin >> s;
    int n = s.size();

    ha.init(s, 233, 998244353, 1e9 + 7, 1e9 + 9);
    s = '#' + s;

    map<uLL, Info> mp;
    auto check = [&](int mid) -> int {
        mp.clear();
        for (int i = 1; i <= n - mid + 1; i++) {
            uLL hash = ha.query1(i, i + mid - 1);
            // cout << hash << " " << s.substr(i, mid) << endl;
            mp[hash].t++;
            mp[hash].id = i;
        }

        int first = (int)1e9;
        for (auto [k, v] : mp) {
            // cout << k << " " << v.t << " " << mid << endl;
            if (v.t == 1) {
                first = chmin(first, v.id);
            }
        }

        if (first != 1e9) {
            t = s.substr(first, mid);
        }
        return first != 1e9;
    };

    int l = 1, r = n + 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << t << endl;
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