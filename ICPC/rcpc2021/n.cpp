#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

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

void solve() {
    int n, m;
    cin >> n >> m;

    unordered_map<char, int> green;
    unordered_map<char, int> yellow;

    for (int i = 0; i < n; ++i) {
        string word, correctness;
        cin >> word >> correctness;
        for (int j = 0; j < word.length(); ++j) {
            if (correctness[j] == 'G') {
                green.emplace(word[j], j);
            } else if (correctness[j] == 'Y') {
                yellow.emplace(word[j], j);
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        string test;
        unordered_map<char, int> test_map;
        cin >> test;

        for (int j = 0; j < test.length(); ++j) {
            test_map.emplace(test[j], j);
        }

        for (auto [g, gi] : green) {
            if (test_map[g] != gi) {
                goto END;
            }
        }

        for (auto [y,yi] : yellow) {
            if (test_map.find(y) == test_map.end() || test_map[y] == yi) {
                goto END;
            }
        }

        cout << test << "\n";
    END:
    }
}

int main() {
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
