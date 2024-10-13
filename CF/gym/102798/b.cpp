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

const int N = (int)1e6 + 1, M = N * 2;

int dirx[4] = {0, 0, 1, -1}, diry[4] = {-1, 1, 0, 0};

void solve(){
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<vector<int>> a, b;
    map<pair<int, int>, int> mp;

    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;

        a.pb({x, y});
        mp[{x, y}] = 1;
    }

    int p1[n + 1][m + 1], p2[n + 1][m + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            p1[i][j] = mp[{i + 1,  j + 1}];
            p2[i][j] = mp[{i + 1, j + 1}];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            p1[i][j] += p1[i - 1][j];
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            p2[j][i] += p2[j - 1][i];
        }
    }

    for(int i = 0; i < k; i++){
        int x = a[i][0], y = a[i][1];
        for(int j = 0; j < 4; j++) {
            int dx = x + dirx[i], dy = y + diry[i];
            if(dx < 0 || dy < 0 || dx > n || dy > m){
                continue;
            }
            if(mp[{dx, dy}]) continue;
            mp[{dx, dy}] = 1;
            b.pb({dx, dy});
        }
    }

    int l = b.size();
    int f[l][n + 1][m + 1];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                f[i][j][k] = 0;
            }
        }
    }

    for(int i = 0; i < b.size(); i++){
        int x = b[i][0], y = b[i][1];
        f[0][x][y] = 0;

        queue<pair<int, int>> q;
        q.push({x, y});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int nx = p.first, ny = p.second;
            for(int j = 0; j < 4; j++){
                int dx = nx = dirx[j], dy = ny + diry[j];
                if(dx < 0 || dy < 0 || dx > n || dy > m || mp[{dx, dy}]){
                    continue;
                }
                if(f[i][dx][dy] > f[i][nx][ny] + 1) {
                    f[i][dx][dy] = f[i][nx][ny] + 1;
                    q.push({dx, dy});
                }
            }
        }
    }

    for(int i = 0; i < q; i++){
        int x1, y1, x2, y2;

        if(k == 0){
            cout << abs(x1 - x2) + abs(y1 - y2) << endl;
        }
        else{
            int qwq = 1e9;
            for(int j = 0; j < k; j++) {
                qwq = chmin(qwq, f[j][x1][y1] + f[j][x2][y2]);
            }
            cout << (qwq == 1e9 ? -1 : qwq) << endl;
        }
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}