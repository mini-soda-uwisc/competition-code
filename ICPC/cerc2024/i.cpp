#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> m >> n;

    vector<string> a, s;
    map<string, deque<int>> mp;

    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        a.push_back(t);
    }

    for (int i = 0; i < m; i++) {
        string l, r;
        for (int j = 0; j < n - 1; j++) {
            l += a[j][i];
        }
        for (int j = 1; j < n; j++) {
            r += a[j][i];
        }

        s.push_back(l);
        mp[r].push_back(i);
    }

    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        ans[i] = i;
    }

    for (int i = 0; i < s.size(); i++) {
        string t = s[i];
        if (!mp[t].empty()) {
            int j = mp[t].front();
            mp[t].pop_front();
            ans[i] = j;
        }
        else {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < m; i++) {
        cout << ans[i] + 1 << " \n"[i == m - 1];
    }
    return 0;
}