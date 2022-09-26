#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

const int maxE = 200050, maxN = 200050;

int head[maxN] = {0}, cnt = 0;
struct edge
{
    int to, nxt, w;
};

edge e[maxE * 2];
long long dis[maxN];
long long odd;
long long sum;
long long n;

void add(int from, int to, int w)
{
    e[++cnt].nxt = head[from];
    head[from] = cnt;
    e[cnt].to = to;
    e[cnt].w = w;
}

void dfs(int cur, int father, int deep)
{
    for (int j = head[cur]; j; j = e[j].nxt)
    {
        if (e[j].to == father)
            continue;
        if (deep % 2 == 1)
            odd++;
        dfs(e[j].to, cur, deep + 1);
    }
    dis[father] += dis[cur];
    sum += dis[cur] * (n - dis[cur]);
    return;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < maxN; i++)
        dis[i] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v, 1);
        add(v, u, 1);
    }
    dfs(1, 0, 1);
    // for (int i = 0; i <= 12; i++)
    // {//检查dis是不是对的。
    //     printf("%d\n", dis[i]);
    // }

    long long step2 = odd * (n - odd);
    long long ans = (sum + step2) / 2;
    printf("%lld\n", ans);
}