#include<stdio.h>
//#include<math.h>
int main(void)
{
	//freopen("1.out","w",stdout);
    int h;
    scanf("%d",&h);
    int i,j;
    if(h==1){printf("*\n");return 0;
	}
	else
	{
		for(i=1;i<2*h;i++)
		{
			printf("*");
			if(i==2*h-1)printf("\n");
		}
	}
	for(i=h-1;i>=1;i--)
    {
    	for(j=1;j<=2*h;j++)
    	{   if(j==h+i/*&&i!=1*/)
    	{
    		printf("\n");
    		break;
		}
			if(j==h+1-i||j==h+i-1)printf("*");
    		else printf(" ");
    		
		}
	}
	return 0;
}
 
