//
// Created by EHPC6 on 11/9/2024.
//
#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  int l, r;
    cin >> n;
    cin >> l >> r;
    for (int i = 2; i <= n; ++i) {
        int nl, nr;
        cin >> nl >> nr;
        l = max(l, nl);
        r = min(r, nr);
    }
    if (l <= r) cout << r - l + 1 << ' ' << l << '\n';
    else cout << "bad news\n";
  return 0;
 }