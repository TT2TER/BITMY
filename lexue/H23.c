#include <stdio.h>
#include <ctype.h>
char in[80];
int tab;
int enter;
//TODO:if while
int checkfor(int i)
{
    int ret = 0;
    for (int j = 0; j <= i - 2; j++)
    {
        if (in[j] == 'f' && in[j + 1] == 'o' && in[j + 2] == 'r')
        {
            ret = 1;
            break;
        }
    }
    return ret;
}

void puttab(int tab)
{
    for (int k = 0; k < tab; k++)
    {
        printf("    ");
    }
}

int main()
{
    freopen("1.out", "w", stdout);
    int i = 1;
    while ((in[i] = getchar()) != EOF)
    {
        if (checkfor(i) && in[i] == ')') //"-2"
        {
            puttab(tab);
            for (int k = 1; k < i; k++)
            {
                printf("%c", in[k]);
            }
            printf("%c\n", in[i]);
            i = 1;
            continue;
        }
        if (in[i] == ';' && in[i - 1] == ')') //"-1"
        {
            puttab(tab);
            for (int k = 1; k < i; k++)
            {
                printf("%c", in[k]);
            }
            printf("%c\n", in[i]);
            i = 1;
            continue;
        }
        if (in[i] != ';' && in[i - 1] == ')') //"0"
        {
            if (in[i] == '{')
            {
                puttab(tab);
                for (int k = 1; k < i; k++)
                {
                    printf("%c", in[k]);
                }
                printf("\n");
                puttab(tab);
                printf("{\n");
                tab++; //A
            }
            else
            {
                puttab(tab);
                for (int k = 1; k < i; k++)
                {
                    printf("%c", in[k]);
                }
                printf("\n");
            }
            i = 1;
            continue; //TODO:may be bug here
        }
        if (!checkfor(i) && in[i] == ';') //"1"
        {
            puttab(tab);
            for (int k = 1; k < i; k++)
            {
                printf("%c", in[k]);
            }
            printf("%c\n", in[i]);
            i = 1;
            continue;
        }
        if (in[i] == '{')
        {
            puttab(tab);
            printf("{\n");
            tab++; //A
            i = 1;
            continue;
        }
        if (in[i] == '}')
        {
            tab--; //B
            puttab(tab);
            printf("}\n");
            i = 1;
            continue;
        }
        if (in[i] != '>') //D
            ;
        else
        {
            puttab(tab);
            for (int k = 1; k < i; k++)
            {
                printf("%c", in[k]);
            }
            printf("%c\n", in[i]);
            i = 1;
            continue;
        }
        if (in[i] == '\n') //吃掉所有回车
        {
            i = 1;
            continue;
        }
        i++;
    }
    return 0;
}