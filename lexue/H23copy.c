#include <stdio.h>
#include <ctype.h>
char in[1000];
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

int checkjing(int i)
{
    int ret = 0;
    for (int j = 0; j <= i; j++)
    {
        if (in[j] == '#')
        {
            ret = 1;
            break;
        }
    }
    return ret;
}

int check(int i) //if
{
    int ret = 0;
    for (int j = 0; j <= i - 1; j++)
    {
        if (in[j] == 'i' && in[j + 1] == 'f')
        {
            return 1;
        }
    }
    for (int j = 0; j <= i - 4; j++)
    {
        if (in[j] == 'w' && in[j + 1] == 'h' && in[j + 2] == 'i' && in[j + 3] == 'l' && in[j + 4] == 'e')
        {
            return 1;
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
    freopen("2.out", "w", stdout);
    int i = 1;
    while ((in[i] = getchar()) != EOF)
    {
        if (checkfor(i) && in[i] == ')'&&in[i-1]!='\'') //"-2"
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
        if (in[i] == ';' && in[i - 1] == ')'&&in[i-2]!='\'') //"-1"
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
        if (in[i] != ';' && in[i - 1] == ')'&&in[i-2]!='\'') //"0"
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
            else if (check(i))
            {
                if (in[i] == '{')
                {
                    puttab(tab);
                    for (int k = 1; k < i; k++)
                    {
                        if(in[k]!='\n')
                        printf("%c", in[k]);
                    }
                    printf("\n");
                    puttab(tab);
                    printf("{\n");
                    tab++; //A
                }
                else if (in[i] == ';'&&in[i-1]=='\'')
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
                else
                {
                    i++;
                    continue;
                }
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

        if (!checkfor(i) && in[i] == ';'&&in[i-1]!='\'') //"1"
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

        if (in[i] == '{'&&in[i-1]!='\'')
        {
            if(i!=1)
            {
                puttab(tab);
                for(int k=1;k<i;k++)
                {
                    if(in[k]!='\n')
                    printf("%c", in[k]);
                }
                printf("\n");
            }
            puttab(tab);
            printf("{\n");
            tab++; //A
            i = 1;
            continue;
        }

        if (in[i] == '}'&&!check(i)&&!checkfor(i))
        {
            tab--; //B
            puttab(tab);
            printf("}\n");
            i = 1;
            continue;
        }

        if (checkjing(i) && in[i] == '>') //D
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
            if(i!=1)puttab(tab);
            if(check(i))
            for(int k=1;k<i;k++)
            {
                if(in[k]!='\n')
                printf("%c",in[k]);
            }
            if(check(i))
            {
                printf("\n");
            }
            i = 1;
            continue;
        }
        i++;
    }
    return 0;
}