#include <bits/stdc++.h>
using namespace std;

int n;
long long m;

inline long long get_min(long long a[]) {
    double p = a[1];
    int k = 1;
    long long c = 0;

    while (ceil(p / (1 << (k - 1)) > 1)) {
        c += ceil(p / (1 << (k - 1)));
        ++k;
    }

    return c;
}
const int N = 1e3 + 10;
long long a[N];

void dfs(int step, long long cur, long long target) {
    long long mi = cur + (long long)ceil((double)a[1] / (1 << step));
    if (mi > target) return;

    for (int i = 1; i <= n; ++i) {
        long long t = cur + ceil((double)a[i] / (1 << step));
        if (t == target) {
            cout << "YES\n";
            exit(0);
        }
        if (t < target) dfs(step + 1, t, target);
    }
}

inline void solve() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    if (get_min(a) <= m) {
        cout << "YES\n";
        return;
    }



    dfs(0, 0, m);
    cout << "NO\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}