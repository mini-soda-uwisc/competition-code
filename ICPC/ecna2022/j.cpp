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

struct card {
    char suit;
    char rank;
};

vector<card> base;

void cardSolve(vector<card> &face_up);
bool rankSolve(vector<card> &face_up);
bool suitSolve(vector<card> &face_up);

void solve() {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; ++j) {
            string str;
            cin >> str;
            card x{};
            x.rank = str[0];
            x.suit = str[1];
            base.pb(x);
        }
    }

//    for (auto &i: base) {
//        cout << i.rank << i.suit << ' ';
//    }

    int cur = 0;
    vector<card> face_up;
    face_up.pb(base[cur++]);
    face_up.pb(base[cur++]);
    face_up.pb(base[cur++]);
    // 先抽三张牌
    while (cur < 52) {
        face_up.pb(base[cur++]);
        if (face_up.size() >= 4) {
            cardSolve(face_up);
        }
    }
    cout << face_up.size() << " ";
    for (auto &i: face_up) {
        cout << i.rank << i.suit << ' ';
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

void cardSolve(vector<card> &face_up) {
    bool flag1 = rankSolve(face_up);
    bool flag2 = suitSolve(face_up);
    if (!flag1 && !flag2) {
        return;
    } else {
        cardSolve(face_up);
    }
}

bool rankSolve(vector<card> &face_up) {
    int test = (int) face_up.size() - 1;
    bool flag = false;
    // 先检查rank相同，移除4张牌
    while (test >= 3) {
        if (face_up[test].rank == face_up[test - 3].rank) {
            face_up.
                    erase(face_up.begin() + test - 3,
                          face_up.begin() + test + 1);
            flag = true;
            break;
        } else {
            test--;
        }
    }
    if (flag) {
        cardSolve(face_up);
        return true;
    } else {
        return false;
    }
}

bool suitSolve(vector<card> &face_up) {
    int test = (int) face_up.size() - 1;
    bool flag = false;
// 再检查suit相同，移除2张牌
    while (test >= 3) {
        if (face_up[test].suit == face_up[test - 3].suit) {
            face_up.
                    erase(face_up.begin() + test,
                          face_up.begin() + test + 1);
            face_up.erase(face_up.begin() + test - 3,
                          face_up.begin() + test - 2);
            flag = true;
            break;
        } else {
            test--;
        }
    }
    if (flag) {
        cardSolve(face_up);
        return true;
    } else {
        return false;
    }
}