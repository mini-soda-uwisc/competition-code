#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

const int RANDTIME = 30;

int one_third, one_half;

int n;

struct Point {
    int x, y;
    bool operator == (const Point& a) const {
        return x == a.x && y == a.y;
    }
    bool operator < (const Point& a) const {
        if (x != a.x) return x < a.x;
        return y < a.y;
    }
    // void print() {
    //     cout << "(" << x << ", " << y << ")\n";
    // }
};


map<Point, int> on_line_map;


void update_on_line_map(vector<Point>& on_line, int val) {
    for (auto& p : on_line) {
        on_line_map[p] = val;
    }
}

bool check_validate(Point& a, Point& b, vector<Point>& p, int less, vector<Point>& on_line) {
    on_line.clear();
    on_line.emplace_back(a);
    on_line.emplace_back(b);
    for (int i = 0; i < p.size(); ++i) {
        Point &c = p[i];
        if (a == c || c == b) continue;
        if ((c.y - a.y) * (b.x - a.x) == (b.y - a.y) * (c.x - a.x)) {
            on_line.emplace_back(c);
        }
    }

    // cout << "find a line\n";
    // cout << "size: " << on_line.size() << ", less: " << less << "\n";
    // for (auto& c : on_line) {
    //     c.print();
    // }
    if (on_line.size() >= less) return true;
    return false;
}
void get_rest(vector<Point>& p, vector<Point>& rest) {
    rest.clear();
    for (auto& c : p) {
        if (on_line_map[c] == 0) rest.emplace_back(c);
    }
}

vector<Point> on_line1, on_line2, on_line3, rest1, rest2;

vector<Point> p;

int main() {
    srand((unsigned)time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        on_line_map[p[i]] = 0;
    }
    random_shuffle(p.begin(), p.end());

    one_third = ceil((double)n / 3.0);

    for (int i = 1; i <= RANDTIME; ++i) {
        int a = rand() % n, b = rand() % n;
        while (a == b) b = rand() % n;

        if (!check_validate(p[a], p[b], p, one_third, on_line1)) continue;

        update_on_line_map(on_line1, 1);
        get_rest(p, rest1);

        if (rest1.size() <= 4) {
            cout << "possible\n";
            return 0;
        }

        for (int j = 1; j <= RANDTIME; ++j) {
            int c = rand() % rest1.size(), d = rand() % rest1.size();
            while (c == d) d = rand() % rest1.size();

            one_half = ceil((double)rest1.size() / 2.0);

            if (!check_validate(rest1[c], rest1[d], rest1, one_half, on_line2)) continue;

            update_on_line_map(on_line2, 1);
            get_rest(rest1, rest2);

            if (rest2.size() <= 2) {
                cout << "possible\n";
                return 0;
            }

            if (check_validate(rest2[0], rest2[1], rest2, rest2.size(), on_line3)) {
                cout << "possible\n";
                return 0;
            }

            update_on_line_map(on_line2, 0);
        }

        update_on_line_map(on_line1, 0);
    }
    cout << "impossible\n";
    return 0;
}