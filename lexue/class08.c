#include<stdio.h>
typedef struct s
{
    float weight;
    float value;
} take;
int main()
{
    take arr[3];
    for(int i=0;i<3;i++)
    {
        scanf("%f",&arr[i].weight);
    }
    for(int i=0;i<3;i++)
    {
        scanf("%f",&arr[i].value);
    }
    if(arr[1].weight+arr[2].weight+arr[0].weight<=10)
    {
        printf("MaxValue=%.1f\n",arr[1].value+arr[2].value+arr[0].value);
        return 0;
    }
    float max=0;
    if(arr[0].weight+arr[1].weight<=10)
    {
        max=max<arr[0].value+arr[1].value?arr[0].value+arr[1].value:max;
    }
    if(arr[1].weight+arr[2].weight<=10)
    {
        max=max<arr[1].value+arr[2].value?arr[1].value+arr[2].value:max;
    }
    if(arr[0].weight+arr[2].weight<=10)
    {
        max=max<arr[0].value+arr[2].value?arr[0].value+arr[2].value:max;
    }
    if(arr[0].weight<=10)
    {
        max=max<arr[0].value?arr[0].value:max;
    }
    if(arr[1].weight<=10)
    {
        max=max<arr[1].value?arr[1].value:max;
    }
    if(arr[2].weight<=10)
    {
        max=max<arr[2].value?arr[2].value:max;
    }
    printf("MaxValue=%.1f\n",max);
    return 0;

}