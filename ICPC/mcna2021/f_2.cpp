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

const int N = (int)2e5 + 1, S = N / 2;

int h[N], e[N], ne[N], v1[N], v2[N], c1[N], c2[N], idx, qwq;
string ans;

void add(int u, int v){
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void dfs1(int u, int fa, int color){
    c1[u] = color;
    v1[u] = 1;

    ans += (u < S ? 'F' : 'T');

    if(!qwq){
        return;
    }

    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(j == fa || v1[j]) continue;
        if(c1[j] == color){
            qwq = 0;
        }
        else{
            dfs1(j, u, 3 - color);
        }
    }
}

void dfs2(int u, int fa, int color){
    c2[u] = color;
    v2[u] = 1;

    ans += (u < S ? 'F' : 'T');

    if(!qwq){
        return;
    }

    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(j == fa || v2[j]) continue;
        if(c2[j] == color){
            qwq = 0;
        }
        else{
            dfs2(j, u, 3 - color);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> a;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        a.pb(s);
    }

    fill(h, h + N, -1);
    fill(v1, v1 + N, 0);
    fill(v2, v2 + N, 0);
    idx = 0;

    for(int i = 0; i < n; i++){
        string s = a[i];
        for(int j = 0; j < m; j++){
            if(s[j] == 'X') continue;
            for(int k = 0; k < m; k++) {
                if(j == k) continue;
                if(s[k] == 'X') continue;
                int posj = s[j] == 'T' ? S + j : j;
                int posk = s[k] == 'F' ? S + k : k;
                add(posj, posk);
            }
        }
    }

    string s;
    for(int j = 0; j < m; j++){
        if(v1[j] == 0 && v1[j + S] == 0 && v2[j] == 0 && v2[j + S] == 0){
            qwq = 1;
            ans = "";
            dfs1(j, -1, 1);

            if(!qwq){
                qwq = 1;
                ans = "";
                dfs2(S + j, -1, 2);

                if(!qwq){
                    cout << -1 << endl;
                    return;
                }
                else{
                    s += ans;
                }
            }
            else{
                s += ans;
            }
        }
    }
    if(s.length() != m){
        cout << -1 << endl;
        return;
    }
    cout << s << endl;
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