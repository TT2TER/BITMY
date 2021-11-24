#include<stdio.h>
int main()
{
    int n;
    char c;
    scanf("%d %c",&n,&c);
    //printf("%d %c",n,c);
    int i,j;
    char a[1000];
    int sum=0,cnt=0;
    for(i=1;i<=n*n;i++)
    {
        a[i]=c;
        if('a'<=c&&c<='z')
        {
            c=c=='z'?'a':c+1;
        }
        if('A'<=c&&c<='Z')
        {
            c=c=='Z'?'A':c+1;
        }
    }
    int start=n*n-(2*n-1);
    for ( i = 0; i < n; i++)
    {
        for(j=1;j<=i;j++)
        {
            printf(" ");
        }
        for(j=1;j<=n-i+n-i-1;j++)
        {
            printf("%c",a[start+j]);
            cnt++;
        }
        start-=cnt-2;
        cnt=0;
        printf("\n");
    }

    
    return 0;
}