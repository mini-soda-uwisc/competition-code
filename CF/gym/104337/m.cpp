#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
//    printf("%d %d\n", x, y);
    if (y % 500 != 0) {
        printf("-1\n");
        return 0;
    } // 特判，因为1000B+2500C=y，所以y必须是500的倍数
    for (int c = x; c >= 0; --c) {
        if ((y - c * 2500) % 1000 == 0) {
            int b = (y - c * 2500) / 1000;
            int a = x - b - c;
            if (b >= 0 && a >= 0) {
                printf("%d %d %d\n", a, b, c);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}