#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double h, r, da, dw;
    cin >> h >> r >> da >> dw;
    auto A = dw - da;
    auto B = h * da;
    auto delta = 4 * A * A * B * B + 4 * h * A * A * A * B;
    auto y = (-2 * A * B + sqrt(delta)) / (2 * A * A);
    printf("%.10lf\n", y);
    return 0;
}