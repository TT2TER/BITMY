#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        long long int n = 0;
        scanf("%lld", &n);
        long long int map[n + 2][3];
        long long int max = 0;
        for (long long int j = 1; j <= n; j++)
        {
            scanf("%lld", &map[j][0]);
            if (max < map[j][0])
            {
                max =  map[j][0];
            }
            map[j][1] = max;
        }
        max = 0;
        long long int ans = 0;
        for (long long int j = n; j >= 1; j--)
        {
            if (max < map[j][0])
            {
                max =  map[j][0];
            }
            map[j][2] = max;
            if(map[j][2]<=map[j][1])
            {
                ans+=map[j][2]-map[j][0];
            }
            else ans+=map[j][1]-map[j][0];
        }
        printf("%lld\n",ans);
    }

    return 0;
}