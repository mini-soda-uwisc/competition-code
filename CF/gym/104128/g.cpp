#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    scanf("%d", &n);
    // getchar();
    for (int i = 0; i < n; i++)
    {
        int round = 0;
        scanf("%d", &round);
        // getchar();
        int sum0 = 0;
        int attact = 1;
        int beasts = 1;
        int fanhui = 0;
        printf("round:%d\n", round);
        for (int j = 0; j < round; j++)
        {
            int operation = 0;
            scanf("%d", &operation);
            // getchar();
            printf("operation:%d\n", operation);
            if (operation == 1)
            {
                attact++;
                beasts++;
            }
            else if (operation == -1)
            {
                if (beasts <= 1)
                {
                    if (fanhui <= 0)
                    {
                        printf("-1\n");
                        break;
                    }
                    else
                    {
                        // ����
                        attact--;
                        beasts++;
                        fanhui--;

                        // ���� Card
                        attact++;
                        beasts++;
                    }
                }
                attact++;
                beasts--;
            }
            else
            {
                if (beasts > 1) // ������й��޾� Mysterious Stone
                {
                    attact++;
                    beasts--;
                    fanhui++;
                }
                else // û�о� Card
                {
                    attact++;
                    beasts++;
                }
            }
        }
        printf("%d %d\n", attact, beasts);
    }
    return 0;
}