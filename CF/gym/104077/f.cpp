#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    long long int ans = 0;
    int typeSingle = 0, typeDouble = 0;
    cin >> n >> typeSingle >> typeDouble;
    // 如果开两间双人间比开两间单人间便宜，那么就开两间双人间
    if (typeDouble * 2 < typeSingle * 2) {
        typeSingle = typeDouble;
    }

    for (int i = 0; i < n; ++i) {
        string s;
        int sum = 0;
        cin >> s;

        if (typeDouble < typeSingle * 2
            && (s[0] == s[1] || s[1] == s[2] || s[0] == s[2])) {
            sum = typeSingle + typeDouble;
        } else {
            sum = typeSingle * 3;
        }

        ans += sum;
    }
    cout << ans << endl;
    return 0;
}