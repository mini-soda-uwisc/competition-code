#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

int heap[60] = {0};

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int) 1e5 + 1, M = N * 2;

void solve() {
    for (int i = 0; i < 5; ++i) {
        int x;
        cin >> x;
        heap[x]++;
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = 1;
    cin >> n;
    int t = n * 10;

    while (t--) {
        solve();
    }

    bool flag = false;
    for (int i = 1; i <= 50; ++i) {
        if (heap[i] > 2 * n) {
            flag = true;
            cout << i << " ";
        }
    }

    if (!flag) {
        cout << -1 << endl;
    } else {
        cout << endl;
    }

    return 0;
}