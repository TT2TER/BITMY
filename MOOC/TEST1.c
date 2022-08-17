#include<stdio.h>
#include<string.h>
int main()
{
    char c[22];
    gets(c);
    int len=strlen(c);
    if(len==1)
    {
        puts(c);
        return 0;
    }
    for (int i=0;i<len+1;i++)
    {
        for(int j=0;j<len;j++)
        {
            int a=(j+i)%len;
            printf("%c",c[a]);
        }
        printf("\n");
    }
    return 0;
}