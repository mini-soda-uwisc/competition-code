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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a;
    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;

        if (op == '!') {
            int p, l, A;
            cin >> p >> l >> A;
            a.pb({p, l, A});
        }
        else {
            ll qwq = 0;
            int p;
            cin >> p;

            for (int j = 0; j < a.size(); j++) {
                if (a[j][0] <= p && p <= a[j][0] + a[j][1] - 1) {
                    int owo = (p - a[j][0]) % 4;
                    if (owo == 0) {
                        qwq += a[j][2];
                    }
                    else if (owo == 2) {
                        qwq -= a[j][2];
                    }
                }
            }
            cout << qwq << endl;
        }
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
