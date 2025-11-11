#include <bits/stdc++.h>
using namespace std;

// struct score {
//     int f1, f2;
// } s[15];
pair<int, int> s[15];
int tot, c, knots = 10;
int mi = INT_MAX;
int mx = INT_MIN;

// int strike = 0, spare = 0;
// inline int work(int sc) {
//     int res = sc;
//     if (strike) {
//         res += sc;
//     }
//     if (spare) {
//         res += sc;
//     }
//
//     return res;
// }

inline int calc() {
    int score = 0;
    int strike2 = 0, strike1 = 0, spare = 0;
    for (int i = 1; i <= 9; ++i) {
        if (s[i].first == knots && s[i].second == knots) return INT_MIN;
        // cout << "f1: " << s[i].first << ", f2: " << s[i].second << '\n';
        // cout << "spare: " << spare << ", strike: " << strike2 << '\n';
        score += s[i].first;
        if (strike2) {
            score += s[i].first * strike2;
        }
        if (strike1) {
            score += s[i].first * strike1;
        }
        if (spare) {
            score += s[i].first * spare;
        }
        strike1 = strike2;
        spare = 0;
        strike2 = 0;

        if (s[i].first != knots) {
            score += s[i].second;
            if (strike2) {
                score += s[i].second * strike2;
            }
            if (strike1) {
                score += s[i].second * strike1;
            }
            if (spare) {
                score += s[i].second * spare;
            }
            strike1 = strike2;
            spare = 0;
            strike2 = 0;
        }

        if (s[i].first == knots) {
            ++strike2;
        } else if (s[i].first + s[i].second == knots) {
            ++spare;
        }
    }

    {
        int i = 10;
        score += s[i].first;
        if (strike2) {
            score += s[i].first * strike2;
        }
        if (strike1) {
            score += s[i].first * strike1;
        }
        if (spare) {
            score += s[i].first * spare;
        }
        strike1 = strike2;
        spare = 0;
        strike2 = 0;

        if (s[i].first == knots) {
            ++strike2;
        }

        if (s[i].first != knots) {
            score += s[i].second;
            if (strike2) {
                score += s[i].second * strike2;
            }
            if (strike1) {
                score += s[i].second * strike1;
            }
            if (spare) {
                score += s[i].second * spare;
            }
            strike1 = strike2;
            spare = 0;
            strike2 = 0;
        }

        if (s[i].second == knots) {
            ++strike2;
        }
    }

    if (s[10].first == knots && s[10].second == knots) {
        score += c;
        if (strike2) score += c;
        if (strike1) score += c;
        if (spare) score += c;
    }

    return score;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> tot >> c;
    for (int i = 1; i <= 10; ++i) {
        cin >> s[i].first >> s[i].second;
    }

    // cout << calc() <<'\n';

    vector<int> ans;
    do {
        int p = calc();
        if (p == tot) {
            cout << tot << " Yes\n";
            return 0;
        }
        ans.emplace_back(p);
    } while (next_permutation(s + 1, s + 11));

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] < tot) {
            mx = max(mx, ans[i]);
        }
        if (ans[i] > tot) {
            mi = min(mi, ans[i]);
        }
    }

    // cout << tot << ' ' << mx << ' ' << mi << '\n';
    cout << tot;
    if (mx != INT_MIN) {
        cout << ' ' << mx;
    }
    if (mi != INT_MAX) {
        cout << ' ' << mi;
    }
    return 0;
}
