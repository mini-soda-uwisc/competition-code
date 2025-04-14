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
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a, b, c;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.pb({x, y});
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        b.pb({x, y});
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        c.pb({x, y});
    }

    auto calc = [&](vector<vector<int>> a, vector<vector<int>> b) -> double {
        int dn = a.size(), dm = b.size();
        vector<int> v1(dn), v2(dm);
        double qwq = 0;

        while (dm--) {
            double min = 1e15, dx = 0, dy = 0;
            for (int i = 0; i < a.size(); i++) {
                if (v1[i]) {
                    continue;
                }

                for (int j = 0; j < b.size(); j++) {
                    if (v2[j]) {
                        continue;
                    }

                    double x = a[i][0] - b[j][0];
                    double y = a[i][1] - b[j][1];
                    if (min > x * x + y * y) {
                        min = x * x + y * y;
                        dx = i, dy = j;
                    }
                }
            }
            qwq += sqrt(min);
            v1[dx] = v2[dy] = 1;
        }
        return qwq;
    };

    cout << fixed << setprecision(20) << calc(b, a) + calc(c, a) << endl;
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
