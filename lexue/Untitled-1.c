#include<stdio.h>  
char ch[1000],c,c1;  
int scnt(int a,int b,char c){  
    switch(c){  
        case '+':return a+b;  
        case '-':return a-b;  
        case '*':return a*b;  
        case '/':return a/b;  
    }  
}  
int main()  
{  
    int arr[1000]={0},cnt=0,num1=0,num2,num3,num=0,cnt1=0,i;  
    while((c=getchar())!=EOF){  
        if(c==' '||c=='\n')continue;  
        if(isdigit(c)){  
            num=c-'0';  
            while((c=getchar())!=EOF){  
                if(c==' ')  
                {  
                    arr[cnt++]=num;  
                    num=0;  
                    break;  
                }  
            else num=num*10+c-'0';  
        }  
        }  
        else  
        {  
            arr[cnt-2]=scnt(arr[cnt-2],arr[cnt-1],c);  
            arr[cnt-1]=0;  
            cnt--;  
        }  
    }  
    printf("%d\n",arr[0]);  
}  