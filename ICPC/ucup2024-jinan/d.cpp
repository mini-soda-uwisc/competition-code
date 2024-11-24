#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> sta;
int pc = 0;
const int MAXTIME = (int)1e9;

struct Instr {
    int type;
    int v1, add1, v2, add2;
    Instr() {

    }

    Instr(string& s) {
        if (s[0] == 'H') {
            type = 0;
            sscanf(s.c_str(), "HALT; PUSH %d GOTO %d", &v1, &add1);
        } else {
            type = 1;
            sscanf(s.c_str(), "POP %d GOTO %d; PUSH %d GOTO %d", &v1, &add1, &v2, &add2);
        }
    }
    void exec() {
        if (type == 0) {
            if (sta.empty()) {
                pc = 0;
                return;
            } else {
                sta.push(v1);
                pc = add1;
            }
        } else {
            if (!sta.empty() && sta.top() == v1) {
                sta.pop();
                pc = add1;
            } else {
                sta.push(v2);
                pc = add2;
            }
        }
    }

    void print() {
        printf("type: %d\n", type);
        if (type == 0) {
            printf("HALT; PUSH %d GOTO %d\n", v1, add1);
        } else {
            printf("POP %d GOTO %d; PUSH %d GOTO %d\n", v1, add1, v2, add2);
        }
    }
} instrs[2000];

int dfs(int x, int stop, int sempty) {
    Instr &instr = instrs[x];

    if (instr.type == 0) {
        if (sempty) return 1;
        else {
            return 1 + dfs(instr.add1, );
        }
    }
}

int main() {
    cin >> n;
    getchar();
    for (int i = 1; i <= n; ++i) {
        string s;
        getline(cin, s);
        instrs[i] = Instr(s);
//        instrs[i].print();
    }
    pc = 1;
    int ans = 0;
    while (pc != 0) {
        instrs[pc].exec();
        ++ans;
        if (ans > MAXTIME) {
            cout << "-1\n";
            return 0;
        }
    }
    cout << (ans % 998244353) << '\n';
    return 0;
}