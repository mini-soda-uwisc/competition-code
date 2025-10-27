#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int p[1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> a >> b;
    if (a + b > n + 1 || (a == 1 &&b == 1)) {
        cout << "no\n";
        return 0;
    }

    // vector<int> l, r;
    // queue<int> rem;
    // l.emplace_back(n);
    // r.emplace_back(n);
    // for (int i = n - 1; i >= 1; --i) {
    //     if (l.size() < a) l.emplace_back(i);
    //     else if (r.size() < b) r.emplace_back(i);
    //     else rem.push(i);
    // }
    //
    // if (l.size() != a || r.size() != b) {
    //     cout << "no\n";
    //     return 0;
    // }
    //
    // sort(l.begin(), l.end());
    // sort(r.begin(), r.end());
    // for (int i = 1; i <= a; ++i) {
    //     p[i] = l[i - 1];
    // }
    // for (int i = 1; i < b; ++i) {
    //     p[n - i + 1] = r[i - 1];
    // }
    // for (int i = 1; i <= n; ++i) {
    //     if (p[i] == 0) {
    //         p[i] = rem.front();
    //         rem.pop();
    //     }
    // }
    //
    // for (int i = 1; i <= n; ++i) {
    //     cout << p[i] << ' ';
    // }

    int p[n + 1];
    if (a > b) {
        p[n - b + 1] = n;
        int id = 1;
        for (int i = n; i > n - b + 1; i--) {
            p[i] = id++;
        }
        for (int i = 1; i < n - b + 1; i++) {
            p[i] = id++;
            if (--a == 1) {
                id--;
                p[i] = n - 1;

                for (int j = i + 1; j < n - b + 1; j++) {
                    p[j] = id++;
                }
                break;
            }
        }
    }
    else {
        p[a] = n;
        int id = 1;
        for (int i = 1; i < a; i++) {
            p[i] = id++;
        }
        for (int i = n; i > a; i--) {
            p[i] = id++;
            if (--b == 1) {
                id--;
                p[i] = n - 1;
                for (int j = i - 1; j > a; j--) {
                    p[j] = id++;
                }
                break;
            }
        }
    }

    cout << "yes\n";
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " \n"[i == n];
    }
    return 0;
}