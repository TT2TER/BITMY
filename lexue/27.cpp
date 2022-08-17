#include<stdio.h>
int main(void)
{
    int min[100]={},max[100]={};
    int i;
    for(i=1;i<100;i++)
    {
    	scanf("%d %d",&min[i],&max[i]);
    	if(!(min[i]&&max[i])) {break;
		}
	}
	int I=i;
	//printf("%d\n",min[i]); 
    for(i=1;i<I;i++)
    {   int j; int counter=0;
        //int ans[max[i]];
        if(min[i]>=1000&&max[i]>=min[i])
		{int k,b,s,g;//int flag=-1;
    	for(j=min[i];j<=max[i];j++)
    	{   
    		k=j/1000;
    		b=j/100%10;
    		s=j/10%10;
    		g=j%10;
    		//printf("\n%d %d %d %d",k,b,s,g);
			
    		if((k!=b)&&(k!=s)&&(k!=g)&&(b!=s)&&(b!=g)&&(s!=g)&&(j%2==0))
    		{counter+=1;/*flag+=1;*/printf("%d  ",j);
    		//if(!flag)
    		//if(flag) printf("  %d",j);
			}
		}
		printf("\ncounter=%d",counter);
		}
        else printf("Error");
        printf("\n");
	}
	return 0;
}
