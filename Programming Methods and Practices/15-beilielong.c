#include <stdio.h>
#include <stdlib.h>
struct drag
{
    long long int x;
    long long int y;
};
struct drag dragongood[200100];
struct drag dragonbad[200100];
int compare1x(const void *a, const void *b)
{
    return (*(struct drag *)a).x - (*(struct drag *)b).x;
}
int compare2x(const void *a, const void *b)
{
    if(((*(struct drag *)b).x+(*(struct drag *)b).y)==((*(struct drag *)a).x+(*(struct drag *)a).y))
    {
        return (*(struct drag *)b).x - (*(struct drag *)a).x;
    }
    else 
    {
        return (*(struct drag *)b).x+(*(struct drag *)b).y-((*(struct drag *)a).x+(*(struct drag *)a).y);
    }
    
}
int main()
{
    long long int force = 0,ta,tb;
    long long int ke = 0;
    int n,g=0,b=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&ta,&tb);
        {
            if(tb<0)
            {
                dragonbad[b].x=ta;
                dragonbad[b].y=tb;
                b++;
            }
            else
            {
                dragongood[g].x=ta;
                dragongood[g].y=tb;
                g++;
            }
        }
    }
    qsort(dragongood,g,sizeof(dragongood[0]),compare1x);
    qsort(dragonbad,b,sizeof(dragonbad[0]),compare2x);

    for(int i=0;i<g;i++)
    {
        if(force>=dragongood[i].x)
        {
            force+=dragongood[i].y;
        }
        else
        {
            ke+=(dragongood[i].x-force);
            force=dragongood[i].x+dragongood[i].y;
        }
    }
    for(int i=0;i<b;i++)
    {
        if(force>=dragonbad[i].x)
        {
            force+=dragonbad[i].y;
        }
        else
        {
            ke+=(dragonbad[i].x-force);
            force=dragonbad[i].x+dragonbad[i].y;
        }
    }
    printf("%lld\n",ke);
    return 0;
}