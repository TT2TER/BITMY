#include <stdio.h>
#include <string.h>
#define sys 2
int na[32];
int ans[1000];
void change(char s[], int len)
{
    for (int k = 0; k < len; k++)
    {
        na[k] = s[k] - '0';
    }
}
int division(int *p, int len)
{
    int last = 0;
    int zero = 0;
    for (int i = 0; i < len; i++)
    {
        if (na[i] != 0)
        {
            zero = 1;
        }
        if (zero = 1)
        {
            na[i] = na[i] + last * 10;
            last = na[i] % sys;
            na[i] = na[i] / sys;
        }
    }
    return last;
}
int judge(int *p, int len) //适用于2进制
{
    int ret = 0;
    for (int k = 0; k < len - 1; k++)
    {
        if (p[k] == 0)
            ;
        else
        {
            ret = 1;
            break;
        }
    }
    return ret;
}
int main()
{
    char a[32];
    scanf("%s", a);
    int len = strlen(a);
    change(a, len);
    int k = 1;
    while (na[len - 1] >= sys || judge(na, len))
    {
        ans[k] = division(na, len);
        k++;
    }
    ans[k] = na[len - 1];
    int cnt=0;
    for (int i = 1; i <= 8 - k % 8; i++)
    {
        if(k%8)
        {
        ans[k + i] = 0;
        cnt=8;
        }
    }
    int K = k + cnt - k % 8;

    for (int i = K / 8; i >= 1; i--)
    {
        for (int n = 8; n >= 1; n--)
        {
            printf("%d", ans[K--]);
        }
        if (i == 1)
            printf("B\n");
        else
            printf("-");
    }
    return 0;
}