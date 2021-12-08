#include<stdio.h>
typedef struct 
{
    int num;
    int a;
    int b;
    int c;
} stu;
int main()
{
    stu a[3]=
    {
        {1,90,80,70},
        {2,85,75,95},
        {3,88,84,65},
    };
    char b[4]={'\0'};
    gets(b);
    if(b[0]=='m')
        printf("2\n");
    else if(b[0]<='3')
        printf("%d\n",(a[b[0]-'0'-1].a+a[b[0]-'0'-1].b+a[b[0]-'0'-1].c)/3);
    else printf("0\n");
    return 0;
}