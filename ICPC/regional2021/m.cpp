#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

struct pair_hash {
    template<class T1, class T2>
    size_t operator()(const std::pair<T1, T2> &pair) const {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
    }
};

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int) 1e5 + 1, M = N * 2;

int n;
ll p, k;
vector<ll> d;

void solve() {
    cin >> n >> p >> k;
    d.resize(n);
    for (int i = 0; i < n; ++i) cin >> d[i];

    // Precompute prefix sums for the durations
    vector<ll> cum(n + 1, 0); // cum[i] = sum of d[i to n-1]
    for (int i = n - 1; i >= 0; --i) {
        cum[i] = cum[i + 1] + d[i];
    }

    ll total_passes = 0;
    int pos = 0;
    ll day = 0;
    unordered_map<int, pair<ll, ll>> mp; // pos -> (day, total_passes)

    while (day < k) {
        if (mp.count(pos)) {
            ll prev_day = mp[pos].first;
            ll prev_passes = mp[pos].second;
            ll cycle_length = day - prev_day;
            ll cycle_passes = total_passes - prev_passes;
            if (cycle_length == 0) {
                // Cannot proceed further, break to prevent infinite loop
                break;
            }
            ll cycles = (k - day) / cycle_length;
            total_passes += cycles * cycle_passes;
            day += cycles * cycle_length;
            if (day >= k) break;
        }
        mp[pos] = {day, total_passes};

        ll remaining_time = p;
        int start_pos = pos;

        // Try to complete the rest of the current rehearsal pass
        ll time_needed = cum[pos];
        if (time_needed <= remaining_time) {
            // Complete the current pass
            remaining_time -= time_needed;
            total_passes += 1;
            pos = 0;

            // Complete as many full passes as possible
            ll full_passes = remaining_time / cum[0];
            total_passes += full_passes;
            remaining_time -= full_passes * cum[0];

            // Perform additional performances if possible
            while (remaining_time >= d[pos]) {
                remaining_time -= d[pos];
                pos += 1;
                if (pos == n) {
                    total_passes += 1;
                    pos = 0;
                }
            }
        } else {
            // Cannot complete the current pass, perform as many as possible
            while (pos < n && remaining_time >= d[pos]) {
                remaining_time -= d[pos];
                pos += 1;
            }
            // Remaining performances are moved to the next day
        }
        day += 1;
    }

    cout << total_passes << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

//    int t = 1;
//    cin >> t;

    solve();

    return 0;
}