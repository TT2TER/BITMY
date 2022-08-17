#include <stdio.h>
int value(char *str)
{
    int i, s[32], t[32], end = strlen(str)-1, v = 0;
    // 初始化s, t
    int j;
    int plen=end;
    for(i=0; i<=end; ++i)
    {
        s[i] = str[i] - 'a'+1;
        t[i] = 0;
        for(j=0;j<=plen;j++)
                                            {
                                                printf("sys[%d]:%d num[%d]:%d  %d %d \n",j,s[j],j,t[j],v,end);
                                            }printf("\n");
    }
    // 模拟运算
    while(memcmp(s, t, sizeof(int)*(end+1)))
    {
        // 模拟加一
        t[end]++;
        v++; for(j=0;j<=plen;j++)
                                            {
                                                printf("sys[%d]:%d num[%d]:%d  %d  \n",j,s[j],j,t[j],v);
                                            }printf("\n");
        if(t[end] <= 26)continue;
        // 进位
        t[end] = 26;                            for(j=0;j<=plen;j++)
                                            {
                                                printf("sys[%d]:%d num[%d]:%d  %d  \n",j,s[j],j,t[j],v);
                                            }printf("\n");
        for(i=end; t[i-1] && t[i]==t[i-1]+1; i--);
        t[i-1]++;                               for(j=0;j<=plen;j++)
                                            {
                                                printf("sys[%d]:%d num[%d]:%d  %d %d \n",j,s[j],j,t[j],v,i);
                                            }printf("\n");
        // 修改进位后面的数
        while(i <= end)
        {
            t[i] = t[i-1]+1;
            i++; for(j=0;j<=plen;j++)
                                            {
                                                printf("sys[%d]:%d num[%d]:%d  %d  \n",j,s[j],j,t[j],v);
                                            }printf("\n");
        }
    }
    return v;
}
int main()
{
    printf("%d", value("abc"));
}