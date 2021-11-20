#include <stdio.h>
int main()
{
    int map[110][110] = {0};
    int i, j;
    int n;
    scanf("%d", &n);
    for (i = 0; i <= n + 1; i++)
    {
        for (j = 0; j <= n + 1; j++)
        {
            if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
                map[i][j] = -1;
            else
                map[i][j] = 0;
        }
    }
    int flag = 0;
    for (int k = 1, i = 1, j = 1; k <= n * n; k++)
    {
        if (i == 1 && j == 1 && flag == 0)
        {
            map[i][j] = k;
            j++;
            continue;
        }
        if (i == 1 && map[i + 1][j - 1] == 0 && flag == 0)
        {
            flag = 1;
        }
        if (j == 1 && map[i - 1][j + 1] == 0 && flag == 0)
        {
            flag = 2;
        }
        if (flag==-1)
        {
            if(j==n)
            flag=1;
            else if(i==n)
            flag=2;
        }
        if (flag == 1)
        {
            if (map[i + 1][j - 1] != -1)
            {
                map[i][j] = k;
                i = i + 1;
                j = j - 1;
                continue;
            }
            else
            {
                map[i][j] = k;
                if (map[i + 1][j] != -1)
                {
                    i = i + 1;
                    flag = 0;
                    continue;
                }
                else
                {
                    j = j + 1;
                    flag = -1;
                    continue;
                }
            }
        }
        if (flag == 2)
        {
            if (map[i - 1][j + 1] != -1)
            {
                map[i][j] = k;
                i = i - 1;
                j = j + 1;
                continue;
            }
            else
            {
                map[i][j] = k;
                if (map[i][j + 1] != -1)
                {
                    j = j + 1;
                    flag = 0;
                    continue;
                }
                else
                {
                    i = i + 1;
                    flag = -1;
                    continue;
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%2d",map[i][j]);
            if(j!=n)
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}