#include <bits/stdc++.h>
using namespace std;

#define int long long

int a, b;
int n, m;

int check_amount(int x) {
    return x * (x - 1) / 2;
}

int calc(int layer) {
    int p = (layer - 2) * (layer - 1) / 2;
    p += (n - layer + 1) * (layer - 1);
    return p;
}

int s[100000];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    scanf("%lld/%lld", &a, &b);
    if (a < b) {
        if (a != b - 1) {
            cout << "impossible\n";
            return 0;
        }

        cout << b << ' ' << b - 1 << '\n';
        for (int i = 2; i <= b; ++i) {
            cout << "1 " << i << '\n';
        }
        return 0;
    }

    n = b;
    m = a;
    int a_time_mark_hahahahahaha = 1;
    while (check_amount(n) < m) {
        n += b;
        ++a_time_mark_hahahahahaha;
        m += a;
    }

//    a *= a_time_mark_hahahahahaha;

    s[1] = 1;
    s[2] = n - 1;
    int layer = 2;
    for (; ; ++layer) {
        s[layer - 1] = 1;
        s[layer] = n - layer + 1;
        int t = calc(layer);
//        cout << "layer: " << layer << ", t: " << t << endl;
        if (t == m) break;
        if (t < m) continue;
        s[layer - 1] += t - m;
        s[layer] -= t - m;
        break;
    }

//    cout << "s:\n";
//    for (int i = 1; i <= layer; ++i) {
//        cout << s[i] << ' ';
//    }
//    cout << endl << endl;

    cout << n << ' ' << n - 1 << '\n';

    int parent = 1;
    for (int i = 2; i <= layer; ++i) {
        for (int p = 1; p <= s[i]; ++p) {
            int node = parent + p;
            cout << parent << ' ' << node << '\n';
        }
        parent += s[i];
    }
    return 0;
}
