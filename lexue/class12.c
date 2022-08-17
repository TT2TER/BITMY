#include <stdio.h>
#include <string.h>
char a[100];
struct Save
{
    char c[100];
    int num;
    int len;
} ans;
char temp[100];

int search(char *map, char *comp, int d)
{
    int len1 = strlen(map);
    int times = 0;
    for (int j = 0; j <= len1 - d; j++)
    {
        int same = 0;
        for (int i = 0; i < d; i++)
        {
            if (comp[i] == map[j + i])
            {
                same++;
            }
        }

        if (same == d)
        {
            j += d - 1;
            times++;
        }
    }
    return times;
}
int main()
{
    gets(a);
    int len = strlen(a);

    for (int left = 0; left < len - 1; left++)
    {
        for (int d = 2; d <= len - left; d++)
        {
            char temp[100] = {'\0'};
            int i;
            for (i = 0; i < d; i++)
            {
                temp[i] = a[left + i];
            }

            int times = search(&a[left + i], temp, d);

            if (times == ans.num)
            {
                if (d > ans.len)
                {
                    strcpy(ans.c, temp);
                    ans.len = d;
                    ans.num = times;
                }
            }
            else if (times > ans.num)
            {
                strcpy(ans.c, temp);
                ans.len = d;
                ans.num = times;
            }
        }
    }

    if(ans.num==0)
    {
        printf("no result!\n");
    }
    else{
        printf("%s %d times\n",ans.c,ans.num+1);
    }
    return 0;
}