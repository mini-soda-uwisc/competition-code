#include <bits/stdc++.h>

using namespace std;

unsigned long long lcm(unsigned long long a, unsigned long long b, unsigned long long gcdAns)
{
    return (a / gcdAns) * (b / gcdAns) * gcdAns;
}

int main()
{
    unsigned long long T = 0;
    scanf("%lld", &T);
    for (unsigned long long i = 0; i < T; i++)
    {
        unsigned long long x, y;
        scanf("%lld%lld", &x, &y);
        unsigned long long gcdAns = __gcd(x, y);
        unsigned long long lcmAns = lcm(x, y, gcdAns);
        printf("1 %lld\n", lcmAns / gcdAns);
    }

    return 0;
}
