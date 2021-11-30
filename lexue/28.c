#include<stdio.h>
#include<math.h>
//#include<string.h>
//#include<time.h>
int judge(int i,int n)
{
	int a=i;
	int N=n;
	int sum=0;
	int ret;
    for (;n>0;n--)
	{
		sum+=pow(a%10,N);
		a/=10;
	}
	if(sum==i)ret=1;
	else ret=0;
	return ret;	
}
int main(void)
{
    int n;
    scanf("%d",&n); 
    int flag=0;
    int i,start=1,end=10;
    for(i=n;i>1;i--)
    {  start*=10;
       end*=10;
	}
	for(i=start;i<end;i++)
	{
		if(judge(i,n))
		{
			printf("%d\n",i);
			flag++;
		}
	}
	if(!flag)printf("No output.\n");
	return 0;
}
