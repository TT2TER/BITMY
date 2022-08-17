#include<stdio.h> 
char num[13];
int nnum[13];
int main()
{
    scanf("%c\n",&num[1]);
    nnum[1]=num[1]-'0';
    for(int i=2;i<=6;i++)
    {
        scanf("%c",&num[i]);
        nnum[i]=num[i]-'0';
    }
    scanf("\n");
    for(int i=7;i<=11;i++)
    {
        scanf("%c",&num[i]);
        nnum[i]=num[i]-'0';
    }
    // for(int i=1;i<=11;i++)
    // {
    //     printf("%c",num[i]);
    // }
    int a,b,c;
    a=nnum[1]+nnum[3]+nnum[5]+nnum[7]+nnum[9]+nnum[11];
    b=nnum[1+1]+nnum[3+1]+nnum[5+1]+nnum[7+1]+nnum[9+1];
    a*=3;
    c=9-(a+b-1)%10;
    printf("%d\n",c);
    return 0;
}