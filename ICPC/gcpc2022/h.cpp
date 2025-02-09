#include <bits/stdc++.h>
using namespace std;

set<int> ask(string s){
    cout << "?" << " " << s << endl;
    int n;
    cin >> n;

    set<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    return a;
}

int main() {
    string a = "abcdefghijklmnopqrstuvwxyz";
    auto p = ask(a);
    int len = *max_element(p.begin(), p.end());
    vector<set<int>> vec;

    vec.emplace_back(ask("bdfhjlnprtvxz"));
    vec.emplace_back(ask("cdghklopstwx"));
    vec.emplace_back(ask("efghmnopuvwx"));
    vec.emplace_back(ask("ijklmnopyz"));
    vec.emplace_back(ask("qrstuvwxyz"));

    string ans;
    for (int i = 1; i <= len; ++i) {
        int c = 0;
        for (int t = 0; t < 5; ++t) {
            if (vec[t].find(i) != vec[t].end()) {
                c |= 1 << t;
            }
        }
        ans.push_back(c + 'a');
    }

    cout << "! " << ans << '\n' << flush;
    cin >> ans;
    assert(ans == "correct");
    return 0;
}
