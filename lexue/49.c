#include <stdio.h>
// char cmap[110][110];
// int map[110][110];
int main()
{
    int flag = 0;
    while (1)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        if(m==0&&n==0)return 0;
        else flag++;
        getchar();
        char cmap[110][110]={0};
        int map[110][110]={0};
        int i, j;
        for (i = 0; i <= n + 1; i++)
        {
            for (j = 0; j <= m + 1; j++)
            {
                if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
                    cmap[i][j] = '#';
            }
        }
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                scanf("%c", &cmap[i][j]);
            }
            if (i != m)
                getchar(); //消除行尾回车！！！
        }
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                if (cmap[i][j] == '*')
                {
                    map[i + 1][j]++;
                    map[i - 1][j]++;
                    map[i][j + 1]++;
                    map[i][j - 1]++;
                    map[i + 1][j - 1]++;
                    map[i - 1][j - 1]++;
                    map[i - 1][j + 1]++;
                    map[i + 1][j + 1]++;
                }
            }
        }
        if(flag!=1)printf("\n");
        printf("Field #%d:\n",flag);
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                if (cmap[i][j] == '*')
                {
                    printf("*");
                }
                else
                    printf("%d", map[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}