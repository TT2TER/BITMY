#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 10, M = 10; // N为顶点数,M为边数
struct node
{
    int v;
    int w; //权重
};
vector<node> g[N]; // n为顶点数

void dfs(vector<node> *g, int n, int i, bool visit[])
{
    visit[i] = true;
    //下面放功能代码

    //
    for (int j = 0; j < g[i].size(); j++)
    {//查询边如查询i开始的第j条边，就是g[i][j],指向的结点是g[i][j].vS
        if (!visit[g[i][j].v])
            dfs(g, n, g[i][j].v, visit);
    }
}

void bfs(vector<node> *g, int n, int i, bool visit[])
{
    queue<int> q;
    q.push(i);
    visit[i] = true;
    while (!q.empty())
    {
        for (int j = 0; j < g[q.front()].size(); j++)
        {
            if (!visit[g[q.front()][j].v])
            {
                q.push(g[q.front()][j].v);
                visit[g[q.front()][j].v] = true;
            }
        }
        q.pop();
    }
}
int main()
{
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    vector<int> g[n + 10];

    // 邻接表的初始化操作
// 将起点为`i`的边链表全部清空

    g[i].clear();
    bool visit[n + 10];
    for (int i = 1; i <= n; i++)
        visit[i] = false;
    while (m--)
    {                          // m为边数
        scanf("%d%d", &a, &b); // a--->b
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(g[i].begin(), g[i].end());
    }
    dfs(g, n, 1, visit);
    cout << endl;
    for (int i = 1; i <= n; i++)
        visit[i] = false;
    bfs(g, n, 1, visit);
    return 0;
}

int main()
{
    int x, y, w;
    // 有向图
    // g[x].push_back({y, w});

    // 无向图
    g[x].push_back({y, w});
    g[y].push_back({x, w});
}
