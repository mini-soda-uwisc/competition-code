#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

double r, s, h;
double d;

int n1, n2, n3;

int main() {
    cin >> r >> s >> h;
    d = 2 * PI * r / s / h;

    double X = abs(d - floor(d + 0.5));

    double best = 1e18;
    for (double x = 1; x <= 1000; x += 1.0) {
        for (double y = x * 2; y <= 1000; y += x) {
            for (double z = y * 2; z <= 1000; z += y) {
                double diff = abs(X - (1 / x - 1 / y + 1 / z));
                if (diff < best) {
                    best = diff;
                    n1 = x;
                    n2 = y;
                    n3 = z;
                }
            }
        }
    }

    cout << n1 << ' ' << n2 << ' ' << n3 << '\n';
    return 0;
}