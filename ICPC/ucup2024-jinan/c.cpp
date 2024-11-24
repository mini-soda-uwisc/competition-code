#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

const int N = (int)1e5 + 1, M = N * 2;

void solve(){
    int n, qwq = 0;
    cin >> n;

    n = (n - 1) / 2;
    vector<vector<int>> a;
    vector<int> op;

    for(; n;){
        if(n % 2 == 0 || n == 1){
            op.pb(1);
            n--;
        }
        if(!n){
            break;
        }
        n = (n - 1) / 2;
        op.pb(0);
    }

    /*
     *
     * 3
POP 1 GOTO 2; PUSH 1 GOTO 1
POP 2 GOTO 3; PUSH 2 GOTO 2
HALT; PUSH 1 GOTO 1
     */

    reverse(op.begin(), op.end());
    for(auto e : op){
        qwq++;
        if(e){
            a.pb({qwq, qwq + 1, qwq, qwq});
        }
        else{
            a.pb({qwq, qwq + 1, qwq, 1});
        }
    }

    cout << a.size() + 1 << endl;
    for(auto v : a){
        cout << "POP " << v[0] << " GOTO " << v[1] << "; PUSH " << v[2] << " GOTO " << v[3] << endl;
    }
    cout << "HALT; " << "PUSH 1 " << "GOTO 1" << endl;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}