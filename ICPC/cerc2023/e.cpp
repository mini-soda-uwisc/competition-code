#include <bits/stdc++.h>
using namespace std;

map<string, int> h1, h2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string buf;
    while (true) {
        getline(cin, buf);
        if (buf == "------") break;
        stringstream ss(buf);
        int s, t;
        string p;
        ss >> s >> t >> p;
        h1[p] += t - s;
    }
    while (true) {
        getline(cin, buf);
        if (buf == "======") break;
        stringstream ss(buf);
        int s, t;
        string p;
        ss >> s >> t >> p;
        h2[p] += t - s;
    }
    vector<pair<string, int>> ans;
    for (auto& [name, t] : h1) {
        int s = 0;
        if (h2.find(name) != h2.end()) s = h2[name];
        if (s != t) {
            ans.emplace_back(name, s - t);
        }
    }
    for (auto& [name, t] : h2) {
        if (h1.find(name) == h1.end()) {
            ans.emplace_back(name, t);
        }
    }
    sort(ans.begin(), ans.end());
    if (ans.empty()) {
        cout << "No differences found.\n";
    } else {
        for (auto& [name, t] : ans) {
            if (t < 0) {
                cout << name << " " << t << '\n';
            } else {
                cout << name << " +" << t << '\n';
            }
        }
    }
    return 0;
}