#include<stdio.h>
#include<string.h>
char ch[500100];
int pos[500100],cnt;
int main()
{
    gets(ch+1);//gets(&ch[1]);
    ch[0]=' ';
    int len=strlen(ch);
    //printf("%d\n",len);
    for(int i=1;i<=len-1;i++)
    {
        if(ch[i-1]==' '&&ch[i]!=' ')pos[++cnt]=i;
    }
    for(int i=cnt;i>0;i--)
    {
        for(int j=pos[i];ch[j]!=' '&&ch[j]!='\0';j++)
        {printf("%c",ch[j]);}
        if(i!=1)printf(" ");
    }
    return 0;
}