#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	//freopen("1.out","w",stdout);
	int i,j,k;
	for (i=1;i<=n;i++)
	{
		for (j=n-i;j>=1;j--)printf("  ");
		for (k=1,j=n;k<=2*i-1;k++)
		{
			if (k<i) printf("%-2d",j--);
			else printf("%-2d",j++);
		}
		//for (j=n-i;j>=1;j--)printf(" ");
		printf("\n");
	}
	for (i=n-1;i>=1;i--)
	{
		for (j=n-i;j>=1;j--)printf("  ");
		for (k=1,j=n;k<=2*i-1;k++)
		{
			if (k<i) printf("%-2d",j--);
			else printf("%-2d",j++);
		}
		//for (j=n-i;j>=1;j--)printf(" ");
		printf("\n");
	}
	return 0;
}
