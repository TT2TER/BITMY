#include<stdio.h>
#include<string.h>
int count(char *ch)
{
    int plen=strlen(ch);//plen是从1-最后一个[]；
    int i,j,ret=0,sys[27]={0},num[27]={0};
    //初始化比较器
    for(i=1;i<=plen;i++)
    {
        sys[i]=ch[i-1]-'a'+1;
        if(sys[i-1]>=sys[i])
        {
            ret =0;
            goto exit;
        }
    }
    //最后一位开始相加
    int y=memcmp(num, sys, sizeof(int)*(plen+1));
    while(memcmp(sys, num, sizeof(int)*(plen+1)))
    {
        if(num[plen]<=26)
        {
            num[plen]++;
            ret++;
            continue;
        }//把最后一位加到26，每加一次就判断一次大小是不是OK
        num[plen]=26;//确保进位的时候倒数第二位到25进位
        i=plen;
        for(i=plen; num[i-1] && num[i]==num[i-1]+1; i--);
        num[i-1]++; //如果前一位没到后一位加一，那么就不要进位，就是后一位给前一位进位，如果到了，就是前一位给再前面一位进位
        //将进位后的后面位数初始化，比前面一个大一；
        for(;i<=plen;i++)
        {
            num[i]=num[i-1]+1;
        }
    }
    exit:
    return ret;
}
int main()
{
    int n;
    scanf("%d\n",&n);
    int y;
    for(y=0;y<n;y++)
    {
        char str[27];
        gets(str);
        printf("%d\n",count(str));
    }
    return 0;
}