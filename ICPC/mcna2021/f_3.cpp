#include <bits/stdc++.h>
using namespace std;

// these 2 numbers are from other's success. SO WHAT THE HELL THEY ARE???
const int N = 100010, M = 1000010;

int hed[N], to[M], nxt[M], edcnt;
inline void ADD(int x, int y) {
    nxt[++edcnt] = hed[x];
    hed[x] = edcnt;
    to[edcnt] = y;
}


int n, k;
string a[N];

inline int F(int x) { return x; }
inline int T(int x) { return x + k; }
inline int getQ(int x) {
    if (x <= k) return x;
    return x - k;
}

char ans[N];
int vis[N];


void dfs_erase(int x, int dfn) {
    int q = getQ(x);
    ans[q] = '\0';
    vis[x] = 0;

    for (int i = hed[x]; i; i = nxt[i]) {
        int y = to[i];
        if (vis[y] != dfn) continue;
        dfs_erase(y, dfn);
    }
}


int dfs(int x, int fa, int dfn) {
    int q = getQ(x);
    if (ans[q]) {
        if (x == T(q)) return ans[q] == 'T';
        else return ans[q] == 'F';
    }

    vis[x] = dfn;
    if (x == T(q)) ans[q] = 'T';
    else ans[q] = 'F';

    int flag = 1;

    for (int i = hed[x]; i; i = nxt[i]) {
        int y = to[i];

        if (vis[y]) continue;
        flag &= dfs(y, x, dfn);
        if (!flag) break;
    }

    if (!flag) {
        dfs_erase(x, dfn);
        return 0;
    }

    return 1;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = " " + a[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (a[i][j] == 'X') {
                continue;
            }

            for (int p = 1; p <= k; ++p) {
                if (p == j) continue;
                if (a[i][p] == 'X') continue;

                int posj = (a[i][j] == 'T' ? T(j) : F(j));
                int posp = (a[i][p] == 'F' ? T(p) : F(p));

                ADD(posj, posp);
            }
        }
    }
    int Index = 0;

    for (int i = 1; i <= k; ++i) {
        if (!ans[i]) {
            if (dfs(F(i), 0, ++Index)) {
                continue;
            } else if (dfs(T(i), 0, ++Index)) {
                continue;
            } else {
                cout << "-1\n";
                return 0;
            }
        }
    }

    for (int i = 1; i <= k; ++i) {
        cout << ans[i];
    }

    return 0;
}
