#include<stdio.h>
#define q 1900
int main()
{

	int year,month,day,i=0,run=0;
	scanf("%d %d %d",&year,&month,&day);
	if(month>12){printf("month is error.\n");return 0;}
	for(i=q;i<year;i++)
	{
		if((i%400==0)||((i%100!=0)&&(i%4==0)))run+=1;
	}//在输入年份之前闰年个数 
	int days=(year-q)*365+run;//在输入年份之前天数
	int run0=0;
		if((year%400==0)||((year%100!=0)&&(year%4==0)))run0+=1;
	    if(month==1)
	    {
	    	if(day>31){printf("day is error.\n");return 0;}
	    	days+=day;
		}
		if(month==2)
		{
			if(day>28+run0){printf("day is error.\n");return 0;}
	    	days+=31+day;
		}
		if(month==3)
		{
			if(day>31){printf("day is error.\n");return 0;}
			days+=run0;
	    	days+=31+28;
			days+=day;
		}
		if(month==4)
		{
			if(day>30){printf("day is error.\n");return 0;}
			days+=run0;
			days+=31+28+31;
			days+=day;
		}
		if(month==5)
		{
			if(day>31){printf("day is error.\n");return 0;}
			days+=run0;
	    	days+=31+28+31+30;
			days+=day;
		}
		if(month==6)
		{
			if(day>30){printf("day is error.\n");return 0;}
			days+=run0;
	    	for(i=1;i<month;i++)
	    	days+=31+28+31+30+31;
			days+=day;
		}
		if(month==7)
		{
			if(day>31){printf("day is error.\n");return 0;}
			days+=run0;
	        days+=31+28+31+30+31+30;
			days+=day;
		}
		if(month==8)
		{
			if(day>31){printf("day is error.\n");return 0;}
			days+=run0;
	        days+=31+28+31+30+31+30+31;
			days+=day;
		}
		if(month==9)
		{
			if(day>30){printf("day is error.\n");return 0;}
			days+=run0;
	        days+=31+28+31+30+31+30+31+31;
			days+=day;
		}
		if(month==10)
		{
			if(day>31){printf("day is error.\n");return 0;}
			days+=run0;
			days+=31+28+31+30+31+30+31+31+30;
			days+=day;
		}
		if(month==11)
		{
			if(day>30){printf("day is error.\n");return 0;}
			days+=run0;
	        days+=31+28+31+30+31+30+31+31+30+31;
			days+=day;
		}
		if(month==12)
		{
			if(day>31){printf("day is error.\n");return 0;}
			days+=run0;
	        days+=31+28+31+30+31+30+31+31+30+31+30;
			days+=day;
		}
		//计算所有天数； 
	int week=days%7;
	printf("%d\n",week);
	return 0;
}
