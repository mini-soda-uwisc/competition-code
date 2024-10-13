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
int day_time;
int total_days;
int total_time;
int total_training_time = 0;

vector<int> a;

void solve() {
    cin >> n >> day_time >> total_days;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Precompute cumulative sums of performance durations from each student to the end
    vector<ll> cum(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        cum[i] = cum[i + 1] + a[i];
    }

    ll passes_completed = 0;
    int current_student = 0;
    ll days = 0;
    unordered_map<int, pair<ll, ll>> mp; // current_student -> (day, passes_completed)

    while (days < total_days) {
        // Check if we've been in this state before to detect cycles
        if (mp.find(current_student) != mp.end()) {
            ll prev_days = mp[current_student].first;
            ll prev_passes = mp[current_student].second;
            ll cycle_days = days - prev_days;
            ll cycle_passes = passes_completed - prev_passes;
            if (cycle_days == 0) {
                // Avoid division by zero
                break;
            }
            ll cycles = (total_days - days) / cycle_days;
            passes_completed += cycles * cycle_passes;
            days += cycles * cycle_days;
            if (days >= total_days) {
                break;
            }
        }
        mp[current_student] = {days, passes_completed};

        ll remaining_time = day_time;
        int start_student = current_student;

        // Try to complete the remaining performances in the current rehearsal pass
        while (current_student < n && remaining_time >= a[current_student]) {
            remaining_time -= a[current_student];
            current_student++;
        }

        // Check if we've completed a rehearsal pass
        if (current_student == n) {
            passes_completed++;
            current_student = 0;
            // Try to start new rehearsal passes within the same day
            // While we can complete a full rehearsal pass
            ll full_passes = remaining_time / cum[0];
            passes_completed += full_passes;
            remaining_time -= full_passes * cum[0];

            // Process any remaining performances after full passes
            while (remaining_time >= a[current_student]) {
                remaining_time -= a[current_student];
                current_student++;
                if (current_student == n) {
                    passes_completed++;
                    current_student = 0;
                }
            }
        }

        // If next performance cannot fit, move remaining performances to next day
        days++;
    }

    cout << passes_completed << endl;
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