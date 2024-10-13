#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int) 1e5 + 1, M = N * 2;

struct Person {
    int position; // 0: left, 1: right
    int status; // 0: initial, 1: first, 2: done
    int nxtTime; // 下次可移动时间

    bool operator<(const Person &other) const {
        return nxtTime < other.nxtTime;
    }
};

void solve() {
//    int nowTime = 0;
//    int n, restTime, walkTime; // n: number of people, restTime: relax nxtTime, walkTime: walk nxtTime
//    cin >> n >> restTime >> walkTime;
//    int left = n, right = n;
//    priority_queue<Person> statusLeft, statusRight;
//    int statusMe = 0;
//    for (int i = 0; i < n; ++i) {
//        Person person{0, 0, 0};
//        statusLeft.push(person);
//    }
//    for (int i = n; i < 2 * n; ++i) {
//        Person person{1, 0, 0};
//        statusLeft.push(person);
//    }
//    while (!statusLeft.empty() && !statusRight.empty()) {
//        Person personLeft = statusLeft.top();
//        Person personRight = statusRight.top();
//        if (statusMe == 0)// 我在左边
//        {
//            if (personLeft.nxtTime > walkTime + personRight.nxtTime) {
//                nowTime  = walkTime + personRight.nxtTime;
//                statusMe = 1;
//
//            }
//            if (personLeft.nxtTime <= nowTime) {
//                nowTime  = personLeft.nxtTime;
//                statusMe = 1;
//                personLeft.position = 1;
//                personLeft.status = 1;
//                personLeft.nxtTime = nowTime + restTime;
//                statusRight.push(personRight);
//            }
//        }
//    }
    ll n, x, t;
    cin >> n >> x >> t;
    cout << min(2 * n * t + max(x - (2 * n - 2) * t, 0ll) + 2 * n * t,
                2 * n * t + t + max(x - (2 * n - 1) * t - t, 0ll) + 2 * n * t) << '\n';
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}