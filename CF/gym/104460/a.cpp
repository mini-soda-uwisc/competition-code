#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

// dp[pos][tight][max_digit][diff][leading_zero]
// max_digit: 0-9 (10)
// diff: 0-50 (51)
// leading_zero: 0-1 (2)
long long dp[51][2][10][51][2];

long long digit_dp(int pos, int tight, int max_digit, int diff, bool leading_zero, const vector<int>& digits) {
    if (pos == digits.size()) {
        // 如果整个数都是前导零，则不计入
        if (leading_zero) return 0;
        return max_digit;
    }

    if (dp[pos][tight][max_digit][diff][leading_zero] != -1) {
        return dp[pos][tight][max_digit][diff][leading_zero];
    }

    int limit = tight ? digits[pos] : 9;
    long long res = 0;

    for (int d = 0; d <= limit; ++d) {
        bool next_tight = tight && (d == limit);
        bool next_leading_zero = leading_zero && (d == 0);
        int next_max_digit = max_digit;
        int next_diff = diff;

        if (next_leading_zero) {
            // 仍在前导零部分，众数未定
            res = (res + digit_dp(pos + 1, next_tight, max_digit, diff, true, digits)) % MOD;
        } else {
            if (diff == 0) {
                // 当前没有众数，新的数字成为众数
                next_max_digit = d;
                next_diff = 1;
            } else {
                if (d == max_digit) {
                    next_diff++;
                } else {
                    next_diff--;
                    if (next_diff == 0) {
                        // 众数可能变化，取较大的数字
                        next_max_digit = max(max_digit, d);
                        next_diff = 1;
                    }
                }
            }
            res = (res + digit_dp(pos + 1, next_tight, next_max_digit, next_diff, false, digits)) % MOD;
        }
    }

    dp[pos][tight][max_digit][diff][leading_zero] = res;
    return res;
}

long long solve(const string& n_str) {
    vector<int> digits;
    for (char ch : n_str) {
        digits.push_back(ch - '0');
    }
    memset(dp, -1, sizeof(dp));
    return digit_dp(0, 1, 0, 0, true, digits) % MOD;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string n_str;
        cin >> n_str;
        cout << solve(n_str) << endl;
    }
    return 0;
}
