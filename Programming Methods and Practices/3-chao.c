#include <stdio.h>
#define MAX 16
int m, n;
int amap[MAX][MAX], copyMap[MAX][MAX];
// amap用于保存原灯阵和一次遍历后的灯阵， copyMap用于保存遍历后的灯阵并进行操作，两者要隔离防止互相干扰
int ans = 256; //利用全局变量来更新最终答案，初始化为256是因为理论最大值为256

//定义一个操作，改变某处灯的情况
void change(int amap[MAX][MAX], int row, int column)
{
    if (amap[row][column] == 1)
        amap[row][column] = 0;
    else if (amap[row][column] == 0)
        amap[row][column] = 1;
    return;
}
//定义一个操作，模拟按下某个灯的情况
void push(int amap[MAX][MAX], int row, int column)
{
    change(amap, row, column);
    if (row - 1 >= 0)
        change(amap, row - 1, column);
    if (row + 1 < n)
        change(amap, row + 1, column);
    if (column - 1 >= 0)
        change(amap, row, column - 1);
    if (column + 1 < m)
        change(amap, row, column + 1);
    return;
}
//定义一个操作，用于复制整个灯阵，可以防止后续的操作破坏原有的结构
void getCopy()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            copyMap[i][j] = amap[i][j];
        }
    }
    return;
}
//定义一个函数，用于获取总共的步骤
int getStep()
{
    getCopy();
    int step = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (copyMap[i][j] == 1)
            {
                push(copyMap, i + 1, j);
                step++;
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (copyMap[n - 1][j] == 1)
            return -1;
    }
    return step;
}
// DFS主体
void dfs(int index, int count)
{
    if (index == m)
    {
        int lef = getStep();
        if (lef == -1)
            return;
        else if (lef + count < ans)
            ans = lef + count;
        return;
    }

    push(amap, 0, index);
    dfs(index + 1, count + 1);

    push(amap, 0, index); //此处很重要，DFS在“回头”的时候一定要“恢复”原状态
    dfs(index + 1, count);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &amap[i][j]);
        }
    }
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}