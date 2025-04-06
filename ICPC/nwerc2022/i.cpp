#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int a = 0, b = 0, A = 0, B = 0;
    for (int i = n; i <= m; i++) {
        string s;
        cin >> s;

        if(s[0] == 'F' || s[0] == 'B'){
            if(s[0] == 'F'){
                if(!A){
                    A = i;
                }
                else{
                    a = i - A;
                    A = i;
                }
            }
            if(s[0] == 'B' || s == "FizzBuzz"){
                if(!B){
                    B = i;
                }
                else{
                    b = i - B;
                    B = i;
                }
            }
        }
    }

    if(!a){
        a = (A == 0 ? m + 1 : A);
    }
    if(!b){
        b = (B == 0 ? m + 1 : B);
    }

    cout << a << " " << b << endl;
    return 0;
}