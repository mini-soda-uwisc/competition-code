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

const char tetrisSet[7] = {'J', 'L', 'S', 'Z', 'I', 'O', 'T'};
map<char, int> mp;
string s;

bool testMapNotPass() {
    for (char j: tetrisSet) {
        if (mp[j] > 1) {
            return true;
        }
    }
    return false;
}

void useMap(int left, int right) {
    mp.clear();
    for (int i = left; i < right; ++i) {
        mp[s[i]]++;
    }
}

bool solve() {
    cin >> s;


    for (int i = 0; i < (7 > s.length() ? s.length() : 7); ++i) {
        bool flag = false;
        useMap(0, i);
        if (testMapNotPass()) { continue; }

        int index = i;
        while (index + 7 < s.length()) {
            useMap(index, index + 7);
            if (testMapNotPass()) {
                flag = true;
                break;
            }
            index += 7;
        }
        if (flag) { continue; }

        useMap(index, (int) s.length());
        if (testMapNotPass()) { continue; }
        return true;
    }
    return false;
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
        bool result = solve();
        if (result) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}