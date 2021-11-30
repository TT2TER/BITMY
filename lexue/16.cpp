#include<stdio.h>  
#include<math.h>  
double a,b,c;     
double d,e,f,g,h,j,k,l,ans;  
int main ()  
{  
    scanf("%lf %lf %lf", &a, &b, &c);  
    d = b*b - 4*a*c;  
    e = sqrt(fabs(d));  
    if (a==0&&b==0)printf("Input error!\n");  
    else if (a==0&&b!=0&&c!=0) ans=-c/b,printf("x=%.6lf\n",ans);  
    else if (a==0&&b!=0&&c==0) ans=c/b,printf("x=%.6lf\n",ans);  
    else if (a!=0&&b==0&&d==0) ans=-c/a,printf("x1=x2=%.6lf\n",sqrt(fabs(ans)));      
    else if (a!=0&&b!=0&&d==0) printf("x1=x2=%.6lf\n",-b/(2*a));  
    else if (d>0&&a!=0) f=(-b+e)/(2*a),g=(-b-e)/(2*a),printf("x1=%.6lf\nx2=%.6lf\n",f,g);  
    else if (d<0&&a!=0&&b!=0) h=-b/(2*a),j=e/(2*a),k=-b/(a*2),l=e/(2*a),printf("x1=%.6lf+%.6lfi\nx2=%.6lf-%.6lfi\n",h,j,k,l);  
    else if (d<0&&a!=0&&b==0) f=e/(2*a),g=-e/(2*a),printf("x1=%.6lfi\nx2=%.6lfi\n",f,g);  
    return 0;          
} 

