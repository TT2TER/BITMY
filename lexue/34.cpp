#include<stdio.h>
//#define q 1900
int main()
{   //freopen("1.in","r",stdin);
    int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int year,month,day,i=0,run=0,plus;
	scanf("%d %d %d",&year,&month,&day);
	scanf("%d",&plus);
			for(;plus;)
			{
				if(((year%400==0)||((year%100!=0)&&(year%4==0)))&&month==2)run=1;
				else run=0;
				if(m[month]+run-day<plus)
				{   plus-=m[month]+run+1-day;
					day=1;
					if(month==12)month=1,year+=1;
					else month+=1;
				}
				else if(m[month]+run-day>=plus)
				{
					day+=plus;
					plus=0;
				}
			
			}
		

		//计算所有天数； 
	//int week=days%7;
	printf("%d.%d.%d\n",year,month,day);
	return 0;
}
