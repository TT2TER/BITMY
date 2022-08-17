#include<stdio.h>
#define q 1900
int main()
{
	int year;
	scanf("%d",&year);
	int i,run=0;
	for(i=q;i<=year;i++)
	{
	   if((i%400==0)||((i%100!=0)&&(i%4==0)))run+=1;
	} 
	int days=(year-q)*365+run+31+28+31+30;
	int week=(days+1)%7;
	if(!week)week+=7;
	//printf("%d %d\n",week,run);
	int a=0;//a=五月的第几天 
	a+=15-week;//最一开始用了两个循环，非常繁琐 
	printf("%d\n",a);
	return 0;
}
