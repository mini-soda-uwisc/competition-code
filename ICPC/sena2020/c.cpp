#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

// #define int long long

int n;
int a[N];

priority_queue<int, vector<int>, greater<int>> q;
map<int, int> b;

int z[N << 2];

inline int lowbit(int x) {
    return x & -x;
}
inline void update(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) {
        z[i] += v;
    }
}
inline int query(int x) {
    int s = 0;
    for (int i = x; i; i -= lowbit(i)) {
        s += z[i];
    }
    return s;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[a[i]] = i;
        q.emplace(a[i]);
        update(i, i);
        update(i + 1, -i);
    }

    int ans = 0, l = 1, r = n;
    while (!q.empty()) {
        int v = q.top();
        q.pop();

        int pos = query(b[v]);

        int L = pos - l;
        int R = r - pos;

        if (L <= R) {
            ans += L;
            // modify(root, 1, pos - 1, 1);
            update(1, 1);
            update(pos, -1);
            ++l;
        } else {
            ans += R;
            // modify(root, pos + 1, n, -1);
            update(pos + 1, -1);
            --r;
        }
    }

    cout << ans << '\n';
    return 0;
}