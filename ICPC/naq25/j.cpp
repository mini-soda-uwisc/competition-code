#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    for (int i = 1; i <= 100; ++i) {
        cin >> a;
    }

    if (a % 10 == 0) cout <<"10\n";
    else cout << a % 10 << '\n';
    return 0;
}