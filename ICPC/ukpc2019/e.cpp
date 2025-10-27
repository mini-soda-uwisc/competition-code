#include <bits/stdc++.h>
using namespace std;

const int N = 200;
const int M = N * N;

int n, m;
int hed[N], to[M], nxt[M], wt[M], edcnt;

inline void ADD(int x, int y, int w) {
    nxt[++edcnt] = hed[x];
    hed[x] = edcnt;
    to[edcnt] = y;
    wt[edcnt] = w;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        ADD(u, v, w);
    }
    return 0;
}