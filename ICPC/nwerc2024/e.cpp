#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
string s;

map<string, int> vis;
map<string, string> nxt;
string ans;

string dfs(const string& stat, int steps) {
    if (steps == k + 1) {
        return stat;
    }

    vis[stat] = steps;
    string tmp = stat + stat;
    string r;
    for (int i = 0; i < n * 2; i += 2) {
        r.push_back(tmp[i]);
    }

//    cout << r << '\n';

    nxt[stat] = r;
    if (!vis[r]) {
        return dfs(r, steps + 1);
    }

    int circle_length = steps - vis[r] +;
    int remain = k - steps;

//    cout << "I got this! length: " << circle_length << ", remain: " << remain << '\n';

    remain %= circle_length;

//    cout << "After remain: " << remain << '\n';

    for (int t = 1; t <= remain; ++t) {
        r = nxt[r];
    }
    return r;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    srand((unsigned)time(NULL));
//
//    cin >> n >> k;
//    cin >> s;

    int cnt = 1;
    while(1) {
        n = rand() % 10 + 1, k = rand() % 1000 + 1;
        for (int i = 0; i < n; i++) {
            s += (char) (rand() % 26 + 'a');
        }
        vis.clear();
        nxt.clear();

        string s1 = dfs(s, 1);
        string s2 = s + s;
        for (int i = 0; i < k; i++) {
            string s3 = "";
            for (int j = 0; j < n * 2; j += 2) {
                s3 += s2[j];
            }
            s2 = s3 + s3;
        }
        s2 = s2.substr(0, n);

        if (s1 == s2) {
            cout << "test" << cnt << " : " << "Ok" << endl;
        } else {
            cout << "test" << cnt << " : WA " << s << " " << k << endl;
            cout << "GOOD " << s2 << endl;
            cout << "BAD " << s1 << endl;
            break;
        }
        cnt++;
    }
    return 0;
}