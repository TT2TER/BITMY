#include <stdio.h>
#define q 1900
int judge(int days)
{
    int ret = 0;
    if (days % 7 == 5)
        ret = 1;
    return ret;
}
int main()
{
    int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, i = 0, run = 0, runy = 0;
    int flag = 0;
    int mon[13];
    scanf("%d", &year);
    for (i = q; i < year; i++)
    {
        if ((i % 400 == 0) || ((i % 100 != 0) && (i % 4 == 0)))
            run += 1;
    }
    int days = (year - q) * 365 + run;
    if ((i % 400 == 0) || ((i % 100 != 0) && (i % 4 == 0)))
        runy += 1;
    days += 13;
    if (judge(days))
    {
        flag++;
        mon[flag] = 1;
    }
    for (i = 1; i <= 11; i++)
    {
        if (i == 2)
            days += m[2] + runy;
        else
            days += m[i];
        if (judge(days))
        {
            flag++;
            mon[flag] = i+1;
        }
    }
    if(flag==0);//printf("There are 0 Black Fridays in year 2006.\n");
    else
    {
        if(flag!=1)
        {
            printf("There are %d Black Fridays in year %d.\nThey are:\n",flag,year);
        for(i=1;i<=flag;i++)
        printf("%d/%d/13\n",year,mon[i]);
        }
        if(flag==1)
        {
            printf("There is %d Black Friday in year %d.\nIt is:\n",flag,year);
        for(i=1;i<=flag;i++)
        printf("%d/%d/13\n",year,mon[i]);
        }
        
    }
    return 0;
}