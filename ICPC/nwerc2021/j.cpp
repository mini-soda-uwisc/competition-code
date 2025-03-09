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

bool yVisit[N]; // 从-180到180映射为0-720，0.5为一格，不会碰到下标720

void goVisit(int start0, int finish0) {
    int start = start0, finish = finish0;
    // 设置偏移量
    start += 180, finish += 180;
    start *= 2, finish *= 2;
    if (start >= finish) {
        for (int i = finish; i <= start; i++) {
            yVisit[i] = true;
        }
    }
    else {
        for (int i = start; i <= finish; i++) {
            yVisit[i] = true;
        }
    }
    // if (start0 * finish0 > 0) {
    //     // 同号则一定在一个半球内，直接最近
    //     if (finish > start) {
    //         // 顺时针
    //         for (int i = start; i <= finish; i++) {
    //             yVisit[i] = true;
    //         }
    //     } else {
    //         // 逆时针
    //         for (int i = finish; i <= start; i++) {
    //             yVisit[i] = true;
    //         }
    //     }
    // } else {
    //     // 不同号则考虑跨越0和180
    //     if (finish > start) {
    //         const int crossDistance = 720 - finish + start;
    //         const int directDistance = abs(finish - start);
    //         if (crossDistance < directDistance) {
    //             for (int i = finish; i != start; i++, i %= 720) {
    //                 yVisit[i] = true;
    //             }
    //         } else {
    //             for (int i = start; i <= finish; i++) {
    //                 yVisit[i] = true;
    //             }
    //         }
    //     }
    // }
}

void solve() {
    int n;
    cin >> n;
    int yLast = 0, xLast = 0;
    cin >> xLast >> yLast;
    int y0 = yLast, x0 = xLast;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        goVisit(y, yLast);
    }
    goVisit(yLast, y0);

    for (int i = 0; i < 720; i++) {
        if (!yVisit[i]) {
            printf("no %.2lf\n", i / 2.0);
            return;
        }
    }
    printf("yes\n");
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(yVisit, 0, sizeof(yVisit));

    int t = 1;
    //  cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
