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
int ne[N];

void solve(){
    int n;
    cin >> n;

    auto get_idx = [&](string y, string x) -> vector<int> {
        string t = " " + x;
        for(int i = 2, j = 0; i <= x.size(); i++){
            while(j && t[i] != t[j + 1]) {
                j = ne[j];
            }
            if(t[i] == t[j + 1]) j++;
            ne[i] = j;
        }

        string s = " " + y;
        vector<int> a;

        for(int i = 1, j = 0; i <= y.size(); i++){
            while(j && s[i] != t[j + 1])
                j = ne[j];
            if(s[i] == t[j + 1]) j++;
            if(j == x.size()){
                a.pb(i - x.size());
                j = ne[j];
            }
        }
        return a;
    };

    auto check = [&](char ch) -> int {
        return (0 <= ch - 'a' && ch - 'a' <= 25) || (0 <= ch - 'A' && ch - 'A' <= 25);
    };

    string s = "", ds = "";
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        s += t + "?";
        if (t.size() == 1 && check(t[0])) {
            ds += "i?";
        }
        else {
            ds += t + "?";
        }
    }

    vector<char> b;
    for (int i = 0; i < 26; i++) {
        b.pb((char)(i + 'a'));
        b.pb((char)(i + 'A'));
    }
    sort(b.begin(), b.end());

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string mt = "", dmt = "";
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            string dt;
            cin >> dt;

            mt += dt + "?";
            if (dt.size() == 1 && check(dt[0])) {
                dmt += "i?";
            }
            else {
                dmt += dt + "?";
            }
        }

        auto p = get_idx(ds, dmt);
        if (p.empty()) {
            cout << "no" << endl;
            continue;
        }

        map<char, int> mp1;

        for (int j = 0, k = 0; j < mt.size(); j++) {
            int A = j && j + 1 < mt.size() && mt[j - 1] == '?' && mt[j + 1] == '?';
            int B = (j == 0 && j + 1 < mt.size() && mt[j + 1] == '?');
            int C = (j == mt.size() - 1 && j && mt[j - 1] == '?');
            if ((A || B || C) && check(mt[j])) {
                if (!mp1.count(mt[j])) {
                    mp1[mt[j]] = k++;
                }
                mt[j] = b[mp1[mt[j]]];
            }
        }

        mp1.clear();
        string match = "";
        for (int j = 0, pt = 0, k = 0; j < s.size(); j++) {
            if ((pt < p.size() && j == p[pt]) || match.size() == mt.size()) {
                if (match == mt) {
                    cout << "yes" << endl;
                    goto entry;
                }

                match = "";
                k = 0;
                mp1.clear();
                if (j == p[pt]) {
                    pt++;
                }
            }

            int A = j && j + 1 < s.size() && s[j - 1] == '?' && s[j + 1] == '?';
            int B = (j == 0 && j + 1 < s.size() && s[j + 1] == '?');
            int C = (j == s.size() - 1 && j && s[j - 1] == '?');
            if ((A || B || C) && check(s[j])) {
                if (!mp1.count(s[j])) {
                    mp1[s[j]] = k++;
                }
                match += b[mp1[s[j]]];
            }
            else {
                match += s[j];
            }
        }
        if (match == mt) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
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
