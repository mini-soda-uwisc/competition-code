#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back
#define int long long

const int N = (int)1e5 + 1, M = N * 2;

void simulate(int A, int B, int C) {
    while (A != 0 && B != 0
        || A != 0 && C != 0
        || B != 0 && C != 0) {
        int a = A, b = B, c = C;
        // A attack
        if (A != 0) {
            if (B > C) {
                b--;
            } else if (C > B) {
                c--;
            } else if (C == B) {
                b--;
            }
        }

        // B attack
        if (B != 0) {
            if (A > C) {
                a--;
            } else if (C > A) {
                c--;
            } else if (C == A) {
                c--;
            }
        }

        // C attack
        if (C != 0) {
            if (A > B) {
                a--;
            } else if (B > A) {
                b--;
            } else if (A == B) {
                a--;
            }
        }

        A = a;
        B = b;
        C = c;
    }

    if (A == 0 && B == 0 && C == 0) {
        cout << "Rubble!\n";
    } else if (A > 0) {
        cout << "A " << A << '\n';
    } else if (B > 0) {
        cout << "B " << B << '\n';
    } else if (C > 0) {
        cout << "C " << C << '\n';
    }
    exit(0);
}

void fuckyou(int a, int b, int c) {
    if (a == 0) {
        if (b > c) cout << "B " << b - c << '\n';
        else if (b < c) cout << "C " << c - b << '\n';
        else cout << "Rubble!\n";
    } else if (b == 0) {
        if (a > c) cout << "A " << a - c << '\n';
        else if (a < c) cout << "C " << c - a << '\n';
        else cout << "Rubble!\n";
    } else {
        if (a > b) cout << "A " << a - b << '\n';
        else if (a < b) cout << "B " << b - a << '\n';
        else cout << "Rubble!\n";
    }
    exit(0);
}

void work(int a, int b, int c) {
    if (a == b && b == c) {
        cout << "Rubble!\n";
        exit(0);
    }
    if (a == 0 && b == 0) {
        assert(c != 0);
        cout << "C " << c << '\n';
        exit(0);
    }
    if (a == 0 && c == 0) {
        assert(b != 0);
        cout << "B " << b << '\n';
        exit(0);
    }
    if (b == 0 && c == 0) {
        assert(a != 0);
        cout << "A " << a << '\n';
        exit(0);
    }
    if (a == 0 || b == 0 || c == 0) {
        fuckyou(a, b, c);
    }

    vector<pair<int, int>> arr = {make_pair(a, 1), make_pair(b, 2), make_pair(c, 3)};
    sort(arr.begin(), arr.end());

    int &x = arr[0].first, &y = arr[1].first, &z = arr[2].first;

    if (x <= 10 && y <= 10) {
        simulate(a, b, c);
    }

     if (y - x < 4 || z - y < 4) {
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
        int A = arr[0].first, B = arr[1].first, C = arr[2].first;

        if (arr[1].first >= arr[2].first) {
            --B;
        } else {
            --C;
        }

        if (arr[2].first >= arr[0].first) {
            --C;
        } else {
            --A;
        }

        if (arr[0].first >= arr[1].first) {
            --A;
        } else {
            --B;
        }
        arr[0].first = A;
         arr[1].first = B;
         arr[2].first = C;
    } else {
        int round = min(z - y, y - x);
        z -= 2 * round;
        y -= round;
        x -= round;
    }

    sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });
    work(arr[0].first, arr[1].first, arr[2].first);
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    work(a, b, c);
}

signed main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
