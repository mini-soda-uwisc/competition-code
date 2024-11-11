//
// Created by EHPC6 on 11/9/2024.
//
#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
    int val;
    Node *l, *r;
    Node(int val, Node *l, Node *r) : val(val), l(l), r(r) {

    }
};

priority_queue<int> q;

int n, d, l;
int ans = 0;

void dfs(Node *cur, int val) {
    // cout << "cur: " << cur << ", val: " << val << '\n';
    if (cur->l == nullptr && cur->r == nullptr) {
        // cout << "reach leaf, cur_ans: " << val + cur->val << '\n';
        ans = max(ans, val + cur->val);
        return;
    }

    dfs(cur->l, val + cur->val);
    dfs(cur->r, val + cur->val);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("c-in.txt", "r", stdin);

    cin >> n >> d >> l;
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        q.push(-v);
    }

    while (q.size() > 1) {
        int vx = q.top();
        vx = -vx;
        q.pop();
        int vy = q.top();
        vy = -vy;
        q.pop();

        q.push(-(max(vx, vy) + d));
    }


    cout << -q.top() + l << '\n';
    return 0;
}