#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    int x1 = 0, x2 = (int)1e9 + 1, y1 = 0, y2 = (int)1e9 + 1;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >>y;
        x1 = max(x, x1);
        x2 = min(x, x2);
        y1 = max(y, y1);
        y2 = min(y, y2);
    }

    cout << 4<< "\n";
    cout << x2 << " " << y2 << "\n";
    cout << x1 << " " << y2 << "\n";
    cout << x1 << " " << y1 << "\n";
    cout << x2 << " " << y1 << "\n";
}