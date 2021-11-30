#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,d,e;
	scanf("%lf %lf",&a,&b);
	d=b*360.0/60.0;
	c=a*360.0/12.0+b*360.0/(12.0*60.0);
	e=fabs(c-d);
	printf("At %d:%02d the angle is %.1lf degrees.\n",(int)a,(int)b,e<=180?e:360.0-e);
	return 0;
 } 
