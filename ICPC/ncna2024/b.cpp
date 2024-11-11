//
// Created by EHPC6 on 11/9/2024.
//
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string toward, label;
    int length, ants;
    bool operator == (const Node &n) const {
        return toward == n.toward && label == n.label && length == n.length && ants == n.ants;
    }
    bool operator < (const Node &n) const {
        return label < n.label;
    }
    string tostring() const {
        return toward + " " + to_string(length) + " " + to_string(ants) + " " + label;
    }
};

map<Node, int> taken;

inline int get_sum(const vector<Node>& v) {
    int sum = 0, l = 0;
    for (auto& n : v) {
        l += n.length;
        if (!taken[n]) sum += n.ants;
        if (l > 30) break;
    }
    return sum;
}

vector<vector<Node>> ways;

inline int cmp(const vector<Node>& a, const vector<Node>& b) {
    return get_sum(a) > get_sum(b);
}

int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        vector<Node> way;
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            Node n;
            cin >> n.toward >> n.length >> n.ants >> n.label;
            way.emplace_back(n);
        }
        ways.emplace_back(way);
    }

    int res = 0;
    while (m--) {
        sort(ways.begin(), ways.end(), cmp);

        res += get_sum(ways[0]);
        for (auto& n : ways[0]) {
            // cout << "take: " << n.tostring() << "\n";
            taken[n] = 1;
        }
        ways.erase(ways.begin());
    }

    cout << res << '\n';
    return 0;
}