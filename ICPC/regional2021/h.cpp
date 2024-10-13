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

int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};

void solve(){
    int n, m;
    cin >> n >> m;

    char c[n][m];
    vector<vector<int>> d(n, vector<int>(m, 0));

    pair<int, int> st;

    auto set = [&](int i, int j, int op) -> void{
        if(i - 2 >= 0 && j - 1 >= 0) d[i - 2][j - 1] = op;
        if(i - 2 >= 0 && j + 1 < m) d[i - 2][j + 1] = op;
        if(i - 1 >= 0 && j - 2 >= 0) d[i - 1][j - 2] = op;
        if(i - 1 >= 0 && j + 2 < m) d[i - 1][j + 2] = op;
        if(i + 1 < n && j - 2 >= 0) d[i + 1][j - 2] = op;
        if(i + 1 < n && j + 2 < m) d[i + 1][j + 2] = op;
        if(i + 2 < n && j - 1 >= 0) d[i + 2][j - 1] = op;
        if(i + 2 < n && j + 1 < m) d[i + 2][j + 1] = op;
    };

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            c[i][j] = s[j];

            if(c[i][j] == 'R'){
                st = {i, j};
            }
            if(c[i][j] == 'K'){
                set(i, j, 1);
            }
        }
    }

    while(1){
        queue<pair<int, int>> q;
        q.push(st);

        vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
        vector<pair<int, int>> hr;
        vis[0][0] = 1;

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();

            int x = p.first, y = p.second;
            for(int i = 0; i < 4; i++){
                int dx = dirx[i] + x, dy = diry[i] + y;
                if(dx < 0 || dy < 0 || dx >= n || dy >= m){
                    continue;
                }
                if(vis[dx][dy] || d[dx][dy]){
                    continue;
                }
                vis[dx][dy] = 1;

                if(c[dx][dy] == 'T'){
                    cout << "yes" << endl;
                    return;
                }
                if(c[dx][dy] == 'K'){
                    hr.pb({dx, dy});
                    continue;
                }
                q.push({dx, dy});
            }
        }

        if(hr.size() == 0){
            cout << "no" << endl;
            return;
        }
        else{
            for(auto p : hr){
                c[p.first][p.second] = '.';
                set(p.first, p.second, 0);
            }
        }
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