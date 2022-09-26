#include <stdio.h>
#include<string.h>
struct Build
{
    long int c;
    long int h;
    long int dif;
};
struct Build all[1000100];
int main()
{
    long int n;
    scanf("%ld", &n);
    
    while (n--)
    {
        long int m;
        scanf("%ld",&m);
        for(long int i=1;i<=m;i++)
        {
            scanf("%ld",&all[i].c);
        }
        for(long int i=1;i<=m;i++)
        {
            scanf("%ld",&all[i].h);
        }
        for(long int i=1;i<=m;i++)
        {
            if(i==1)
            {
                all[i].dif=1;
            }
            else
            {
                if(all[i].h>=all[i-1].h)
                {
                    all[i].dif=1;
                }
                else{
                    if(all[i].c!=all[i-1].c)
                    {
                        all[i].dif=1+all[i-1].dif;
                    }
                    else
                    {
                        all[i].dif=all[i-1].dif;
                    }
                }
            }
        }
        for(long int i=1;i<=m;i++)
        {
            if(i!=m)
            printf("%ld ",all[i].dif);
            else
            printf("%ld\n", all[i].dif);
        }
    }
    return 0;
}