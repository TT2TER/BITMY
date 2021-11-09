#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int main()
{
    char ch[201];
    for(int j=0;j<201;j++)ch[j]='0';//printf("%c ",ch[j]);
    int flagd=60;//flagw=60,flagn=60;//浮点位置//，幂的位置，数字的位置
    //freopen("1.in","r",stdin);
    int i=60;//从第60个往前读方便移位
    char e;int a;//e读取e,a读取数字
    while(((ch[i++]=getchar())!=' '));//读到第一个空格
    int I=i-1;
    int fuck=I;
    scanf("%c",&e);
    scanf("%d",&a);
    //printf("%c\n%d\n",e,a);
    for(i=0;i<=201;i++)
    {
        if(ch[i]=='.')flagd=i;
    }
    if(flagd!=60)
    {
        fuck=flagd;
        for(;I<201;I++)ch[I]='0';//将所有非底数部分初始化为0;
    }
    if(flagd==60)
    {
        ch[I]='.';
    }
    if(a>0)
    {
        for(i=0;i<a;i++)
        {
            ch[flagd+i]=ch[flagd+i+1];
        }
        ch[flagd+i]='.';
        for(int j=60;j<=flagd+i+8;j++)
        printf("%c",ch[j]);
    }
    if(a<0)
    {
        for(i=0;i>a;i--)
        {
            ch[flagd+i]=ch[flagd+i-1];
        }
        ch[flagd+i]='.';
        for(int j=60+a;j<=flagd+i+8;j++)
        printf("%c",ch[j]);
    }
    if(a==0)
    {
        for(int j=60;j<=fuck+8;j++)
        printf("%c",ch[j]);
    }
    printf("\n");
    return 0;
}