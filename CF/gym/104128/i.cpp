#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        int chMap[26] = {0};
        string str;
        getline(cin, str);
        // cout << str << endl;
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            // printf("str[%d]:%c (int)str[i] % (int)'a':%d\n", i, str[i], (int)str[i] % (int)'a');
            chMap[(int)str[i] % (int)'a']++;
        }
        int maxn = -1;
        for (int i = 0; i < 26; i++)
        {
            if (maxn < chMap[i])
            {
                maxn = chMap[i];
            }
        }
        // printf("maxn:%d len:%d\n", maxn, len);
        printf("%d\n", len - maxn);
    }
    return 0;
}