#include <bits/stdc++.h>
using namespace std;

int n, h;
map<int, int> mp;
priority_queue<pair<int, int>> q;
vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> h;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        ++mp[x];
    }

    for (auto [val, cnt] : mp) {
        q.push({cnt, val});
    }

    int ok = 0;
    while (1) {
        ans.clear();
        for (int i = 1; i <= h && !q.empty(); ++i) {
            auto [cnt, val] = q.top();
            q.pop();
            ans.emplace_back(val);
        }

        if (ans.size() < h) break;
        ok = 1;

        for (int val : ans) {
            cout << val << ' ';
            --mp[val];
            if (mp[val] > 0)
                q.push({mp[val], val});
        }
        cout << '\n';
    }

    if (!ok) {
        cout << "impossible";
    }
    return 0;
}