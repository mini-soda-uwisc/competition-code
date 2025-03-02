#include <bits/stdc++.h>
using namespace std;

struct Team {
    string name;
    int score;
    int id;
};

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<Team> teams;
    for (int i = 1; i <= n; ++i) {
        string name;
        cin >> name;
        int p;
        cin >> p;
        vector<int> e(6);
        for (int j = 0; j < 6; ++j) {
            cin >> e[j];
        }
        sort(e.begin(), e.end());
        Team t;
        t.name = name;
        t.score = p * 10 + e[1] + e[2] + e[3] + e[4];
        t.id = i;
        teams.emplace_back(t);
    }
    sort(teams.begin(), teams.end(), [](const Team& a, const Team& b) {
        if (a.score != b.score) return a.score > b.score;
        return a.id < b.id;
    });
    int last = 0;
    for (int i = 0; i < teams.size(); ++i) {
        if (i != 0 && teams[i].score != teams[i - 1].score) last = i;
        if (last > 2) break;
        cout << teams[i].name << ' ' << teams[i].score << '\n';
    }
    return 0;
}