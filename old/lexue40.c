#include<stdio.h>
#include<string.h>
#include<math.h>
char a[11],b[11];
int na[11],nb[11];
int sum(int sys,int l,int a[])
{
    int all=0;
    int K;int s;
    for(K=l-1,s=0;K>=0;K--,s++)
    {   
        int d=pow(sys,K);
        all+=a[s]*d;
    }
    return all;
}
int main()
{
    //freopen("1.out","w",stdout);
    int i=0,j;
    while((a[i]=getchar())!=' ')i++;
    a[i]='\0';
    i=0;
    while((b[i]=getchar())!='\n')i++;
    b[i]='\0';
    int la,lb;
    la=strlen(a);
    lb=strlen(b);
    //printf("%d %d",la,lb);
    int mma=0,mmb=0;
    for(i=0;i<la;i++)
    {
        if(mma<a[i])mma=a[i];
    }
    for(i=0;i<lb;i++)
    {
        if(mmb<b[i])mmb=b[i];
    }
    
    int mina=2,minb=2;
    mina=(mma>=65?mma-54:mma-'0'+1)>=2?(mma>=65?mma-54:mma-'0'+1):2;
    minb=(mmb>=65?mmb-54:mmb-'0'+1)>=2?(mmb>=65?mmb-54:mmb-'0'+1):2;
    for(i=0;i<la;i++)
    {
        na[i]=a[i]>=65?a[i]-55:a[i]-'0';
        //printf("%d",na[i]);
    }
    //printf("\n");
    for(i=0;i<lb;i++)
    {
        nb[i]=b[i]>=65?b[i]-55:b[i]-'0';
        //printf("%d",nb[i]);
    }
    //printf("%d %d",mina,minb);
    int m,n;
    int ret=0;
    for(i=mina;i<=36;i++)
    {
        for(j=minb;j<=36;j++)
        {  
            m=sum(i,la,na);
            n=sum(j,lb,nb);
            if(m==n){ret=1;goto fuck;}
        }
    }
    fuck:
    if(ret)
    printf("%s (base %d) = %s (base %d)\n",a,i,b,j);
    else printf("%s is not equal to %s in any base 2..36\n",a,b);
    return 0;
}