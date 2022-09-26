
#include <stdio.h>
#include <stdlib.h>
int plus[200000][2], minus[200000][2];
int plus_count = 0, minus_count = 0;
int cmp1(const void *x, const void *y)
{
    return ((int *)x)[0] - ((int *)y)[0];
}
int cmp2(const void *x, const void *y)
{
    if ((((int *)x)[0] + ((int *)x)[1]) == (((int *)y)[0] + ((int *)y)[1]))
        return ((int *)y)[0] - ((int *)x)[0];
    else
        return (((int *)y)[0] + ((int *)y)[1]) - (((int *)x)[0] + ((int *)x)[1]);
}
int main(void)
{
    int n;
    long long attack = 0, money = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int tmp[2];
        scanf("%d %d", &tmp[0], &tmp[1]);
        if (tmp[1] < 0)
            minus[minus_count][0] = tmp[0], minus[minus_count++][1] = tmp[1];
        else
            plus[plus_count][0] = tmp[0], plus[plus_count++][1] = tmp[1];
    }
    qsort(plus, plus_count, sizeof(plus[0]), cmp1);
    qsort(minus, minus_count, sizeof(minus[0]), cmp2);
    for (int i = 0; i < plus_count; ++i)
        if (attack >= plus[i][0])
            attack += plus[i][1];
        else
            money += (plus[i][0] - attack), attack = plus[i][0] + plus[i][1];
    for (int i = 0; i < minus_count; ++i)
        if (attack >= minus[i][0])
            attack += minus[i][1];
        else
            money += (minus[i][0] - attack), attack = minus[i][0] + minus[i][1];
    printf("%lld\n", money);
    return 0;
}