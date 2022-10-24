#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cnt, flag;

void count(int Lefted, int deep,int step)
{
    if (step > deep || Lefted == 0)
        return;
    int NofThisBranch = pow(2, step) - 1;
    if (Lefted - NofThisBranch > 0)
    {
        cnt += pow(2, step - 1);
        if (!flag)
            step++;//向上一个结点移动、、分支不够时，下一句是去递归计算左右侧子串有几个。当分支够时计算的是侧边分支的数目
        count(Lefted - NofThisBranch, deep,step);
    }
    if (Lefted - NofThisBranch == 0)
    {
        cnt += pow(2, step - 1);
        return;
    }
    if (Lefted - NofThisBranch < 0)
    {
        step--;
        flag = 1;
        count(Lefted - 1, deep,step);
    }
    return;
}

int main()
{
    int t, n, m;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        if (n < m + 1)
        {
            printf("0\n");
            continue;
        }
        if (n == m + 1)
        {
            printf("1\n");
            continue;
        }
        cnt = 1;
        int  step = 1;
        flag = 0;//这一分支是否不够
        count(n - m - 1, m,step);
        printf("%d\n", cnt);
    }
}