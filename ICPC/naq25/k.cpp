#include <bits/stdc++.h>
using namespace std;

int ask(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int t;
    scanf("%d", &t);
    return t;
}

void answer(int x, int y) {
    printf("! %d %d\n", x, y);
    exit(0);
}

void ask33(int x, int y) {
    int p = ask(x - 1, y);
    if (p) {
        int q = ask(x - 1, y - 1);
        if (q) answer(x - 1, y - 1);
        else answer(x - 1, y);
    } else {
        int q = ask(x, y - 1);
        if (q) answer(x, y - 1);
        else answer(x, y);
    }
}

int main() {
    int a = ask(2, 2);
    if (a) ask33(2, 2);
    a = ask(2, 4);
    if (a) ask33(2, 4);
    a = ask(4, 2);
    if (a) ask33(4, 2);
    ask33(4, 4);
    return 0;
}