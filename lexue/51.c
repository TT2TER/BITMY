#include <stdio.h>
#include <string.h>
char a[510], b[510], c[510];
int sum(char *a, char *b, char *c, int la, int lb)
{
    int now = 0, up = 0;
    while (now < la || now < lb)
    {
        c[now] = (a[now] - '0' + b[now] - '0' + up) + '0';
        up = (c[now] - '0') / 10;
        c[now] = ((c[now] - '0') % 10) + '0';
        now++;
    }
    if (up == 0)
        now--;
    else
        c[now] = up + '0';
    return now;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int d = m - n;
    a[0] = '0';
    b[0] = '1';
    int la = 1, lb = 1;
    char *pa = a;
    char *pb = b;
    char *pc = c;
    int lc;
    for (int i = 0; i < d; i++)
    {
        if (i == 0)
        {
            lc = sum(pa, pb, pc, la, lb); //z=len-1;}
        }
        else
        {
            char *temp;
            temp=pa;
            pa = pb;
            pb = pc;
            pc = temp;
            la=lb;
            lb=lc+1;
            for (int j = 0; j <= lc; j++)
            {
                pc[j] = '\0';
            }
            lc = sum(pa, pb, pc, la, lb); //z=len-1;}
        }
    }
    for (; lc >= 0; lc--)
    {
        printf("%c", pc[lc]);
    }
    return 0;
}