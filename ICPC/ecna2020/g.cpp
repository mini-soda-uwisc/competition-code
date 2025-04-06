#include <bits/stdc++.h>
using namespace std;

int n, m;
int pre[110], cur[110];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        pre[i] = i;
    }
    while (m--) {
        int x, y;
        string ttttx, tttty;
        cin >> ttttx >> tttty;
        x = stoi(ttttx.substr(1));
        y = stoi(tttty.substr(1));
        int p = 1;
        int idx = -1, idy = -1;
        for (int i = 1; i <= n; ++i) {
            if (pre[i] == x) idx = i;
            if (pre[i] == y) idy = i;
        }
        assert(idx != -1 && idy != -1);
        if (idx < idy) continue;

        for (int i = 1; i <= n; ++i) {
            if (pre[p] == y) {
                ++p;
            }
            if (pre[p] == x) {
                cur[i] = x;
                cur[++i] = y;
                ++p;
                continue;
            }
            cur[i] = pre[p];
            ++p;
        }
        memcpy(pre + 1, cur + 1, n * sizeof(int));
        // printf("m: %d, x: %d, y: %d\n", m, x, y);
        // for (int i = 1; i <= n; ++i) {
        //     printf("%d ", pre[i]);
        // }
        // printf("\n");
    }

    for (int i = 1; i <= n; ++i) {
        printf("T%d ", pre[i]);
    }
    return 0;
}