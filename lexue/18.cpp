#include<stdio.h>
//#include<math.h>
//#include<string.h>
int vs(int a,int b)
{
	if(a<=b)return a;
	else return b;
} 
int main(void)
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("min=%d\n",vs(a,b));  
	return 0;
}

