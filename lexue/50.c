#include <stdio.h>
#include <ctype.h>
char temp[81];
char dic[50000];
int posstart[5000];
int len[5000];
int compare(int cnt,int l)
{
    int ret=0;
    for(int i=1;i<=cnt;i++)
    {
        if(l==len[i])
        {
            for(int k=1,j=posstart[i];k<=l;k++,j++)
            {
                if(temp[k]==dic[j])ret=i;
                else 
                {
                    ret=0;
                    break;
                }
            }
            if(ret)break;
        }
    }
    return ret;
}
int main()
{
    //freopen("1.out","w",stdout);
    int cnt = 0;
    int i = 1;
    len[0] = 0;
    posstart[0] = 1;
    while ((temp[i] = getchar())!=EOF)
    {
        if (!isalpha(temp[i]) && !isalpha(temp[i - 1]))
            printf("%c", temp[i]), i = 0;
        if (!isalpha(temp[i]) && isalpha(temp[i - 1]))
        {
            int a = compare(cnt,i-1);
            if(a)
            {
                printf("%d",a);
                printf("%c", temp[i]);
                i=0;
            }
            if (!a)
            {
                cnt++;
                len[cnt] = i - 1;
                posstart[cnt] = len[cnt - 1] + posstart[cnt - 1];
                for (int k = posstart[cnt], j = 1; k < len[cnt] + posstart[cnt]; k++, j++)
                {
                    dic[k] = temp[j];
                }

                for (int k = 1; k < i; k++)
                {
                    printf("%c", temp[k]);
                }
                printf("%c", temp[i]);
                i = 0;
            }
        }
        i++;
    }
    return 0;
}