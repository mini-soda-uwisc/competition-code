#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back

const ld pi = 3.14159265358979323846;
const int mod = 998244353;
const ll INF = 1e18;

// Up, Right, Down, Left
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n = 0;

//bool not_valid_flag = false;

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

struct Point {
    int type{}; // 0 - empty, 1 - block with no number, 2 - block with number, 3 - light
    int block_number{};
    bool lighted = false;
};

vector<vector<Point>> grid(100, vector<Point>(100));

const int N = (int) 1e5 + 1, M = N * 2;

void solve_input() {
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '.') {
                grid[i][j].type = 0;
                grid[i][j].lighted = false;
            } else if (s[j] == 'X') {
                grid[i][j].type = 1;
                grid[i][j].lighted = true;
            } else if (s[j] == '?') {
                grid[i][j].type = 3;
                grid[i][j].lighted = true;
            } else if (s[j] >= '0' && s[j] <= '4') {
                grid[i][j].type = 2;
                grid[i][j].block_number = s[j] - '0';
                grid[i][j].lighted = true;
            }
        }
    }
}

bool light_up(int x, int y) {
    if (grid[x][y].type == 1 || grid[x][y].type == 2) return true;
    if (grid[x][y].type == 3) {
        cout << 0 << endl;
        exit(0);
//        return true;
    }
    grid[x][y].lighted = true;
    return false;
}

void enlighten() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j].type == 3) {
                // Illuminate up
                for (int x = i - 1; x >= 0; --x) {
                    if (light_up(x, j)) break;
                }
                // Illuminate down
                for (int x = i + 1; x < n; ++x) {
                    if (light_up(x, j)) break;
                }
                // Illuminate left
                for (int y = j - 1; y >= 0; --y) {
                    if (light_up(i, y)) break;
                }
                // Illuminate right
                for (int y = j + 1; y < n; ++y) {
                    if (light_up(i, y)) break;
                }
            }
        }
    }

    // Check if every open cell is enlightened
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j].type == 0 && !grid[i][j].lighted) {
//                cout << i << " " << j << endl;
                cout << 0 << endl;
                exit(0);
//                return;
            }
        }
    }
}


void check_block() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j].type == 2) {
                int count = 0;
                int expected_count = grid[i][j].block_number;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y].type == 3) {
                        count++;
                    }
                }
                if (count != expected_count) {
                    cout << 0 << endl;
                    exit(0);
//                    return;
                }
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


    cin >> n;

    solve_input();

    enlighten();
//    if (not_valid_flag) {
////        cout << 0 << " because of enlighten" << endl;
//        return 0;
//    }

    check_block();
//    if (not_valid_flag) {
////        cout << 0 << "because of check_block" << endl;
//        return 0;
//    }

    cout << 1 << endl;
    return 0;
}