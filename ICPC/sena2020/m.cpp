#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    double sum = 0;
    for (int i = 1; i <= k; ++i) {
        double x;
        cin >> x;
        sum += x;
    }

    printf("%lf %lf\n", (sum - 3.0 * (n - k)) / n, (sum + 3.0 * (n - k)) / n);
    return 0;
}