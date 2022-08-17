#include <stdio.h>
#include <math.h>
int main()
{
    int cnt = 0, n;
    while (cnt>=0)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        else
            cnt += pow(2, n - 1);
    }
    printf("%d\n", cnt);
    return 0;
}