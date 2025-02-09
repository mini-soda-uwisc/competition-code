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

const int N = (int) 1e3 + 1, M = N * 1000;
int st[N], match[N], h[N], e[M], ne[M], idx;

struct Sieve {
    int n, cnt;
    vector<int> p, st;

    Sieve(int _n) : n(_n) {
        st.resize(n + 1, 0);
    }

    void init() {
        cnt = 0;
        for (int i = 2; i <= n; ++i) {
            if (!st[i]) {
                p.pb(i);
            }

            for (int e: p) {
                if (i * e > n) break;
                st[i * e] = true;
                if (i % e == 0) {
                    break;
                }
            }
        }
    }
};

void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

bool hungarian(int x){ //图
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if (!st[j]){
            st[j] = 1;
            if(match[j] == 0 || hungarian(match[j])){
                match[j] = x;
                return 1;
            }
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> A;
    int one = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && !one) {
            A.pb(1);
            one = 1;
        }
        if (a[i] != 1) {
            A.pb(a[i]);
        }
    }

    Sieve s(2 * *max_element(A.begin(), A.end()));
    s.init();

    for (int i = 0; i < A.size(); i++) {
        h[i] = -1;
    }
    idx = 0;

    for (int i = 0; i < A.size(); i++) {
        for (int j = i + 1; j < A.size(); j++) {
            if (!s.st[A[i] + A[j]]) {
                add(i, j), add(j, i);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < A.size(); i++) {
        memset(st, 0, sizeof st);
        if (hungarian(i)) {
            res++;
        }
    }

    cout << A.size() - res / 2 << endl;
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
