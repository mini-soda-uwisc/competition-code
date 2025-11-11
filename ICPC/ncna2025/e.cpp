#include <bits/stdc++.h>
using namespace std;

int input() {
    double x;
    cin >> x;
    return x * 10;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n = input();
    int a = input();
    int b = input();

    int ans_rem = INT_MAX, ans_cur_a = -1, ans_cur_b = 0;
    int cur = n / a;
    while (cur >= 0) {
        int p = n - a * cur;
        int cur_b = p / b;
        int rem = n - (a * cur + b * cur_b);
        // printf("cur a: %d, b: %d, rem: %d\n", cur, cur_b, rem);
        if (rem < ans_rem || (rem == ans_rem && ans_cur_a < cur)) {
            // printf("ans rem: %d, replaced", ans_rem);
            ans_cur_a = cur;
            ans_cur_b = cur_b;
            ans_rem = rem;
        }
        --cur;
    }

    cout << ans_cur_a << ' ' << ans_cur_b;
    return 0;
}