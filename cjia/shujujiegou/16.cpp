#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int illegalplay = 0, flag = 0, i = 0, p = 0, s = 0, m = 0, t1, m1 = 1, k1[30] = {0}, k[30] = {0}, t[30] = {0};
typedef enum
{
    ATOM,
    LIST
} Elemdata;
typedef struct GL
{
    Elemdata data;
    union
    {
        char atom;
        struct
        {
            struct GL *hp, *tp;
        } ptr;
    } asp;
} CTREE;
Elemdata judge(char *s)
{
    return strlen(s) == 1 ? (ATOM) : (LIST);
}
char *Gethead(char *s)
{
    int i, j, l;
    char *t;
    t = (char *)malloc(sizeof(char) * 80);
    l = strlen(s) - 1;
    for (i = 1, j = 0; i <= l; i++)
    {
        if (s[i] == '(')
            j++;
        if (s[i] == ')')
            j--;
        if (j == 0)
            break;
    }
    for (j = 0; j <= i - 1; j++)
    {
        t[j] = s[j + 1];
    }
    t[j] = '\0';
    return t;
}

char *Gettail(char *h)
{
    int i, j, l, w;
    char *m;
    m = (char *)malloc(sizeof(char) * 80);
    l = strlen(h) - 1;
    if (h[1] == ')')
        return ((strcpy(m, "()"), m));
    for (i = 1, j = 0; i <= l; i++)
    {
        if (h[i] == '(')
            j++;
        if (h[i] == ')')
            j--;
        if (j == 0)
            break;
    }
    if (h[i + 1] == ')' && (i + 1) == l)
    {
        return (strcpy(m, "()"), m);
    }
    else
    {
        m[0] = '(';
        for (w = 1, j = i + 2; j <= l; j++)
        {
            m[w++] = h[j];
        }
        m[w] = '\0';
        return (m);
    }
}

CTREE *Create(CTREE *L, char *S)
{
    if (!strcmp(S, "()"))
    {
        L = NULL;
    }
    else
    {
        L = (CTREE *)malloc(sizeof(CTREE));
        L->data = judge(S);
        if (L->data == ATOM)
        {
            L->asp.atom = S[0];
        }
        else
        {
            L->asp.ptr.hp = Create(L->asp.ptr.hp, Gethead(S));
            L->asp.ptr.tp = Create(L->asp.ptr.tp, Gettail(S));
        }
    }
    return L;
}

void print(CTREE *L)
{
    if (L)
    {
        if (L->data == ATOM)
        {
            printf("%c\n", L->asp.atom);
        }
        else
        {
            print(L->asp.ptr.hp);
            print(L->asp.ptr.tp);
        }
    }
    return;
}

void depth(CTREE *p, int t1)
{
    CTREE *q;
    for (q = p->asp.ptr.tp; q; q = q->asp.ptr.tp)
    {
        if (q->asp.ptr.hp->asp.ptr.hp->data == ATOM)
        {
            depth(q->asp.ptr.hp, t1 + 1);
            if (q->asp.ptr.hp->asp.ptr.tp == NULL)
            {
                k[s++] = t1 + 1;
            }
        }
    }
}

CTREE *playWhichOne(CTREE *p, char chequer)
{
    CTREE *q = p->asp.ptr.tp;
    for (; q; q = q->asp.ptr.tp)
    {
        if (q->asp.ptr.hp->asp.ptr.hp->data == ATOM && q->asp.ptr.hp->asp.ptr.hp->asp.atom == chequer)
        {
            return (q->asp.ptr.hp);
        }
    }
    printf("illegal move.\n");
    illegalplay = 1;
    return p;
}

CTREE *continuePlay(CTREE *p)
{
    int i1, i3 = 0, j1 = 0, w = 0, flag1, temp, flag = 1, kj, ko, max = 0;
    CTREE *q;
    while (flag)
    {
        for (q = p->asp.ptr.tp; q; q = q->asp.ptr.tp)
        {
            ko = 0;
            kj = 0;
            s = 0;
            for (i1 = 0; i1 < 30; i1++)
            {
                k[i1] = 0;
            }
            depth(q->asp.ptr.hp, 1);
            for (i1 = 0, temp = 0; k[i1]; i1++)
            {
                if (k[i1] % 2 == 0)
                {
                    ko++;
                }
                else
                {
                    kj++;
                }
                if (temp < k[i1])
                {
                    temp = k[i1];
                }
            }
            k1[i3++] = temp;
            if (temp == 0)
            {
                printf("computer: %c\n", q->asp.ptr.hp->asp.ptr.hp->asp.atom);
                printf("Sorry, you lost.\n");
                return NULL;
            }
            if (ko == 0 && kj > 0)
            {
                t[w++] = temp;
            }
            if (kj == 0 && ko > 0)
            {
                t[w++] = temp;
            }
            if (kj > 0 && ko > 0)
            {
                t[w++] = -1;
            }
        }
        for (i1 = 0, temp = 0, max = 0; t[i1]; i1++)
        {
            if (t[i1] != -1)
            {
                if (t[i1] % 2 != 0 && t[i1] > max)
                {
                    max = t[i1];
                    temp = i1;
                }
            }
        }
        if (temp != 0)
        {
            for (j1 = 0; j1 <= temp; j1++)
            {
                p = p->asp.ptr.tp;
            }
            printf("computer: %c\n", p->asp.ptr.hp->asp.ptr.hp->asp.atom);
            return p->asp.ptr.hp;
        }
        for (i1 = 0, temp = 0; t[i1]; i1++)
        {
            if (t[i1] == -1 && k1[i1] > temp)
            {
                temp = i1;
                max = t[i1];
            }
        }
        if (temp != 0)
        {
            for (j1 = 0; j1 <= temp; j1++)
            {
                p = p->asp.ptr.tp;
            }
            printf("computer: %c\n", p->asp.ptr.hp->asp.ptr.hp->asp.atom);
            return p->asp.ptr.hp;
        }
        printf("Congratulate, you win.\n");
    }
}

int main()
{
    int bob;
    char s[100], conti = 'y', chequer;
    CTREE *L = NULL, *p;
    gets(s);
    L = Create(L, s);
    print(L);
    while (conti == 'y')
    {
        p = L;
        printf("Who play first(0: computer; 1: player )?\n");
        scanf("%d", &bob);
        if (bob == 1)
        {
        B:
            printf("player:\n");
            getchar();
            scanf("%c", &chequer);
            p = playWhichOne(p, chequer);
            if (illegalplay == 1)
            {
                illegalplay = 0;
                goto B;
            }
            if (p->asp.ptr.tp == NULL)
            {
                printf("Congratulate, you win.\n");
                goto A;
            }
        }
        if (p != NULL)
        {
            p = continuePlay(p);
            if (p != NULL)
            {
                goto B;
            }
        }
    A:
        printf("Continue(y/n)?\n");
        for (bob = 0; bob < 30; bob++)
        {
            t[bob] = 0;
        }
        getchar();
        scanf("%c", &conti);
    }
    return 0;
}