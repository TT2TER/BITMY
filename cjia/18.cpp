#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n;
int boy[13][13], girl[13][13];
int Max = -1;
int sum = 0;
int Data[13][13];
int maxSum[13];
int book[13];
int cut(int d)
{
    int ret;
    int tmp = sum;
    for (int i = d; i < n; i++)
    {
        tmp += maxSum[i];
    }
    if (tmp < Max)
        ret = 1;
    else
        ret = 0;
    return ret;
}

void dfs(int t)
{
    if (t >= n) // t到达n之后，代表全部标记访问了,得到了当前最大值
    {
        Max = max(Max, sum);
        return;
    }

    //剪枝
    if (cut(t))
        return;

    for (int i = 0; i < n; i++)
    {
        if (!book[i])
        {
            book[i] = 1;
            sum += Data[t][i];
            dfs(t + 1);
            book[i] = 0; //回溯
            sum -= Data[t][i];
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Data[i][j] = boy[i][j] * girl[j][i];
            maxSum[i] = max(maxSum[i], Data[i][j]);
        }
    }
    dfs(0);
    printf("%d", Max);
    return 0;
}
