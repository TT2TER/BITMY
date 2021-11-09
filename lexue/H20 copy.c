#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d\n", &n);
    const int N = n;
    char name[N + 2][25];
    char num[11000];
    int i;
    char *namer[N + 2];
    char *numr[N + 2];
    int sum=0;
    for (i = 1; i <= N; i++)
    {
        scanf("%s", name[i]);
        namer[i]=name[i];
        scanf("%s",&num[0+sum]);
        numr[i]=&num[0+sum];
        int len=strlen(&num[0+sum]);
        sum+=len+1;
    }
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
                if (strcmp(numr[j], numr[j + 1]) < 0)
            {
                char* temp;
                temp = numr[j];
                numr[j] = numr[j + 1];
                numr[j + 1] = temp;
                temp = namer[j];
                namer[j] = namer[j + 1];
                namer[j + 1] = temp;
            }
                else if ((strcmp(namer[j], namer[j + 1]) > 0)&&(strcmp(numr[j], numr[j + 1]) == 0))
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