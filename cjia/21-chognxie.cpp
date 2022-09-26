#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1000000, M = 10; // N为顶点数,M为边数
struct node
{
    int v;
    int w; //权重
    bool did;
    int step;
};
vector<node> g[N]; // n为顶点数
int s[4], e[4];

bool flag = false;

void bfs(vector<node> *g, int n, int i, bool visit[])
{
    queue<node> q;
    q.push({i,1,1,1});
    while (!q.empty())
    {
        for (int j = 0; j < g[q.front().v].size(); j++)
        {
            if (!g[q.front().v][j].did)
            {
                
                g[q.front().v][j].did = true;
                g[q.front().v][j].step = q.front().step+ 1;
                q.push(g[q.front().v][j]);
                if (g[q.front().v][j].v == e[3] && q.front().v == e[0])
                {
                    printf("%d\n", g[q.front().v][j].step);
                    flag = true;
                    return;
                }
            }
        }
        q.pop();
    }
}
int main()
{
    int m;
    scanf("%d", &m);
    for (int i = 0; i < N; i++)
    { // 邻接表的初始化操作,将起点为`i`的边链表全部清空
        g[i].clear();
    }

    bool visit[N + 10] = {false};

    for (int i = 0; i < m; i++) //读进来每个数字并存在邻接表中
    {
        int t1, t2, t3, t4;
        scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
        g[t1].push_back({t4, 1, 0, 1});
    }

    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &e[i]);
    }

    if (s[0] == e[0] && s[3] == e[3] && s[1] == e[1] && s[2] == e[2])
    {
        printf("1\n");
        flag = true;
    }
    else
    {
        bfs(g, m, s[3], visit);
    }
    if (!flag)
    {
        printf("-1\n");
    }
    return 0;
}