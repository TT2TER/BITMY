#include<stdio.h>
#include<string.h>
int main()
{
    char ch[5000];
    gets(ch);
    int len=strlen(ch);
    int flag=0;
    int start=0;
    int end=0;
    int ansstart,ansend;
    int maxlen=0;
    for(int i=0;i<len;i++)
    {
        if(flag==0)
        start=end;
        if(ch[i]+1==ch[i+1])
        {
            end++;
            flag=1;
        }
        else
        {
            if(end-start>maxlen)
            {
                maxlen=end-start;
                ansstart=start;
                ansend=end;
            }
            flag=0;
            end++;
        }
    }
    for(int i=ansstart;i<=ansend;i++)
    {
        printf("%c",ch[i]);
    }
    printf("\n");
    return 0;
}