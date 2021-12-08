//张姐yyds!!!!
# include<stdio.h>
int main()
{
    char c;
    int i,a[128]={0};
    while ((c=getchar())!=EOF)
    {
        if((0<=c&&c<=32)||c==127)
        {
            a[c]++;
        }
        // else if(c=NULL)
        // {
        //     a[0]++;
        // }
    }
    for(i=0;i<=127;i++)
    {
        if(a[i])
        printf("[%d]=%d\n",i,a[i]);
    }
    return 0;
}