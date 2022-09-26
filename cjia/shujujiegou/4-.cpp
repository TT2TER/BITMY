#include <stdio.h>
#include <stdlib.h>

typedef struct Hole
{
    long long n, w, h;
    struct Hole *pre, *nxt;
} holes;

long long time[100005];

int main()
{
    Hole *left = (Hole *)malloc(sizeof(Hole));
    Hole *right = (Hole *)malloc(sizeof(Hole));

    left->n = 0;
    left->h = 1000050;
    left->w = 0;
    left->pre = NULL;
    left->nxt = NULL;

    Hole *pre = left;
    Hole *now1 = left;

    long long n;
    scanf("%lld", &n);

    for (long long i = 1; i <= n; i++)
    {
        Hole *cur = (Hole *)malloc(sizeof(Hole));
        long long w, h;
        scanf("%lld %lld", &w, &h);
        cur->nxt = NULL;
        cur->pre = pre;
        cur->w = w;
        cur->h = h;
        cur->n = i;
        pre->nxt = cur;
        pre = cur;
        if (now1->h > h)
        {
            now1 = cur;
        }
    }

    right->n = n + 1;
    right->h = 1000050;
    right->w = 0;
    right->pre = pre;
    pre->nxt = right;
    right->nxt = NULL;

    Hole *now2 = now1;
    long long times = 0;
    int end = 0;

    long long N=n;

    while (n--)
    {

        

        //找相对矮的
        if (now1->pre->h > now1->nxt->h)
            now2 = now1->nxt;
        else if (now1->pre->h < now1->nxt->h)
            now2 = now1->pre;

        time[now1->n] = times + now1->w;
        //times += now1->w;

        long long dh = now2->h - now1->h ;
        times += now1->w * dh;

        now2->w += now1->w;

        // del now1

        now1->pre->nxt = now1->nxt;
        now1->nxt->pre = now1->pre;

        free(now1);

        //if (end)
            //break;

        now1 = now2;

        if (now1->pre->h < now1->h && now1->pre->h < now1->nxt->h) // pre最di
        {
            now1 = now1->pre;
        }

        while (now1->pre->h < now1->h || now1->h > now1->nxt->h)
        {
            if(now1->pre->h > now1->nxt->h)
            {
                now1=now1->nxt;
            }
            else
            now1=now1->pre;
        }
    }

    for (long long i = 1; i <= N; i++)
    {
        printf("%lld\n", time[i]);
    }

    return 0;
}