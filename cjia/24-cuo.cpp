#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxE = 300050, maxN = 300050;
int head[maxN], cnt = 0;

struct node
{
    int to, nxt, w;
};
int i;
int n, m;
int in[maxN] = {0};
node e[maxE]; //边集数组，边数一般要设置比maxn*maxn大的数，如果题目有要求除外

void add(int from, int to, int w)
{ // w为边权重，从from到to的一条有向边
    e[++cnt].nxt = head[from];
    head[from] = cnt;
    e[cnt].to = to;
    e[cnt].w = w;
    in[to]++;
}
bool check(int began, int tail)
{
    bool ret = false;
    queue<int> q;
    while (!q.empty())
        q.pop();
    q.push(head[began]);
    while (!q.empty() && !ret)
    {
        for (int j = q.front(); j && !ret; j = e[j].nxt)
        {
            if (e[j].to == tail)
            {
                ret = true;
                printf("%d\n", i + 1);
                exit(0);
            }
            q.push(head[e[j].to]);
        }
        q.pop();
    }

    return ret;
}
int main()
{

    scanf("%d %d", &n, &m);
    int flag = 1;
    bool has = 0;
    bool ans = 0;
    for (i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d", &u, &v); // printf("%d %d",u,v);
        add(u, v, 1);
        if (flag)
        {
            has = check(v, u);
        }
        if (has)
        {

            flag = 0;
            ans = 1;
        }
    }
    if (!flag)
    {
        printf("-1\n");
    }
    return 0;
}