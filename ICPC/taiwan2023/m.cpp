#include <bits/stdc++.h>
using namespace std;

struct Node {
    int ans, id, priority;
};

int cmp(Node& a, Node& b) {
    if (a.priority != b.priority) return a.priority < b.priority;
    return a.id < b.id;
}

inline void solve() {
    int n;
    cin >> n;
    vector<Node> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].id = i;
        cin >> a[i].ans;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].priority;
    }

    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; ++i) {
        cout << a[i].ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}