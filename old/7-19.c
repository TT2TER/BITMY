#include<stdio.h>
#define MAX 100
int main()
{
    int n;
    scanf("%d",&n);
    int y,f;
    for (y=0;y<MAX;y++)
    {
        for(f=0;f<MAX;f++)
        {
            if(98*f-199*y==n)
            {
                printf("%d.%d",y,f);
                goto exit;
            }
        }
    }
    printf("No Solution");
    exit:
    return 0;
}