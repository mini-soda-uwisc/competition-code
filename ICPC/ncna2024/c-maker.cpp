//
// Created by EHPC6 on 11/9/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
        priority_queue<int> q;
        for (int i = 1; i <= 5; ++i) q.push(-i);
        while (!q.empty()) {
                cout << q.top() << '\n';
                q.pop();
        }
        return 0;
}