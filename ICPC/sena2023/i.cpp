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

int itm_sum, itm_per_pge, pge_sum, itm_pre_sum, itm_want_sum;
unordered_map<int, set<int>> want;
unordered_map<int, set<int>> pre_sel;
set<int> pge;

int getPgeNum(const int itm_num) {
    return (itm_num - 1) / itm_per_pge + 1;
}

int getPgeItmSum(const int pge_num) {
    if (pge_num == pge_sum) return itm_sum % itm_per_pge == 0 ? itm_per_pge : itm_sum % itm_per_pge;
    return itm_per_pge;
}

int deselectAllAndSelect(const int pge_num) {
    return want[pge_num].size() + 1;
}

int selectAllAndDeselect(const int pge_num) {
    return getPgeItmSum(pge_num) - want[pge_num].size() + 1;
}

int deselectAndSelect(const int pge_num) {
    set<int> diff;
    set_symmetric_difference(
        want[pge_num].begin(), want[pge_num].end(),
        pre_sel[pge_num].begin(), pre_sel[pge_num].end(),
        inserter(diff, diff.begin())
    );
    return diff.size();
}

void solve() {
    int pge_now;
    cin >> itm_sum >> itm_per_pge >> pge_now >> itm_pre_sum >> itm_want_sum;
    pge_sum = ceil(static_cast<double>(itm_sum) / itm_per_pge);

    if (itm_want_sum == 0 && itm_pre_sum == 0) {
        cout << "0\n";
        return;
    }

    int pge_min = INT_MAX;
    int pge_max = INT_MIN;
    for (int i = 1; i <= pge_sum; ++i) {
        want[i].clear();
        pre_sel[i].clear();
    }


    for (int i = 0; i < itm_pre_sum; ++i) {
        int x;
        cin >> x;
        const int pge_num = getPgeNum(x);
        pge.emplace(getPgeNum(x));
        pre_sel[pge_num].emplace(x);
        pge_min = min(pge_min, pge_num);
        pge_max = max(pge_max, pge_num);
    }
    for (int i = 0; i < itm_want_sum; ++i) {
        int x;
        cin >> x;
        const int pge_num = getPgeNum(x);
        pge.emplace(pge_num);
        want[pge_num].emplace(x);
        pge_min = min(pge_min, pge_num);
        pge_max = max(pge_max, pge_num);
    }

    int ans = 0;
    for (const auto p : pge) {
        // cout << "p: " << p << '\n';
        // cout << "want: \n";
        // for (int x : want[p]) {
        //     cout << x << ' ';
        // }
        // cout << '\n';
        int arr[] = {deselectAllAndSelect(p), selectAllAndDeselect(p), deselectAndSelect(p)};
        // for (int i = 0; i < 3; ++i) cout << arr[i] <<' ';
        // cout << '\n';
        ans += *min_element(arr, arr + 3);
    }

    // cout << ans << '\n';

    if (ans != 0) {
        if (pge_now < pge_min) ans += pge_max - pge_now;
        else if (pge_now > pge_max) ans += pge_now - pge_min;
        else ans += min(abs(pge_max - pge_now), abs(pge_now - pge_min)) + (pge_max - pge_min);
    }

    cout << ans << '\n';
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
