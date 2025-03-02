#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Fraction {
    int a, b; // a / b
    Fraction() {
        a = 0;
        b = 1;
    }

    Fraction(int a, int b) {
        this->a = a;
        this->b = b;
    }

    void simplify() {
        if (a > 0 && b < 0) {
            a *= -1;
            b *= -1;
        }
        int d = __gcd(a, b);
        a /= d;
        b /= d;
    }

    Fraction reverse() const {
        return Fraction(b, a);
    }

    Fraction operator +(const Fraction& other) const {
        Fraction res = Fraction(a * other.b + b * other.a, b * other.b);
        res.simplify();
        return res;
    }

    void operator +=(const Fraction& other) {
        *this = *this + other;
    }

    Fraction operator -(const Fraction& other) const {
        Fraction res = Fraction(a * other.b - b * other.a, b * other.b);
        res.simplify();
        return res;
    }

    void operator -=(const Fraction& other) {
        *this = *this - other;
    }

    Fraction operator *(const Fraction& other) const {
        Fraction res = Fraction(a * other.a, b * other.b);
        res.simplify();
        return res;
    }

    void operator *=(const Fraction& other) {
        *this = *this * other;
    }

    Fraction operator /(const Fraction& other) const {
        Fraction res = *this * other.reverse();
        res.simplify();
        return res;
    }

    void operator /=(const Fraction& other) {
        *this = *this * other.reverse();
    }

    bool operator <(const Fraction& other) const {
        return a * other.b < b * other.a;
    }

    bool operator ==(const Fraction& other) const {
        return a == other.a && b == other.b;
    }
};

int n;
Fraction h[100010];

Fraction get_x(Fraction x1, Fraction y1, Fraction x2, Fraction y2, Fraction y) {
    return ((y - y1) / (y2 - y1)) * (x2 - x1) + x1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i].a;
    }

    Fraction ans = Fraction(0, 1);

    stack<pair<int, int>> s;
    for (int i = 1; i <= n; ++i) {
        while (!s.empty() && s.top().first < h[i].a) {
            auto p = s.top();
            s.pop();

            int idx = p.second;
            if (abs(idx - i) > 1) {
                int idy = idx + 1;
                Fraction res = get_x(Fraction(i, 1), h[i], Fraction(i - 1, 1), h[i - 1], h[idx]);
                res = res - Fraction(idx, 1);
                ans = max(ans, res);
            }
        }
        s.push({h[i].a, i});
    }

    while (!s.empty()) {
        s.pop();
    }
    for (int i = n; i >= 1; --i) {
        while (!s.empty() && s.top().first < h[i].a) {
            auto p = s.top();
            s.pop();

            int idx = p.second;
            if (abs(idx - i) > 1) {
                Fraction res = get_x(Fraction(i +1, 1), h[i + 1], Fraction(i, 1), h[i], h[idx]);
                res = Fraction(idx, 1) - res;
                ans = max(ans, res);
            }
        }
        s.push({h[i].a, i});
    }

    if (ans.b == 1) {
        cout << ans.a << '\n';
    }
    else {
        cout << ans.a << '/' << ans.b << '\n';
    }
    return 0;
}
