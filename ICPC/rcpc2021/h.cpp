#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long

int a, b;
map<int, int> mp;

int is_prime(int x) {
    int s = sqrt(x);
    for (int i = 2; i <= s; ++i) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

void work(int x) {
    for (int i = 2; i <= sqrt(x) && i <= x; i++) {
        while (x % i == 0) {
            mp[i]++;
            x /= i;

            if (mp[i] > 1) {
                cout << "no credit" << '\n';
                exit(0);
            }
        }
    }
    mp[x]++;
    if (mp[x] > 1) {
        cout << "no credit" << '\n';
        exit(0);
    }
}

signed main() {
    cin >> a >> b;
    if (a == b) {
        cout << "no credit\n";
        return 0;
    }

    if (is_prime(a) && is_prime(b)) {
        cout << "full credit\n";
        return 0;
    }

    work(a);
    work(b);

    cout << "partial credit\n";
    return 0;
}