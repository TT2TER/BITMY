# include<stdio.h>
# include<math.h>
double Sqrt(double x,double p, double e)
{
    if(fabs(p*p-x)<e)
    return p;
    if(fabs(p*p-x)>=e)
    {
        return Sqrt(x,0.5*(p+x/p),e);
    }
}
int main()
{
    double a;
    double b;
    scanf("%lf %lf",&b,&a);
    double c=Sqrt(b,b,a);
    // if(c==(int)c)
    // printf("%d",(int)c);
    printf("%.8f\n",c);
    return 0;
}