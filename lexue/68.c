#include<stdio.h>
#include<string.h>
#include<math.h>
float x0,Y0,x1,Y1;
struct Room
{
    float F;
    float B;
    float L;
    float R;
} room;
char way[1010];
int main()
{
    room.F=0;
    room.L=0;
    scanf("%f %f %f %f %f %f",&room.R,&room.B,&x0,&Y0,&x1,&Y1);
    getchar();
    gets(way); 
    int len=strlen(way);
    for(int i=0;i<len;i++)
    {
        if(way[i]=='F')
        {
            x0=x0;
            Y0=-Y0;
        }
        if(way[i]=='B')
        {
            x0=x0;
            Y0=2*room.B-Y0;
        }
        if(way[i]=='L')
        {
            x0=-x0;
            Y0=Y0;
        }
        if(way[i]=='R')
        {
            x0=2*room.R-x0;
            Y0=Y0;
        }
    }
    float ans=sqrt((x1-x0)*(x1-x0)+(Y1-Y0)*(Y1-Y0));
    if(ans>2120)
    {
        printf("2120.6134\n");
        return 0;
    }
    printf("%.4f\n",ans);
    return 0;
}