#include <stdio.h>

int countsub(char *str, char *ss);
//TODO:caution！ss or subs!!!
int main()
{
    char s1[1000] = {0}, s2[100] = {0};
    gets(s1);
    gets(s2);
    printf("%d\n", countsub(s1, s2));
    return 0;
}
int countsub(char *str, char *ss)
{
    int i,j;
    for (i=0;str[i]!='\0';i++);
    for (j=0;ss[j]!='\0';j++);
    int m=0,n;
    int sum=0,cnt=0;
    int ret=0;
    while (m<=i-j)
    {
        for(n=0;n<j;n++)
        {
            if(str[m+n]==ss[n])
            {
                cnt++;
            }
            else if(str[m+n]!=ss[n])
            break;
        }
        if(cnt==j)sum++,m+=j;
        else 
        {
            ret=sum>=ret?sum:ret;
            sum=0;
            m+=1;
        }
        cnt=0;
    }
    ret=sum>=ret?sum:ret;
    return ret;
}