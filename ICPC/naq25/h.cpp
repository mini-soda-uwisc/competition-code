#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

#define ll long double

int n;
ll a[N], b[N];
ll sum = 0;

void moveright() {
    int id = 1;
    for (int i = 2; i <= n; ++i) {
        if (b[i] > b[id]) id = i;
    }

    ll dis = 0;
    ll wt = 0;
    for (int i = id; i <= n; ++i) {
        sum -= b[i] * a[i];
        wt += b[i];
        // printf("i: %d, wt: %Lf, sum %Lf\n", i, wt, sum);
        ll y = -sum / wt;
        if (a[i] <= y && y <= a[i + 1]) {
            cout << setprecision(20) << dis + abs(y - a[i]) * (i - id + 1)<< '\n';
            return;
        }

        dis += (a[i + 1] - a[i]) * (i - id + 1);
    }
}
void moveleft() {
    int id = 1;
    for (int i = 2; i <= n; ++i) {
        if (b[i] >= b[id]) id = i;
    }

    ll dis = 0;
    ll wt = 0;
    for (int i = id; i >= 1; --i) {
        sum -= b[i] * a[i];
        wt += b[i];
        // printf("i: %d, wt: %Lf, sum %Lf\n", i, wt, sum);
        ll y = -sum / wt;
        if (a[i - 1] <= y && y <= a[i]) {
            // cout << "found y: " << y << '\n';
            cout << setprecision(20) << dis + abs(y - a[i]) * (id - i + 1) << '\n';
            return;
        }

        dis += (a[i] - a[i - 1]) * (id - i + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        sum += a[i] * b[i];
    }
    a[n + 1] = 2e18;
    a[0] = -2e18;

    // if (abs(sum) <= 1e-8) {
    //     cout << "0\n";
    //     return 0;
    // }

    if (sum < 0) {
        moveright();
        return 0;
    }

    moveleft();
    return 0;
}