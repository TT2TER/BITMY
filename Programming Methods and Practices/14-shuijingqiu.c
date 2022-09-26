#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct cube
{
    int a;
    int b;
    int c;
    int n, m;
};

struct cube all[100100];

int comparec(const void *a, const void *b)
{
    return (*(struct cube *)b).c - (*(struct cube *)a).c;
}
int compareb(const void *a, const void *b)
{
    return (*(struct cube *)b).b - (*(struct cube *)a).b;
}
int comparea(const void *a, const void *b)
{
    return (*(struct cube *)b).a - (*(struct cube *)a).a;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int o, p, q;
        scanf("%d %d %d", &o, &p, &q);
        if (o < p)
        {
            int t = o;
            o = p;
            p = t;
        }
        if (p < q)
        {
            int t = p;
            p = q;
            q = t;
        }
        if (o < p)
        {
            int t = o;
            o = p;
            p = t;
        }
        all[i].a = o;
        all[i].b = p;
        all[i].c = q;
        all[i].n = i + 1;
    }

    qsort(all, n, sizeof(all[0]), comparec);
    struct cube best = all[0];

    qsort(all, n, sizeof(all[0]), compareb);
    qsort(all, n, sizeof(all[0]), comparea);
    int j = 0;
    int flag = 0;
    for (j = 0; j < n - 1; j++)
    {
        if (all[j].a == all[j + 1].a && all[j].b == all[j + 1].b)
        {
            int q = all[j].c + all[j + 1].c;
            int o = all[j].a;
            int p = all[j].b;
            if (o < p)
            {
                int t = o;
                o = p;
                p = t;
            }
            if (p < q)
            {
                int t = p;
                p = q;
                q = t;
            }
            if (o > p)
        {
            int t = o;
            o = p;
            p = t;
        }
            if (q > best.c)
            {
                flag = 1;
                best.a = o;
                best.b = p;
                best.c = q;
                best.n = all[j].n;
                best.m = all[j + 1].n;
            }
        }
    }
    if (flag)
    {
        printf("2\n");
        printf("%d %d\n", best.n, best.m);
    }
    else
    {
        printf("1\n%d\n", best.n);
    }
    return 0;
}