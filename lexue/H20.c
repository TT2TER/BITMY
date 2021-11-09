#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d\n", &n);
    const int N = n;
    char name[N + 2][25];
    char num[N + 2][10020];
    int i;
    for (i = 1; i <= N; i++)
    {
        scanf("%s", name[i]);
        scanf("%s", num[i]);
    }
    char *namer[N + 2];
    char *numr[N + 2];
    for (i = 1; i <= N; i++)
    {
        namer[i] = name[i];
        numr[i] = num[i];
    }
    //冒泡排序判断大小并且交换对应地址
    int j;
    for (i = 1; i < N; i++)
    {
        for (j = 1; j < N - (i - 1); j++)
        {
            //printf("%s ",namer[j]);
            int lnum1, lnum2;
            lnum1 = strlen(numr[j]);
            lnum2 = strlen(numr[j + 1]);
            if (lnum1 < lnum2)
            {
                char* temp;
                temp = numr[j];
                numr[j] = numr[j + 1];
                numr[j + 1] = temp;
                temp = namer[j];
                namer[j] = namer[j + 1];
                namer[j + 1] = temp;
            }
            else if (lnum1 == lnum2)
            {
                if (strcmp(namer[j], namer[j + 1]) > 0)
                {
                    char* temp;
                    temp = numr[j];
                    numr[j] = numr[j + 1];
                    numr[j + 1] = temp;
                    temp = namer[j];
                    namer[j] = namer[j + 1];
                    namer[j + 1] = temp;
                }
            }
        }
    }
    for (i = 1; i <= N; i++)
    {
        printf("%s\n",namer[i]);
    }
    return 0;
}