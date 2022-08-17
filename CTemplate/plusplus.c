#include <stdio.h>
#include <string.h>
//char a[510], b[510], c[510];
int sum(char *a, char *b, char *c, int la, int lb)
{
    int now = 0, up = 0;
    while (now < la || now < lb)
    {
        if(a[now]=='\0')a[now]='0';
        if(b[now]=='\0')b[now]='0';
        c[now] = (a[now] - '0' + b[now] - '0' + up) + '0';
        up = (c[now] - '0') / 10;
        c[now] = ((c[now] - '0') % 10) + '0';
        now++;
    }
    if (up == 0)
        now--;
    else
        c[now] = up + '0';
    return now;
}
int main()
{
    char c[100];
    char a[10]={'1','2','3','9'};
    char b[10]={'1','2','3','4'};
    int z=sum (a,b,c,4,4);//z=len-1;
    for(;z>=0;z--)
    {
        printf("%c",c[z]);
    }
    return 0;
}