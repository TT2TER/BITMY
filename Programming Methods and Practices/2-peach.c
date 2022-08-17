#include <stdio.h>
int main()
{
    int n = 0, v = 0;
    int day[3010] = {0};
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; i++)
    {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        day[a] += b;
    }
    int sum = 0;
    for (int i = 1; i <= 3001; i++)
    {
        int today = 0;
        for (int j = v; j >= 1; j--)
        {
            if (day[i-1] > 0)
            {
                today += 1;
                day[i-1] -= 1;
                continue;
            }
            else
            {
                if(day[i]>0)
                {
                    today += 1;
                    day[i] -= 1;
                    continue;
                }
                else
                continue;
            }
        }
        sum+=today;
    }
    printf("%d\n",sum);
    return 0;
}