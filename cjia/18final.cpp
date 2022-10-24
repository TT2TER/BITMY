#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define m 13
int n;
int boy[m][m], girl[m][m];
int Data[m][m], msum[m], selected[m];
int Max = -1;
int sum = 0;
int cut(int d)
{
    int ret;
    int tmp = sum;
    for (int i = d; i < n; i++)
    {
        tmp += msum[i];
    }
    if (tmp < Max)
        ret = 1;
    else
        ret = 0;
    return ret;
}
void dfs(int d)
{
    if (d >= n)
    {
        Max = max(Max, sum);
        return;
    }

    if (cut(d))
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!selected[i])
        {
            selected[i]++;
            sum += Data[i][d];
            dfs(d+1);
            selected[i]--;
            sum -= Data[i][d];
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &boy[i][j]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &girl[i][j]);
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            Data[i][j] = girl[j][i] * boy[i][j];
            msum[j] = max(msum[j], Data[i][j]);
        }
    }

    dfs(0);
    printf("%d\n", Max);
    return 0;
}