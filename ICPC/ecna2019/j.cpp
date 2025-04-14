#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using i128 = __int128;

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

int n, m;

ostream &operator<<(std::ostream &os, i128 n) {
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

int check(vector<pair<ll, ll>>& a, i128 mid) {
    priority_queue<int, vector<int>, less<>> q;
    ll owo = 0, qwq = 0;

    for (auto [x, y] : a) {
        owo += x;
        q.push(x);
        while (mid * y < owo && !q.empty()) {
            owo -= q.top();
            q.pop();
            qwq++;
        }
    }
    return qwq <= m;
}

void solve(){
    cin >> n >> m;

    vector<pair<ll, ll>> a;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.pb({x, y});
    }

    sort(a.begin(), a.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });

    ll l = 1, r = 1e18;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(a, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    if (!check(a, l)) {
        l++;
    }
    cout << l << '\n';
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
