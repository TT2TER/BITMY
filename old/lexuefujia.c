#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("1.in","r",stdin);
    int l=0,w=0,c=0;
    char ch; 
    int num=0,check=0;
    char com=' ';
    while((ch=getchar())!=EOF)
    {   c++;
        if(ch=='\n')l++;
        if(('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z')||ch=='\t'||ch=='\n'||ch==' ');
        else num=1;
        if('0'<=ch&&ch<='9'||ch=='-'||ch=='.'||ch=='\''||ch=='!'||ch==',')check=1;
        if((ch=='\t'||ch=='\n'||ch==' ')&&(num!=1||check!=1))
        {
            if(com==' '||com=='\n'||com=='\t')num=0;
            else
            {
                w++;
                num=0;
            }
            
        }
        if(((ch=='\t')||(ch=='\n')||(ch==' '))&&(check==1))
        {
            check=0;
        } 
        com=ch;
    }
    printf("Lines:%d\nWords:%d\nChars:%d\n",l,w,c);
    return 0;
}