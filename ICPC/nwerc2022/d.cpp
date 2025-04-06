#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> s;
    for(int i = 0; i < n; i++){
        string S;
        cin >> S;
        s.push_back(S);
    }

    long double f[n + 1][m + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            f[i][j] = 1e18;
        }
    }

    f[0][0] = 0;
    long double ld = 1.0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'X'){
                if(i){
                    if(s[i - 1][j] == 'X'){
                        f[i][j] = min(f[i][j], f[i - 1][j] + 10);
                    }
                    else{
                        f[i][j] = min(f[i][j], f[i - 1][j] + ld * 10 * acos(-1) / 4 + 5);
                    }
                }
                if(j){
                    if(s[i][j - 1] == 'X'){
                        f[i][j] = min(f[i][j], f[i][j - 1] + 10);
                    }
                    else{
                        f[i][j] = min(f[i][j], f[i][j - 1] + ld * 10 * acos(-1) / 4 + 5);
                    }
                }
            }
            else{
                if(i) {
                    if(s[i - 1][j] == 'X'){
                        f[i][j] = min(f[i][j], f[i - 1][j] + 15);
                    }
                    else {
                        f[i][j] = min(f[i][j], f[i - 1][j] + ld * 10 * acos(-1) / 4);
                    }
                }
                if(j){
                    if(s[i][j - 1] == 'X'){
                        f[i][j] = min(f[i][j], f[i][j - 1] + 15);
                    }
                    else{
                        f[i][j] = min(f[i][j], f[i][j - 1] + ld * 10 * acos(-1) / 4);
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << setprecision(20) << f[n - 1][m - 1] + (s[n - 1][m - 1] == 'O' ? 5 : 10) << endl;
    return 0;
}