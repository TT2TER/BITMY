#include<stdio.h>
int main(void)
{
    int a,n,ans=1;
	scanf("%d %d",&a,&n);
	int i,temp;
//	if(!a){printf("The last 3 numbers is 0.");return 0;
	//}
	int flag=0;
	for (i=1;i<=n;i++)
	{
		 ans*=a;
		 if(ans>=1000)flag=1;
		 ans=ans%1000;
		 
	}
	if(flag)printf("The last 3 numbers is %03d.\n",ans);
	else printf("The last 3 numbers is %d.\n",ans);
	return 0;
}
