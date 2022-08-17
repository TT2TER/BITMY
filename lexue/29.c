#include<stdio.h>
//#include<math.h>
int main(void)
{    int n;
     scanf("%d",&n);
     int i,j,a=1;
     for(i=1;i<=n;i++)
     {
     	for(j=1;j<=n;j++)
     	{
     		printf("%3d",a);
     		a++;
     		if(j==n)printf("\n");
		 }
	 }
    
	return 0;
}
