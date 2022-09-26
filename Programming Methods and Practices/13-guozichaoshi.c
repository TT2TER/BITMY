#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int *)b - *(int *)a; //从大到小
}

int main()
{
    int n;
    scanf("%d", &n);
    long long int all[10010];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &all[i]);
    }
    long long int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        qsort(all, n - i, sizeof(all[0]), compare);
        all[n - 2 - i] = all[n - 2 - i] + all[n - 1 - i];
        sum += all[n - 2 - i];
    }
    printf("%lld\n", sum);
}