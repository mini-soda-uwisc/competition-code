//
// Created by EHPC6 on 11/9/2024.
//
#include <bits/stdc++.h>
using namespace std;

double a, b;

int calc1(double a, double b) {
    int res = 0;
    for (double yi = 2; yi <= a; yi += 4.0) {
        double xi = - b * yi / a + b;
        int p = floor(xi);
        res += p / 4;
    }
    for (double yi = 4; yi <= a; yi += 4.0) {
        double xi = - b * yi / a + b;
        int p = floor(xi - 2);
        res += p / 4;
    }
    return res;
}
int calc2(double a, double b) {
    int res = 0;
    for (double yi = 2; yi <= a; yi += 4.0) {
        double xi = - b * yi / a + b;
        int p = floor(xi - 2);
        res += p / 4;
    }
    for (double yi = 4; yi <= a; yi += 4.0) {
        double xi = - b * yi / a + b;
        int p = floor(xi);
        res += p / 4;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    a *= 2;
    b *= 2;

    int ans = -1;
    ans = max(ans, calc1(a, b));
    ans = max(ans, calc2(a, b));

    ans = max(ans, calc1(b, a));
    ans = max(ans, calc2(b, a));
    cout << ans << '\n';
    return 0;
}