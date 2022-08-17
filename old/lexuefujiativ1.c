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
                                        for(j=0;j<=plen;j++)
                                            {
                                                printf("sys[%d]:%d num[%d]:%d  %d  \n",j,sys[j],j,num[j],ret);
                                            }printf("\n");
    //sys[0]=1;num[0]=1;
    //最后一位开始相加
    int y=memcmp(num, sys, sizeof(int)*(plen+1));
    while(memcmp(sys, num, sizeof(int)*(plen+1)))
    {
        if(num[plen]<=26)
        {
            num[plen]++;
            ret++;
                                                for(j=0;j<=plen;j++)
                                            {
                                                printf("sys[%d]:%d num[%d]:%d  %d  \n",j,sys[j],j,num[j],ret);
                                            }printf("\n");
            continue;
        }//把最后一位加到26，每加一次就判断一次大小是不是OK

        num[plen]=26;//确保进位的时候倒数第二位到25进位
                                                for(j=0;j<=plen;j++)
                                            {
                                                printf("sys[%d]:%d num[%d]:%d  %d  \n",j,sys[j],j,num[j],ret);
                                            }printf("\n");
        i=plen;
        while(num[i] && num[i+1]==num[i]+1);
        {
            num[i-1]++;
                                                for(j=0;j<=plen;j++)
                                            {
                                                printf("sys[%d]:%d num[%d]:%d  %d  \n",j,sys[j],j,num[j],ret);
                                            }printf("\n");
            i--;
        }
        

        for(;i<=plen;i++)
        {
            num[i+1]=num[i]+1;
        }
                                                for(j=0;j<=plen;j++)
                                                {
                                                    printf("sys[%d]:%d num[%d]:%d  %d  \n",j,sys[j],j,num[j],ret);
                                                }printf("\n");
        
    }
    exit:
    return ret;
}
int main()
{
    //freopen("2.out","w",stdout);
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