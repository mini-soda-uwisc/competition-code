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

const int N = (int) 1e5 + 1, M = N * 2;

const int n = 9;

int puzzle[10][10];

int square[10][10];
int column[10][10];
int row[10][10];

inline int getSquareNum(const int x, const int y) {
    if (1 <= x && x <= 3) {
        if (1 <= y && y <= 3) return 1;
        if (4 <= y && y <= 6) return 2;
        if (7 <= y && y <= 9) return 3;
    } else if (4 <= x && x <= 6) {
        if (1 <= y && y <= 3) return 4;
        if (4 <= y && y <= 6) return 5;
        if (7 <= y && y <= 9) return 6;
    } else if (7 <= x && x <= 9) {
        if (1 <= y && y <= 3) return 7;
        if (4 <= y && y <= 6) return 8;
        if (7 <= y && y <= 9) return 9;
    }
    assert(false);
}

inline void update(int x, int y, int v, int input = 0) {
    if (!(1 <= x && x <= 9 && 1 <= y && y <= 9)) {
        cerr << "invalid index: (" << x << ", " << y << ")\n";
        assert(false);
    }
    if (!input && !(1 <= v && v <= 9)) {
        cerr << "invalid value: " << v << '\n';
        assert(false);
    }
    puzzle[x][y] = v;
    row[x][v] = 1;
    column[y][v] = 1;
    square[getSquareNum(x, y)][v] = 1;
}

inline void printPuzzle() {
    bool easy = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (puzzle[i][j] == 0) {
                easy = false;
                break;
            }
        }
        if (!easy) break;
    }
    cout << (easy ? "Easy\n" : "Not easy\n");
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (puzzle[i][j] == 0) {
                cout << ". ";
            } else {
                cout << puzzle[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}

inline bool singleValueRule(int x, int y) {
    if (puzzle[x][y]) {
        return true;
    }
    int possible[10];
    fill_n(possible, 10, 1);
    for (int i = 1; i <= 9; ++i) {
        if (row[x][i]) {
            possible[i] = 0;
        } else if (column[y][i]) {
            possible[i] = 0;
        } else if (square[getSquareNum(x, y)][i]) {
            possible[i] = 0;
        }
    }

    int ans = -1;
    for (int i = 1; i <= 9; ++i) {
        if (possible[i]) {
            if (ans != -1) {
                return false;
            }
            ans = i;
        }
    }

    if (ans == -1) {
        return false;
    }

    update(x, y, ans);

    return true;
}

inline bool uniqueLocationRule(int x, int y) {
    if (puzzle[x][y]) {
        return true;
    }
    int r_t = -1, c_t = -1, s_t = -1;
    for (int i = 1; i <= 9; ++i) {
        if (row[x][i] == 0) {
            if (r_t == -1) r_t = i;
            else if (r_t != 0) r_t = 0;
        }
        if (column[y][i] == 0) {
            if (c_t == -1) c_t = i;
            else if (c_t != 0) c_t = 0;
        }
        if (square[getSquareNum(x, y)][i] == 0) {
            if (s_t == -1) s_t = i;
            else if (s_t != 0) s_t = 0;
        }
    }

    if (r_t != 0 && r_t != -1) {
        update(x, y, r_t);
        return true;
    }
    if (c_t != 0 && c_t != -1) {
        update(x, y, c_t);
        return true;
    }
    if (s_t != 0 && s_t != -1) {
        update(x, y, s_t);
        return true;
    }

    return false;
}

queue<pair<int, int> > q;
bool visited[N][N];

inline void putInNumber() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (puzzle[i][j] != 0) continue;
            if (visited[i][j]) continue;
            if (singleValueRule(i, j) || uniqueLocationRule(i, j)) {
                visited[i][j] = true;
                q.emplace(i, j);
            }
        }
    }
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int v;
            cin >> v;
            update(i, j, v, 1);
        }
    }

    putInNumber();

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        // do (x, y)

        putInNumber();
    }

    printPuzzle();
}


int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //  cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
