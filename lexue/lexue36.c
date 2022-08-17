#include<stdio.h>
int main()
{
    //freopen("1.out","w",stdout);
    int h,st,now;
    scanf("%d %d",&h,&st);
    if(h==1){printf("%d\n",st);return 0;}
    int flag;
    flag=(h%2?1:0);//偶数是0
    now=st;
    int i;
    for(i=1;i<=3*h-2;i++)
    {
        printf("%d",now);
        if(i<3*h-2)printf(" ");
        if(i<=(3*h-2)/2&&flag==1)now=(now==9?0:now+1);
        else if(flag==1)now=(now==0?9:now-1);
        if(flag==0&&i<(3*h-2)/2)now=(now==9?0:now+1);
        else if(flag==0&&i>(3*h-2)/2)now=(now==0?9:now-1);
        else if(flag==0&&i==(3*h-2)/2);
    }
    printf("\n");
    int j;
    now=(st==9?0:st+1);
    for(j=1;j<=h-2;j++)
    {
        for(i=0;i<j;i++)printf("  ");
        printf("%d ",now);
        for(int k=0;k<(h-j-2)*2+h;k++)
        printf("  ");
        printf("%d\n",now);
        now=(now==9?0:now+1);
    }
    for(i=0;i<j;i++)printf("  ");
    for(i=1;i<=h;i++)
    {
        printf("%d",now);
        if(i<=h-1)printf(" ");
        if(i<=h/2&&flag==1)now=(now==9?0:now+1);
        else if(flag==1) now=(now==0?9:now-1);
        if(flag==0&&i<h/2)now=(now==9?0:now+1);
        else if(flag==0&&i>h/2)now=(now==0?9:now-1);
        else if(flag==0&&i==h/2);
    }
    printf("\n");
    return 0;
}