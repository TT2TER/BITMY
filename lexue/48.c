#include<stdio.h>  
#define min 10000  
#define max 30000  
int sub1,sub2,sub3,k;   
void apart(int a)  
{  
    int j,arr[6];  
    for(j=5;j>=1;j--)  
    {  
        arr[j]=a%10;  
        a/=10;  
    }  
    sub1=arr[1]*100+arr[2]*10+arr[3];  
    sub2=arr[2]*100+arr[3]*10+arr[4];  
    sub3=arr[3]*100+arr[4]*10+arr[5];  
}  
int judge(void)  
{     
    if(sub1%k==0&&sub2%k==0&&sub3%k==0)return 1;  
    else return 0;    
}  
int main(void)  
{  
    scanf("%d",&k);  
    int i;  
    for(i=min;i<=max;i++)  
    {  
        apart(i);  
        if(judge())printf("%d\n",i);  
    }  
    return 0;  
}  