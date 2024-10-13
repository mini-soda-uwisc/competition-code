#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int N = 2e6 + 10;

int n, cnt;
vector<int> p, st(N);

void init() {
    cnt = 0;
    for (int i = 2; i < N; ++i) {
        if (!st[i]) {
            p.pb(i);
        }

        for (int e: p) {
            if (i * e > N) break;
            st[i * e] = true;
            if (i % e == 0) {
                break;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int l, r;
    cin >> l >> r;
    string t;
    cin >> t;

    int ans = 0;
    for (int i = l; i <= r; ++i) {
//        cout << p[i - 1] << '\n';
        if (to_string(p[i - 1]).find(t) != string::npos) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}