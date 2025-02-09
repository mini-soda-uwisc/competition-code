#include <bits/stdc++.h>
using namespace std;

long long n;

struct Matrix {
  double a[2][2];
  void operator *= (Matrix& b) {
    double c[2][2];
    c[0][0] = a[0][0] * b.a[0][0] + a[0][1] * b.a[1][0];
    c[0][1] = a[0][0] * b.a[0][1] + a[0][1] * b.a[1][1];
    c[1][0] = a[1][0] * b.a[0][0] + a[1][1] * b.a[1][0];
    c[1][1] = a[1][0] * b.a[0][1] + a[1][1] * b.a[1][1];

    a[0][0] = c[0][0];
    a[0][1] = c[0][1];
    a[1][0] = c[1][0];
    a[1][1] = c[1][1];
  }
};

inline Matrix fpow(Matrix x, long long y) {
  Matrix res;
  res.a[0][0] = res.a[1][1] = 1;
  res.a[1][0] = res.a[0][1] = 0;

  while (y) {
    if (y & 1) res *= x;
    x *= x;
    y >>= 1;
  }

  return res;
}

int main() {
  cin >> n;
  if (n == 1) {
    printf("100.0 0.0\n");
    return 0;
  }
  if (n == 2) {
    printf("0.0 100.0\n");
    return 0;
  }

  Matrix A;
  A.a[0][0] = 0;
  A.a[0][1] = 1;
  A.a[1][0] = A.a[1][1] = 0.5;

  A = fpow(A, n - 2);

  // for (int i = 0; i < 2; ++i) {
  //   for (int j = 0; j < 2; ++j) {
  //     printf("%10lf", A.a[i][j]);
  //   }
  //   printf("\n");
  // }

  double result = A.a[1][0];
  result *= 100;
  printf("%.10lf %.10lf\n", result, 100 - result);
  return 0;
}