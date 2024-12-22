#include <bits/stdc++.h>
using namespace std;

int n, k, cur = 1;

vector<int> rpos[20];

int ask(int l, int r) {
    cout << l << ' ' << r << '\n' << flush;
    int x;
    cin >> x;
    return x;
}

bool dfs(int depth) {
    if (depth == rpos[cur].size()) return false;
    if (dfs(depth + 1)) return true;

    int tmp = ask(cur, rpos[cur][depth]);

    bool flag = false;

    if (tmp == n) {
        k = n;
        return true;
    } else if (tmp < k) {
        flag = true;
        tmp = ask(cur, rpos[cur][depth]);
        k = tmp;
    } else if (tmp > k) {
        flag = true;
        k = tmp;
    }

    if (dfs(depth + 1)) return true;
    return flag;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= i; --j) {
            rpos[i].emplace_back(j);
        }
    }
    while (k != n && cur != n + 1) {
        dfs(0);
        ++cur;
    }
    return 0;
}