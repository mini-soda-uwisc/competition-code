#include <bits/stdc++.h>
using namespace std;

//#define double long double

const double EPS = 1e-6;

int n;

int calcx(int y, double r) {
    return floor(sqrt(r * r - y * y));
}
int calcy(int x, double r) {
    return floor(sqrt(r * r - x * x));
}

int check(double r) {
    int sum = 0;
    for (int y = 1; y <= floor(r); ++y) {
        int x = calcx(y, r);
        int yp = calcy(x, r);
        sum += (yp - y + 1) * x;
        y = yp;
    }
    if (sum * 4 > n) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    double l = 1, r = 2e5;

    while (r - l > EPS) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.10lf\n", l);
    return 0;
}