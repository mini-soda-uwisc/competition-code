#include <bits/stdc++.h>
using namespace std;

string LCS(const string& a, const string& b) {
    int n = a.size();
    unordered_map<char, int> pos;
    pos.reserve(n);
    for (int i = 0; i < n; ++i) {
        pos[a[i]] = i;
    }

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = pos[b[i]];
    }

    vector<int> tailIdx;
    tailIdx.reserve(n);
    vector<int> prevIdx(n, -1);

    for (int i = 0; i < n; ++i) {
        int l = 0, r = tailIdx.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (p[tailIdx[mid]] < p[i]) l = mid + 1;
            else r = mid;
        }
        int posL = l;

        if (posL > 0) {
            prevIdx[i] = tailIdx[posL - 1];
        }

        if (posL == (int)tailIdx.size()) {
            tailIdx.push_back(i);
        } else {
            tailIdx[posL] = i;
        }
    }

    vector<int> listIdx;
    listIdx.reserve(tailIdx.size());
    for (int k = tailIdx.back(); k != -1; k = prevIdx[k]) {
        listIdx.push_back(k);
    }
    reverse(listIdx.begin(), listIdx.end());

    string lcs;
    lcs.reserve(listIdx.size());
    for (int i : listIdx) {
        lcs.push_back(b[i]);
    }

    return lcs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int n, k;
    // cin >> n >> k;
    // string lcs;
    // cin >> lcs;
    // for (int i = 2; i <= n; ++i) {
    //     string x;
    //     cin >> x;
    //     lcs = LCS(lcs, x);
    // }
    // cout << lcs.length() << '\n';
    string s, t;
    cin >> s >> t;
    cout << LCS(s, t);
    return 0;
}