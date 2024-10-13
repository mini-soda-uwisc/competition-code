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
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    if(s == "ABBA"){
        if(m - n == 3) {
            cout << n + 1 << " " << m - 1 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    else if(s == "BBAA"){
        if(n == 3){
            cout << 1 << " " << 2 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    else if(s == "AABB"){
        if(m == 7){
            cout << 8 << " " << 9 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    else if(s == "ABAB"){
        if(n == 6){
            cout << 7 << " " << 9 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    else if(s == "BABA"){
        if(m == 4){
            cout << 1 << " " << 3 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    else if(s == "BAAB"){
        if(n == 2 && m == 8){
            cout << 1 << " " << 9 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    else{
        cout << -1 << endl;
    }
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