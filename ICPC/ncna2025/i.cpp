#include <bits/stdc++.h>
using namespace std;

struct Sieve {
    int n, cnt;
    vector<int> p, p_min;

    Sieve(int _n) : n(_n) {
        p_min.resize(n + 1, 0);
    }

    void init() {
        for (int i = 2; i <= n; ++i) {
            if (!p_min[i]) {
                p.push_back(i);
            }

            for (int pr : p) {
                if (i * pr > n) {
                    break;
                }
                p_min[i * pr] = pr;
            }
        }
    }
};

int mod = (int)1e9 + 7;

long long qpow(long long a, long long b) {
    long long res = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int e, l, r;
    cin >> e >> l >> r;
    Sieve s(max(l, r) + 1);
    s.init();

    long long ans = 1;
    for (auto p : s.p) {
        if (p >= l && p <= r) {
            ans = ans * qpow(p, e) % mod;
        }
    }

    cout << ans << "\n";
    return 0;
}