#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<int> b;

int getnext(int x, int y) {
    x += y;
    x %= a.size();
    return x;
}
int getpre(int x, int y) {
    x -= y;
    while (x < 0) x += a.size();
    return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = i + 1;
    }

    int size = n;
    int pre = 0;
    while (a.size() != 1) {
        const int id = getnext(pre, a[pre] - 1);
        // cout << "id = " << id << '\n';
        // cout << "kicked: " << a[id] << '\n';
        a.erase(a.begin() + id);
        b.erase(b.begin() + id);

        --size;
        if (id == size) pre = 0;
        else pre = id;
    }

    cout << b[0] << '\n';
    return 0;
}