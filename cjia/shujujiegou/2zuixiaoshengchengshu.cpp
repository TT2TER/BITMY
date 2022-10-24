#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
// #define MAX_E 1000
// #define MAX_V MAX_E * 3

typedef struct edge
{
    int begin;
    int end;
    int w;
} Edge;

bool cmp(Edge x, Edge y)
{
    return x.w < y.w;
}

int Find(int *p, int f)
{
    while (p[f] > 0)
    {
        f = p[f];
    }
    return f;
}
//
int N, M;
int MAX_E, MAX_V;

int main()
{
    scanf("%d %d", &N, &M);
    const int MAX_E = M, MAX_V = N;
    int add = 0;
    int cnt = 0;
    Edge edges[MAX_E];
    for (int i = 0; i < MAX_E; i++)
    {
        scanf("%d %d %d", &(edges[i].begin), &(edges[i].end), &(edges[i].w));
    }
    sort(edges, edges + MAX_E, cmp);
    int parent[MAX_V] ;
    for(int i=0;i<MAX_V;i++)
    {
        parent[i]=0;
    }
    for (int i = 0; i < MAX_E; i++)
    {
        int n, m;
        n = Find(parent, edges[i].begin-1);
        m = Find(parent, edges[i].end-1);
        if (n == m)
        {
            continue;
        }
        else
        {
            parent[n] = m;
            cnt++;
            add += edges[i].w;
        }
    }
    if (cnt != MAX_V - 1)
    {
        printf("-1\n");
    }
    else
        printf("%d\n", add);
    return 0;
}