#include<stdio.h>
//#include<math.h>
//#include<string.h>
double r,h,s,v;
#define pi 3.1415926
int main(void)
{
    scanf("%lf",&r);
    scanf("%lf",&h);
    printf("s=%.2lf,v=%.2lf\n",2*pi*r*h,pi*r*r*h);
	return 0;
}

