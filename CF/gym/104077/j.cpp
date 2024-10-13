#include<bits/stdc++.h>

using namespace std;

long long int a[100010] = {0};

int main() {
    long long int n = 0;
    scanf("%lld", &n);
    for (long long int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    long long int ans = max(a[n - 1] + a[n - 2], a[n - 1]);
    printf("%lld\n", ans >= 0 ? ans : 0);
}