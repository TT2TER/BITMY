#include <stdio.h>
#include <ctype.h>
char in[1000];
int get = 0;
void puttab(int i);
int main()
{
    //freopen("1.out","w",stdout);
    int i = 0, flag1 = 0, flag = 0, len;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            continue;
        in[i] = c;
        i++;
    }
    len = i;
    for (i = 0; i < len; i++)
    {
        printf("%c", in[i]);
        if (in[i] == '#')
            flag1 = 1;
        if (in[i] == '>' && flag1 == 1)
        {
            printf("\n");
            flag1 = 0;
        }
        if (in[i] == 'f' && in[i + 1] == 'o' && in[i + 2] == 'r')
        {
            flag = 3;
        }
        if (in[i] == ')' && in[i + 1] == '{')
        {
            printf("\n");
            puttab(i);
            flag = 0;
        }
        if (in[i] == '{')
        {
            get++;
            printf("\n");
            puttab(i);
        }
        if (in[i] == ';')
        {
            if (flag != 0)
                flag--;
            else
            {
                printf("\n");
                puttab(i);
            }
        }
        if (in[i] == '}')
        {
            get--;
            printf("\n");
            puttab(i);
        }
    }
    return 0;
}
void puttab(int i)
{
    int j = 0;
    if (in[i + 1] == '}')
        j++;
    for (; j < get; j++)
    {
        printf("    ");
    }
}