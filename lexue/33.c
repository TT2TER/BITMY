#include<stdio.h>
//#include<math.h>
//bubble(int a[100];); 
int main(void)
{
    long long n;
    int count=0;
	int a[100]={0};
	scanf("%lld",&n) ;
	int i;
	for(i=1;n!=0;i++)
	{
		a[i]=n%10;
		n/=10;
		++count;
	}
	//printf("%d",count);
	int j;
	for(i=1;i<=count;i++)
	{
		for(j=0;j<=count-i;j++)
		{
			if(a[j]<a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<count;i++)
	{printf("%d",a[i]);
	}
	printf("\n");
	return 0;
}
