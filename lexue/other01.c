#include <stdio.h>

int countsub(char *str, char *ss);
//TODO:caution！ss or subs!!!
int main()
{
    char s1[1000] = {0}, s2[100] = {0};
    gets(s1);
    gets(s2);
    printf("%d\n", countsub(s1, s2));
    return 0;
}
int countsub(char *str, char *ss)
{
    int i, j;
    for (i = 0; str[i] != '\0'; i++)
        ;
    for (j = 0; ss[j] != '\0'; j++)
        ;
    int m = 0;
    int sum = 0, cnt = 0;
    int ret = 0;
    while (m <= i - j)
    {
        for (int k = 0; k < j; k++)
        {
            if (str[k + m] == ss[k])
            {
                cnt++;
            }
        }
        if (cnt == j)
        {
            sum++;
            m += j;
        }
        else
            m++;
        cnt = 0;
    }
    return sum;
}