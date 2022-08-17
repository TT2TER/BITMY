#include<stdio.h>
//#include<math.h>
//#include<string.h>
inline int judge(int a)
{   int j;
    int flag=0;
	for(j=1;j<=a;j++)
	{
		if(a%j==0)flag++;
	}
	if(flag==2)return a;
	else return 0;
}
inline int vs(int a,int b)
{
	if(a>b)return a;
	else return b;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    int i;
    long long max=0;
    for(i=1;i<=n;i++)
    {
    	max=vs(max,judge(i));
	}
	printf("The max prime number is %ld.\n",max);
	return 0;
}

