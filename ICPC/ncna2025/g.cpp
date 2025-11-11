#include <bits/stdc++.h>
using namespace std;

int k, n;
priority_queue<int> q;
vector<int> ans;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> k;
    for (int i = 1; i <= k; ++i) {
        int x;
        cin >> x;
        q.push(-x);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        q.push(0);
        q.push(0);
        q.push(0);
    }

    while (!q.empty()) {
        if (q.size() <= 1) break;
        int x = -q.top();
        q.pop();
        int y = -q.top();
        q.pop();

        // cout << x << ' ' << y << '\n';
        if (x != y) {
            ans.emplace_back(x);
            q.push(-y);
            continue;
        }

        q.push(-(x + 1));
    }

    if (q.size()) {
        ans.emplace_back(-q.top());
    }

    sort(ans.begin(), ans.end());

    for (int v : ans) {
        cout << v << ' ';
    }
    return 0;
}