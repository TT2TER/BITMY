#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int main()
{
    char ch[201];
    for(int j=0;j<201;j++)ch[j]='0';//printf("%c ",ch[j]);
    int flagd=50,flagw=50,flagn=50;//浮点位置，幂的位置，数字的位置
    freopen("1.in","r",stdin);
    int i=50;
    int cnt=0;
    int neg=1;
    while((ch[i++]=getchar())!=EOF);
    for(i=0;i<=201;i++)
    {
        if(ch[i]=='.')flagd=i;
        if(ch[i]=='E'||ch[i]=='e')flagw=i;
        if(i>=flagw&&ch[i-1]==' '&&ch[i]!=' ')flagn=i;
    }
    if(flagw==flagn)flagn++;
    if(ch[flagn]=='-')
    {   
        neg=-1;
        flagn++;
    }
    for(i=0;i<2;i++)
    {
        if(isdigit(ch[flagn+i]))cnt++;
    }
    int num=0;
    for(i=0;i<cnt;i++)
    {
        num+=(ch[flagn+i]-'0')*pow(10,cnt-1-i);
    }
    if(neg>0)
    {
        for(i=0;i<num;i++)
        {
            ch[flagd+i]=ch[flagd+i+1];
        }
        ch[flagd+i]='.';
        for(int j=50;j<201;j++)//TODO:
        printf("%c",ch[j]);
    }
    if(neg<0)
    {
        for(i=0;i>-num;i--)
        {
            ch[flagd+i]=ch[flagd+i-1];
        }
        ch[flagd+i]='.';
        for(int j=50-num;j<201;j++)//TODO:
        printf("%c",ch[j]);
    }
    //num=neg*num;
    printf("\n%c %c %c %d",ch[flagd],ch[flagw],ch[flagn],flagd);//从第0位读进去了
    return 0;
}