#include <bits/stdc++.h>
using namespace std;

vector<char> pos[5];

int main() {
    for (int c = 0; c < 26; ++c) {
        int id = c;
        int t = 0;
        while (id) {
            if (id & 1) pos[t].emplace_back(c + 'a');
            t += 1;
            id >>= 1;
        }
    }

    for (int i = 0; i < 5; ++i) {
        cout << "at " << i << '\n';
        for (char c : pos[i]) cout << c << ' ';
        cout << '\n';
    }
    return 0;
}