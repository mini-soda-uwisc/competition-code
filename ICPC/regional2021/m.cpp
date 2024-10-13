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
    std::size_t operator()(const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
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
    total_time = day_time * total_days;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_training_time += a[i];
    }
    // 如果训练时间大于总时间，那么输出0，退出
    if (total_training_time > total_time) {
        cout << 0 << endl;
        exit(0);
    }

    // 开始枚举，找循环节
//    int loop_time = 0;
    int now_team = 0;
    int loop_days = 0;
    int loop_round = 0;
    unordered_map<pair<int, int>, int, pair_hash> mp; // 匹配：当前队伍，剩余时间。 字典：当前天数
//    vector<int> loop;
    do {
        int remain_day_time = day_time;
        while (remain_day_time >= a[now_team]) {
            remain_day_time -= a[now_team];
//            loop_time += a[now_team];
            // 实时输出当前队伍和剩余时间
//            cout << "Current team: " << now_team << ", Remaining day time: " << remain_day_time << endl;
            now_team++;
//            loop.pb(a[now_team]);
            if (now_team == n) {
//                now_team = 0;
                loop_round++;
            }
            now_team %= n;
        }
        mp.insert(make_pair(now_team, remain_day_time), loop_days);
        loop_days++;
//        cout << "End of day " << loop_days << ", Loop round: " << loop_round << endl;
    } while (now_team != 0 && loop_days < total_days);
//    cout << " Loop Round: " << loop_round << " Loop Days: " << loop_days << endl;

    // 找到循环节，开始计算总共可以训练几轮
    int total_round = total_days / loop_days * loop_round;
    int left_days = total_days % loop_days;
//    loop_time = 0;
    now_team = 0;
    loop_days = 0;
    loop_round = 0;
//    loop.clear();
    do {
        int remain_day_time = day_time;
        while (remain_day_time >= a[now_team]) {
            remain_day_time -= a[now_team];
//            loop_time += a[now_team];
            now_team++;
//            loop.pb(a[now_team]);
            if (now_team == n) {
//                now_team = 0;
                loop_round++;
            }
            now_team %= n;
        }
        loop_days++;
    } while (now_team != 0 && loop_days < left_days);
//    cout << " Loop Round: " << loop_round << " Loop Days: " << loop_days << endl;
    cout << loop_round + total_round << endl;
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