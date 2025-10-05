#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Unit {
public:
    virtual ~Unit() = default;

    virtual ll eval() {
        return 0;
    }

    virtual void print(int ft) = 0;
};

class Operator : public Unit {
public:
    char type;
    vector<Unit*> input;
    ll eval() {
        // cerr << "eval op: " << type << '\n';
        ll a = input[0]->eval();
        ll b = input[1]->eval();
        ll res = 0;
        switch (type) {
        case '+': res = a + b; break;
        case '-': res = max(a, b) - min(a, b); break;
        case '*': res = a * b; break;
        case '/': res = max(a, b) / min(a, b); break;
        default: assert(false);
        }
        return res;
    }

    void print(int ft) {
        string p;
        for (int i = 0; i < ft; ++i) p += "\t";
        cout << p << "operator " << type << "\n";
        cout << p << "left {\n";
        input[0]->print(ft + 1);
        cout << p << "}\n" << p << "right {\n";
        input[1]->print(ft + 1);
        cout << p << "}\n";
    }
};

class Connector : public Unit {
public:
    Unit *input;
    ll eval() {
        // cerr << "eval connector\n";
        return input->eval();
    }

    void print(int ft) {
        string p;
        for (int i = 0; i < ft; ++i) p += "\t";
        cout << p << "connector {\n";
        input->print(ft + 1);
        cout << p << "}\n";
    }
};

class Digit : public Unit {
public:
    int digit;
    ll eval() {
        // cerr << "eval dig: " << digit << '\n';
        return digit * 1ll;
    }

    void print(int ft) {
        string p;
        for (int i = 0; i < ft; ++i) p += "\t";
        cout << p << digit <<'\n';
    }
};

class Print : public Unit {
public:
    Unit *input;
    ll eval() {
        return input->eval();
    }

    void print(int ft) {
        cout << "Print {\n";
        input->print(ft + 1);
        cout << "}\n";
    }
};

int n, m, px, py;
string a[100];

inline int valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int vis[100][100];
Unit* dfs(int x, int y) {
    vis[x][y] = 1;
    char c = a[x][y];
    if ('0' <= c && c <= '9') {
        Digit *res = new Digit;
        res->digit = c - '0';
        return res;
    } else if (c == '#') {
        Connector *res = new Connector;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!valid(nx, ny)) continue;
            if (vis[nx][ny]) continue;
            if (a[nx][ny] == '.') continue;
            res->input = dfs(nx, ny);
            return res;
        }
        assert(false);
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
        Operator *res = new Operator;
        res->type = c;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!valid(nx, ny)) continue;
            if (vis[nx][ny]) continue;
            if (a[nx][ny] == '.') continue;
            res->input.emplace_back(dfs(nx, ny));
            if (res->input.size() == 2) return res;
        }
        assert(false);
    } else if (c == 'P') {
        Print *res = new Print;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!valid(nx, ny)) continue;
            if (vis[nx][ny]) continue;
            if (a[nx][ny] == '.') continue;
            res->input = dfs(nx, ny);
            return res;
        }
        assert(false);
    }

    assert(false);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'P') {
                px = i;
                py = j;
            }
        }
    }

    Unit *rt = dfs(px, py);

    // rt->print(0);
    cout << rt->eval() << '\n';
    return 0;
}