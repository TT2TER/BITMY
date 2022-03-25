#include<stdio.h> 
#include<string.h>
#include<math.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	int map[105][105];
	int i=0,j=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	int k=0;
	scanf("%d",&k);
	if(k%4==0)
	{
		for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d",map[i][j]);
			if(j!=n)printf(" ");
		}
		printf("\n");
	}
	}
	else if(k%4==1)
	{
			for(j=1;j<=n;j++)
	{
		for(i=n;i>=1;i--)
		{
			printf("%d",map[i][j]);
			if(i!=1)printf(" ");
		}
		printf("\n");
	}
	}
	else if(k%4==2)
	{
			for(i=n;i>=1;i--)
	{
		for(j=n;j>=1;j--)
		{
			printf("%d",map[i][j]);
			if(j!=1)printf(" ");
		}
		printf("\n");
	}
	}
	else if(k%4==3)
	{
			for(j=n;j>=1;j--)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d",map[i][j]);
			if(j!=n)printf(" ");
		}
		printf("\n");
	}
	}
	return 0;
}
