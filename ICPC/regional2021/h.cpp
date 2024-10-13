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

int jpx[8] = {-2, -2, -1, -1, 1, 1, 2, 2}, jpy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};

void solve(){
    int n, m;
    cin >> n >> m;

    char c[n][m];
    vector<vector<int>> d(n, vector<int>(m, 0)), v(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            v[i][j] = d[i][j] = 0;
            c[i][j] = s[j];
        }
    }

    map<pair<int, int>, int> mp;
    auto set = [&](int q, int p, int op) -> void{
         for(int i = 0; i < 8; i++){
            int x = q + jpx[i], y = p + jpy[i];
            if(x < 0 || y < 0 || x >= n || y >= m){
                continue;
            }
            d[x][y] += op;
         }
    };

    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(c[i][j] == 'R'){
                q.push({i, j});
                v[i][j] = 1;
            }
            if(c[i][j] == 'K'){
                set(i, j, 1);
            }
        }
    }
 
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << d[i][j] << " ";
    //     } cout << endl;
    // }

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;

        queue<pair<int, int>> hr;

        for(int i = 0; i < 4; i++){
            int dx = x + dirx[i], dy = y + diry[i];
            while(dx >= 0 && dy >= 0 && dx < n && dy < m){
                if(v[dx][dy]){

                }
                else if(d[dx][dy]){
                    mp[{dx, dy}] = 1;
                    if(c[dx][dy] == 'K'){
                        break;
                    }
                }
                else{
                    if(c[dx][dy] == 'K'){
                        hr.push({dx, dy});
                        break;
                    }
                    else if(c[dx][dy] == 'T'){
                        cout << "yes" << endl;
                        return;
                    }
                    else{
                        v[dx][dy] = 1;
                        q.push({dx, dy});
                        // cout << "first " << dx << " " << dy << " " << v[dx][dy] << endl;
                    }
                }
                dx += dirx[i], dy += diry[i];
            }
        }
        // cout << q.size() << endl;

        while(!hr.empty()){
            auto kn = hr.front();
            hr.pop();

            int nx = kn.first, ny = kn.second;
            c[nx][ny] = '.';
            v[nx][ny] = 1;

            q.push({nx, ny});
            // cout << "second " << nx << " " << ny << endl;
            set(nx, ny, -1);

            for(int i = 0; i < 8; i++){
                int dx = nx + jpx[i], dy = ny + jpy[i];
                if(dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
                if(v[dx][dy]) continue;
                if(!d[dx][dy] && mp[{dx, dy}]){
                    mp[{dx, dy}] = 0;
                    if(c[dx][dy] == 'K'){
                        hr.push({dx, dy});
                    }
                    else{
                        if(c[dx][dy] == 'T'){
                            cout << "yes" << endl;
                            return;
                        }
                        c[dx][dy] = '.';
                        v[dx][dy] = 1;
                        q.push({dx, dy});
                        // cout << "third " << dx << " " << dy << endl;
                    }
                }
            }
        }
        // cout << q.size() << endl;
    }
    cout << "no" << endl;
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
