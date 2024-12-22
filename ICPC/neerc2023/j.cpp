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
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    auto get = [&]() -> int{
        int qwq = 0;
        for(int i = 0, j = 0; i < n && j < n; ){
            if(a[i] > b[j]){
                qwq++;
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return qwq;
    };

    int qwq = get();
    for(auto& e : a){
        e = -e;
    }
    for(auto& e : b){
        e = -e;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int owo = n - get();

    cout << qwq - owo + 1 << endl;
    for(int i = owo; i <= qwq; i++){
        cout << i << " ";
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//  cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
