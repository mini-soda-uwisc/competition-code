#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n;
int g[N], h[N];
map<int, int> pos;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> g[i];
        pos[g[i]] = i;
    }
    return 0;
}