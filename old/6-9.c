#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;

    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}
int Count_Digit ( const int N, const int D )
   {
   int M,L,ret=0;
   if(N<0)M=0-N;
   else M=N;
   L=M;
   int count=0;
   //�����һλ��ʼ��ǰ��λ�ǲ��Ǵ���0 
   do 
   {
   	count++;
   	L/=10;
   }
   while (L>0);
   //�����λ��ʼ�Ƚ��Ƿ���ͬ 
   for (int a;count>0;count--)
   {a=M%10;
   if (a==D)
   { ret=ret+1;
     M/=10;
   }
   else M/=10;
   }
   //printf("%d",ret);
   return ret;
   }
