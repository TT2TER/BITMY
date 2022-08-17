#include<stdio.h>
#include<string.h>
char ch[250][5000];
int main()
{   int i=1;
    while(scanf("%s",ch[i++])!=EOF);
    for(int j=i;j>=1;j--)
    {
        printf("%s",ch[j]);
        if(j!=1)printf(" ");
    }
    return 0;
}