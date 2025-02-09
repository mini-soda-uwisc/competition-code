#include <bits/stdc++.h>
using namespace std;

int l, w, n;
int a, b;
char ans[110][110];

int main() {
    cin >> l >> w >> n;
    if ((l * w) % n != 0) {
        cout << "impossible\n";
        return 0;
    }

    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (l % i == 0 && w % j == 0 && n * i * j == l * w) {
                a = i;
                b = j;
                break;
            }
        }
    }

    char ch = 'A';
    for (int a0 = 0; a0 < l; a0 += a) {
        for (int b0 = 0; b0 < w; b0 += b) {
            for (int i = 0; i < a; ++i) {
                for (int j = 0; j < b; ++j) {
                    ans[a0 + i][b0 + j] = ch;
                }
            }
            ch++;
        }
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
    return 0;
}
