#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

// #define ONLINE_JUDGE
// #define MY_ASSERT

#ifndef ONLINE_JUDGE
#define cerr cout
#define FILEIO() \
do { \
freopen(__FILE__".in", "r", stdin); \
freopen(__FILE__".out", "w", stdout); \
} while (0)
#ifndef MY_ASSERT
#define MY_ASSERT
#endif
#else
#define cerr if (0) cerr
#define FILEIO() 0
#endif

#ifdef MY_ASSERT
#define M_ASSERT(cond, msg) \
do { \
if (!(cond)) { \
cerr << "Assertion failed: " << #cond << '\n'; \
cerr << "Message: " << msg << '\n'; \
cerr << "File: " << __FILE__ << ", Line: " << __LINE__ << std::endl; \
exit(1); \
} \
} while (0)
#else
#define M_ASSERT(cond, msg) 0
#endif

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template <typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

inline int partten(int left, int cur, int right) {
    // cout << "Get:" << left << " " << cur << " " << right << '\n';
    bool b = (left && cur && !right) // 110 = 1
        || (left && !cur && right) // 101 = 1
        // || !(left && !cur && !right) // 100 = 0
        || (!left && cur && !right) // 011 = 1
        || (!left & cur && !right) // 010 = 1
        || (!left && !cur && right); // 001 = 1
    // cout << b << '\n';
    return b == false ? 0 : 1;
}

void solve() {
    vector<int> a(100, 0);
    const int START = 83;
    const int LEN = 16;
    string s;
    cin >> s;
    for (int i = START; i < START + LEN; ++i) {
        a[i] = s[i - START] - '0';
    }

    for (int i = 0; i < 100; i++) {
        vector<int> b = a;
        for (int j = 1; j < a.size() - 1; j++) {
            b[j] = partten(a[j - 1], a[j], a[j + 1]);
        }
        for (auto bi : b) {
            cout << bi;
        }
        cout << '\n';
        a = b;
    }
}

int main() {
    // FILEIO();

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
