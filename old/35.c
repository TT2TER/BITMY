#include<stdio.h>
#include<math.h>
#define yj 0.1
#define wu 0.5
#define yy 1.0
int judge(double a,double b,double c,int n)
{
    int ret;
    if(a*yj+b*wu+c*yy>n)ret=-1;
    else if(fabs(a*yj+b*wu+c*yy-n)<1e-6)ret=1;
    else ret=0;
    return ret;
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i;i++)
    {
        int j=judge(10/9*i,4/3*i,i,n);
        if (j==1){printf("%d,%d,%d\n",10*i,12*i,9*i);break;}
        if(j==0);
        if(j==-1)
        {
            printf("No change.\n");
            break;
        }
    }
}
//10:12:9