//S=(x1*y2-x1*y3+x2*y3-x2*y1+x3*y1-x3*y2)/2;
#include<stdio.h>
#include<math.h>
typedef struct _Point
{
    int x;
    int y;
} point;
float area(point p1,point p2,point p3)
{
    float S=fabs(p1.x*p2.y-p1.x*p3.y+p2.x*p3.y-p2.x*p1.y+p3.x*p1.y-p3.x*p2.y)/2.0;
    return S;
}
void find(point *arr,int N)
{
    float max=0;
    for(int i=1;i<=N-2;i++)
    {
        for(int j=i+1;j<=N-1;j++)
        {
            for(int k=j+1;k<=N;k++)
            {
                float S=area(arr[i],arr[j],arr[k]);
                max=S>max?S:max;
            }
        }
    }
    printf("%.1f\n",max);
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        point arr[101];
        for(int j=1;j<=N;j++)
        {
            scanf("%d %d",&arr[j].x,&arr[j].y);
        }
        find(arr,N);
    }
    return 0;
}