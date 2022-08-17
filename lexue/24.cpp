#include<stdio.h>
//#include<math.h>
//#include<string.h>
#define st 1
int main(void)
{
    int n,j,ans;
    scanf("%d",&n);
    ans=st;
    for(j=n-1;j>=1;j--)
    {
    	ans=(ans+j)*2;
	}
	if(ans==1)printf("The monkey got 1 peach in first day.\n");
	else printf("The monkey got %d peaches in first day.\n",ans);
	return 0;
}

