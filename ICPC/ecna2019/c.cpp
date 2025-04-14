#include <bits/stdc++.h>
using namespace std;
constexpr int M = 100, N = 100, INF = 1e9;

int n, m;
double a[M][N], q[M], p[N], v;

void pivot(int l, int e) {  // 转轴操作函数
    q[l] /= a[l][e];
    for (int j = 1; j <= n; j++)
        if (j != e) a[l][j] /= a[l][e];
    a[l][e] = 1 / a[l][e];

    for (int i = 1; i <= m; i++)
        if (i != l && fabs(a[i][e]) > 0) {
            q[i] -= a[i][e] * q[l];
            for (int j = 1; j <= n; j++)
                if (j != e) a[i][j] -= a[i][e] * a[l][j];
            a[i][e] = -a[i][e] * a[l][e];
        }

    v += p[e] * q[l];
    for (int j = 1; j <= n; j++)
        if (j != e) p[j] -= p[e] * a[l][j];
    p[e] = -p[e] * a[l][e];

    // swap(B[l],N[e])
}

double simplex() {
    while (true) {
        int e = 0, l = 0;
        for (e = 1; e <= n; e++)
            if (p[e] > (double)0) break;
        if (e == n + 1) return v;  // 此时v即为最优解
        double mn = INF;
        for (int i = 1; i <= m; i++) {
            if (a[i][e] > (double)0 && mn > q[i] / a[i][e]) {
                mn = q[i] / a[i][e];  // 找对这个e限制最紧的l
                l = i;
            }
        }
        if (mn == INF) return INF;  // unbounded
        pivot(l, e);                // 转动l,e
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
        q[i] *= 100;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
        cin >> p[i];
    }
    printf("%.2lf\n", simplex());
}