/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <math.h>   
#define N 50  
  
  
typedef struct{  
    double x;  
    double y;  
} POINT;  
typedef POINT* P_POINT;  
  
void line(P_POINT pp, int n);  
  
int main()    
{  
    POINT points[N];  
    P_POINT pt=points;  
      
    int i,n,ret;   
    scanf("%d", &n);   
       
    for(i=0; i<n; i++,pt++)
	{  
        ret=scanf("%lf%lf",&pt->x,&pt->y);  
    }  
    line(points, n);   //编写此函数并输出解  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  
void line(P_POINT pp, int n)
{
	int noans=1;
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				POINT a,b;
				a.x=pp[i].x-pp[j].x;
				a.y=pp[i].y-pp[j].y;
				b.x=pp[i].x-pp[k].x;
				b.y=pp[i].y-pp[k].y;
				if(b.x<0&&b.y<0)
				{
					b.x=fabs(b.x);
					b.y=fabs(b.y);
				}
				//printf("%lf %lf %lf %lf %lf %lf %d %lf %d\n",a.x,b.x,a.y,b.y,a.x/b.x,a.y/b.y,(a.x/b.x)==(a.y/b.y),a.x/b.x-a.y/b.y,fabs(a.x/b.x-a.y/b.y)<0.000001);
				
				if(fabs(a.x/b.x-a.y/b.y)<0.000001)
				{
					printf("(%.2f,%.2f)(%.2f,%.2f)(%.2f,%.2f)\n",pp[i].x,pp[i].y,pp[j].x,pp[j].y,pp[k].x,pp[k].y);
					noans=0;
				}
//printf("%d %d %d\n",i,j,k);
			}
		}
	}
    if(noans)
    {
    	printf("no result!\n");
	}
}
