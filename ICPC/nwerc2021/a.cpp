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

const int N = (int)1e5 + 1, M = N * 2;

double input() {
    string s;
    getline(cin, s);
    assert(s.length() >= 7);
    if (s[7] == 'G') {
        exit(0);
    }

    double res = 0.0;
    sscanf(s.c_str(), "ACCESS DENIED (%lf ms)", &res);
    return res;
}

void solve(){
    string s = "a";
    cout << s << endl;
    int qwq = input();

    auto get = [&](int count) -> int {
        return (count - 5) / 9 - 1;
    };

    if (qwq == 5) {
        for (int i = 0; i < 20; i++) {
            s += "a";
            cout << s << endl;
            qwq = input();
            if (qwq != 5) {
                break;
            }
        }
    }
    qwq = get(qwq);

    for (int i = qwq; i < s.size(); ) {
        for (char j = 'a'; j <= 'z'; j++) {
            s[i] = j;
            cout << s << endl;
            qwq = input();
            int nxt = get(qwq);
            if (nxt != i) {
                i = nxt;
                goto entry;
            }
        }
        for (char j = 'A'; j <= 'Z'; j++) {
            s[i] = j;
            cout << s << endl;
            qwq = input();
            int nxt = get(qwq);
            if (nxt != i) {
                i = nxt;
                goto entry;
            }
        }
        for (char j = '0'; j <= '9'; j++) {
            s[i] = j;
            cout << s << endl;
            qwq = input();
            int nxt = get(qwq);
            if (nxt != i) {
                i = nxt;
                goto entry;
            }
        }
        entry:;
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

    while(t--){
        solve();
    }

    return 0;
}
