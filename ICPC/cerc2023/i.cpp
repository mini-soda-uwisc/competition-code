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

void solve() {
    int n;
    cin >> n;
    int p[16][n + 1];
    memset(p, 0, sizeof p);

    queue<int> q;
    vector<int> deg(n + 1);

    string t = "";
    for (int i = 1; i <= n; i++) {
        t += '1';
    }
    cout << "QUERY " << t << endl;

    for (int i = 1; i <= n; i++) {
        cin >> deg[i];
    }

    for (int i = 2; i >= 0; i--) {
        string s = "";
        for (int j = 1; j <= n; j++) {
            s += to_string(j >> i & 1);
        }
        cout << "QUERY " << s << endl;

        for (int j = 1; j <= n; j++) {
            int occ;
            cin >> occ;
            p[i][j] += occ;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            q.push(i);
            cout << i << endl;
        }
    }

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        int v = 0;
        for (int i = 0; i < 16; i++) {
            if (p[i][u]) {
                v |= 1 << i;
                p[i][u]--;
            }
        }

        cout << u << " " << v << endl;
        if (--deg[v] == 1) {
            q.push(v);
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
