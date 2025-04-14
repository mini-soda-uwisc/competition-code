#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    // n：约束个数（q的长度）， m：决策变量个数（p的长度）

    // 读入右端项 q（长度为 n）
    vector<double> q(n);
    for (int i = 0; i < n; i++){
        cin >> q[i];
        q[i] *= 100;
    }

    // 读入矩阵 A 和目标函数系数 p
    // 注意：输入共 m 行，每行先输入 n 个数字表示 A 的一行（表示决策变量 x_j 在各约束下的系数），
    // 接着一个数字 p[j]（目标函数中 x_j 的系数）。
    vector<vector<double>> A(m, vector<double>(n, 0));
    vector<double> p(m);
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            cin >> A[j][i];
        }
        cin >> p[j];
    }

    // 构造单纯形表
    // 共 (n + 1) 行：前 n 行对应约束，第 n 行为目标函数
    // 共 (m + n + 1) 列：前 m 列代表决策变量，接下来 n 列代表松弛变量，最后一列为右端项 (RHS)
    int rows = n + 1;
    int cols = m + n + 1;
    vector<vector<double>> tableau(rows, vector<double>(cols, 0.0));

    // 填充约束行（行 0 到 n-1）
    // 对于每个约束 i (0-based)：
    // - 决策变量 x[j] 的系数：A[j][i] ， j = 0...m-1
    // - 松弛变量 s[i] 的系数：1 （对应列 m + i）
    // - 右端项：q[i]
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            tableau[i][j] = A[j][i]; // 注意 A 存的是 m 行 n 列（每行对应一个决策变量在所有约束的系数）
        }
        tableau[i][m + i] = 1.0; // 松弛变量形成单位阵
        tableau[i][cols - 1] = q[i]; // 右端项
    }

    // 填充目标函数行（最后一行，索引 n）
    // 对于决策变量 x[j]：放入 -p[j]（单纯形表中通常将目标函数写为：最大化 f ==> 最小化 -f）
    for (int j = 0; j < m; j++){
        tableau[n][j] = -p[j];
    }
    // 松弛变量系数均为 0，右端项为 0

    // 开始单纯形迭代
    while (true) {
        // 找出目标行中仍为负（表示可改进）的列，选取第一个这样的列为入基变量
        int pivotCol = -1;
        for (int j = 0; j < cols - 1; j++){
            if (tableau[n][j] < -EPS) {
                pivotCol = j;
                break;
            }
        }
        // 如果目标行系数都不为负，则已达到最优
        if (pivotCol == -1) break;

        // 比例检验：在所有具有正 pivotCol 系数的约束行中，选取 RHS/系数最小的行为出基行
        int pivotRow = -1;
        double minRatio = numeric_limits<double>::infinity();
        for (int i = 0; i < n; i++){
            if (tableau[i][pivotCol] > EPS) {
                double ratio = tableau[i][cols - 1] / tableau[i][pivotCol];
                if (ratio < minRatio) {
                    minRatio = ratio;
                    pivotRow = i;
                }
            }
        }
        // 如果没有找到 pivotRow，则目标函数无界
        if (pivotRow == -1){
            cout << "Unbounded" << "\n";
            return 0;
        }

        // 执行 pivot 操作：先将 pivot 行标准化，再消去其他各行中 pivot 列元素
        double pivotVal = tableau[pivotRow][pivotCol];
        // 标准化 pivot 行
        for (int j = 0; j < cols; j++){
            tableau[pivotRow][j] /= pivotVal;
        }
        // 消去其他行 pivot 列上的元素
        for (int i = 0; i < rows; i++){
            if (i == pivotRow) continue;
            double factor = tableau[i][pivotCol];
            for (int j = 0; j < cols; j++){
                tableau[i][j] -= factor * tableau[pivotRow][j];
            }
        }
    }

    // 最优解的目标函数值存储在目标行（最后一行）的最右侧元素
    double optValue = tableau[n][cols - 1];
    printf("%.2lf\n", optValue);

    return 0;
}
