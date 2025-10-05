#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, ans = -1;
pair<int, int> ANS = {-1, -1};

int ch[N * 30][2], ndcnt = 1;
char wc[N * 30];
int tag[N * 30];

void insert(const string& s, int t) {
    int cur = 1;
    for (int i = 1; i <= m; ++i) {
        int id = s[i] == 'Y';
        if (ch[cur][id] == 0) {
            ch[cur][id] = ++ndcnt;
            wc[ndcnt] = id == 1 ? 'Y' : 'N';
        }
        cur = ch[cur][id];
    }

    tag[cur] = t;
    // cout << "tagged: " << cur << " as " << t << '\n';
}

void dfs(const string& s, int t, int cur, int cnt, int x) {
    if (cur == m + 1) {
        if (cnt > ans && t != tag[x]) {
            ans = cnt;
            ANS.first = min(t, tag[x]);
            ANS.second = max(t, tag[x]);
        } else if (cnt == ans && t != tag[x] && min(t, tag[x]) < ANS.first) {
            ANS.first = min(t, tag[x]);
            ANS.second = max(t, tag[x]);
        } else if (cnt == ans && t != tag[x] && min(t, tag[x]) == ANS.first && max(t, tag[x]) < ANS.second) {
            ANS.first = min(t, tag[x]);
            ANS.second = max(t, tag[x]);
        }
        return;
    }
    if (s[cur] == 'Y') {
        if (ch[x][1]) dfs(s, t, cur + 1, cnt + 1, ch[x][1]);
        if (ch[x][0]) dfs(s, t, cur + 1, cnt, ch[x][0]);
    } else {
        if (ch[x][1]) dfs(s, t, cur + 1, cnt, ch[x][1]);
    }
}

string a[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = "0" + a[i];
        insert(a[i], i);
    }

    for (int i = 1; i <= n; ++i) {
        dfs(a[i], i, 1, 0, 1);
    }

    if (ans == -1) cout << "No\n";
    else cout << ANS.first << ' ' << ANS.second << '\n';
    return 0;
}