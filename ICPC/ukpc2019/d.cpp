#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template <typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<double>> a;
    for (int i = 0; i < n; i++){
        double x, y, z;
        cin >> x >> y >> z;
        a.push_back({x, y, z});
    }

    auto check = [&](ld r) -> bool{
        int cnt = 0;
        for (int i = 0; i < n; i++){
            ld x = a[i][0], y = a[i][1], z = a[i][2];
            if (sqrt(x * x + y * y + z * z) <= r){
                cnt++;
            }
        }
        return cnt >= k;
    };

    ld l = 0, r = 1e12, base = 1.0, eps = 1e-8;
    while(r - l > chmax(base, l) * eps){
        ld x = (l + r) / 2;
        if(check(x)) r = x;
        else l = x;
    }
    cout << setprecision(20) << r << "\n";
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
