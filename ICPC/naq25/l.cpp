#include <bits/stdc++.h>
using namespace std;

int n;
int a[20];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int x = a[1] / 3;
    int y = a[2] - 2 * x;
    int z = a[n] / 3;

    cout << x << ' ' << y << ' ' << z << '\n';
    return 0;
}