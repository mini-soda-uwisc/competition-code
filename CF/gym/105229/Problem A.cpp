#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int countGridsForPoint(int a, int b, int n, int m) {
    int left = a;
    int right = n - a;
    int up = m - b;
    int down = b;
    int maxSize = min(min(left, right), min(up, down));
    int count = 0;
    for (int size = 1; size <= maxSize; ++size) {
        count += min(min(left, right) - size + 1, 0) * 
                 min(min(up, down) - size + 1, 0);
    }
    return count;
}

vector<vector<int> > countGrids(int n, int m) {
    vector<vector<int> > result(n + 1, vector<int>(m + 1));
    for (int a = 0; a <= n; ++a) {
        for (int b = 0; b <= m; ++b) {
            result[a][b] = countGridsForPoint(a, b, n, m);
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > grids = countGrids(n, m);

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << grids[i][j];
            if (j < m) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
