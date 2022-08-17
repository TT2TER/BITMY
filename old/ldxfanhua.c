#include<stdio.h>
#include<string.h>
char s[500010];
int pos[500010],cnt;
int main()
{
 gets(s+1);
 int n=strlen(s+1);
 s[0]=' ';
 for(int i=1;i<=n;++i)if(s[i-1]==' '&&s[i]!=' ')pos[++cnt]=i;
 for(int i=cnt;i;--i)
 {
  for(int j=pos[i];s[j]!=' '&&s[j];j++)printf("%c",s[j]);
  if(i!=1)printf(" ");
 }
 return 0;
}
     