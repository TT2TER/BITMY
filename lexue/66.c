#include <stdio.h>
#include <string.h>
typedef struct Bank
{
    char name[15];
    int give;
    int num;
    int left;
    int got;
    // int ans;
} bank;
bank *search(char *c, bank *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(c, arr[i].name) == 0)
            return &arr[i];
    }
    return NULL;
}
int main()
{
    int N;
    scanf("%d", &N);
    bank arr[11];
    getchar();
    for (int i = 0; i < N; i++)
    {
        gets(arr[i].name);
        arr[i].give = 0;
        arr[i].got = 0;
        arr[i].left = 0;
    }
    for (int i = 0; i < N; i++)
    {
        char name[15];
        gets(name);
        bank *p = search(name, arr, N);
        scanf("%d %d", &p->give, &p->num);
        getchar();
        if (p->give == 0)
        {
            for (int k = 0; k < p->num; k++)
            {
                gets(name);
            }
            continue;
        }
        int every = p->give / p->num;
        p->left = p->give - p->num * every;
        for (int k = 0; k < p->num; k++)
        {
            gets(name);
            bank *q = search(name, arr, N);
            q->got += every;
        }
    }
    for (int i = 0; i < N; i++)
    {
        printf("%s %d\n", arr[i].name, arr[i].got + arr[i].left - arr[i].give);
    }
    return 0;
}
