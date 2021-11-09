#include <stdio.h>
#include <string.h>
int main()
{
    freopen("1.out","w",stdout);
    int n;
    scanf("%d\n", &n);
    int z;
    for (z = 0; z < n; z++)
    {
        int a[510], b[510], c[510];
        int len, sym;
        int i;
        char all[1100];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        gets(all);
        len = strlen(all);
        for (i = 0; i < len; i++)
            if (all[i] == '-' || all[i] == '+')
                sym = i;
        for (i = 0; i < sym; i++)
        {
            a[sym - i] = all[i] - '0'; //a从1开始
        }
        for (i = 0; i < len - 1 - sym; i++)
        {
            b[len - 1 - sym - i] = all[sym + 1 + i] - '0';
        }
        int la, lb;
        la = sym;
        lb = len - 1 - sym;
        if (all[sym] == '+')
        {
            int now = 1, up = 0;
            while (now <= la || now <= lb)
            {
                c[now] = a[now] + b[now] + up; //两数相加
                up = c[now] / 10;
                c[now] %= 10;
                now++;
            }
            if (up == 0)
                now--;
            else
                c[now] = up;
            for (i = now; i >= 1; i--)
            {
                printf("%d", c[i]);
            }
        }
        if (all[sym] == '-')
        {
            int now = 1;
            if (la < lb || (la == lb && a[1] < b[1]))
            {
                printf("-");
                while (now <= lb || now <= la)
                {
                    if (b[now] < a[now])
                    {
                        b[now] += 10; //不够减，那么向高位借1当10
                        b[now + 1]--;
                    }
                    c[now] = b[now] - a[now]; //对应位相减
                    now++;
                }
                while ((c[now] == 0) && (now > 1))
                    now--;
                for (i = now; i >= 1; i--)
                {
                    printf("%d", c[i]);
                }
            }
            else 
            {
                while (now <= lb || now <= la)
                {
                    if (a[now] < b[now])
                    {
                        a[now] += 10; //不够减，那么向高位借1当10
                        a[now + 1]--;
                    }
                    c[now] = a[now] - b[now]; //对应位相减
                    now++;
                }
                while ((c[now] == 0) && (now > 1))
                    now--;
                for (i = now; i >= 1; i--)
                {
                    printf("%d", c[i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}