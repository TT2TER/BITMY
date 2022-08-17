#include <stdio.h>
#include <string.h>
int all_no=0;
void reverse(char *a)
{
    // reverse
    int len = strlen(a);
    char temp;
    for (int i = 0; i < len / 2; i++)
    {
        temp = a[i];
        a[i] = a[len - i - 1];
        a[len - i - 1] = temp;
    }
}

void add(char *ans, char *a, char *b, int l)
{
    int len1 = strlen(a);
    int len2 = strlen(b);
    int position = 0, next = 0;
    while (position < l)
    {
        int sum = a[position] + b[position] + next - 2 * '0';
        ans[position] = sum % 10 + '0';
        next = sum / 10;
        position++;
    }
    ans[position] = '.';
    position++;
    while (position < len1 && position < len2)
    {
        int sum = a[position] + b[position] + next - 2 * '0';
        ans[position] = sum % 10 + '0';
        next = sum / 10;
        position++;
    }
    while (position >= len1 && position < len2)
    {
        int sum = +b[position] + next - '0';
        ans[position] = sum % 10 + '0';
        next = sum / 10;
        position++;
    }
    while (position < len1 && position >= len2)
    {
        int sum = +a[position] + next - '0';
        ans[position] = sum % 10 + '0';
        next = sum / 10;
        position++;
    }
    if (next != 0)
    {
        ans[position] = '1';
        position++;
    }
    ans[position] = '\0';
}
int check_num(char a[])
{
    int i = 0, flag = 0, num = 0;
    while (a[i] != '\0')
    {
        if (flag)
        {
            num++;
        }
        if (a[i] == '.')
        {
            flag = 1;
        }
        i++;
    }
    return num;
}
int add_zero(char *a, char *b)
{
    int len1 = 0, len2 = 0, ret = 0;
    len1 = check_num(a);
    len2 = check_num(b);
    // printf("%d %d",len1,len2);
    int len10 = strlen(a), len20 = strlen(b);
    if (len1 > len2)
    {
        int i;
        for (i = 0; i < len1 - len2; i++)
        {
            b[len20 + i] = '0';
        }
        b[len20 + i] = '\0';
        ret = len1;
    }
    if (len1 <= len2)
    {
        int i;
        for (i = 0; i < len2 - len1; i++)
        {
            a[len10 + i] = '0';
        }
        a[len10 + i] = '\0';
        ret = len2;
    }
    return ret;
}
int has_point(char*a)
{int i=0,ret=0;
    while(a[i]!='\0')
    {
        if(a[i]=='.')
        {
            ret=1;
        }
        i++;
    }
    return ret;
}
void add_space(char *a, char *b)
{
    int len1 = 0, len2 = 0, ret = 0;
    if(!has_point(a)&&all_no!=2)
    {
        int i=0;
    while(a[i]!='\0'){
        i++;
    }
    a[i]=' ';
    }
    if(!has_point(b)&&all_no!=2)
    {
        int i=0;
    while(b[i]!='\0'){
        i++;
    }
    b[i]=' ';
    }
    len1 = check_num(a);
    len2 = check_num(b);
    // printf("%d %d",len1,len2);
    int len10 = strlen(a), len20 = strlen(b);
    if (len1 > len2)
    {
        int i;
        for (i = 0; i < len1 - len2; i++)
        {
            b[len20 + i] = ' ';
        }
        b[len20 + i] = '\0';
        ret = len1;
    }
    if (len1 <= len2)
    {
        int i;
        for (i = 0; i < len2 - len1; i++)
        {
            a[len10 + i] = ' ';
        }
        a[len10 + i] = '\0';
    }
}

int main()
{
    char a[2005], b[2005], a0[2005], b0[2005], ans[2010];
    scanf("%s %s", a, b);
    strcpy(a0, a);
    strcpy(b0, b);
    if(!has_point(a))
    {
        int p=strlen(a);
        a[p]='.';
        a[p+1]='\0';
        all_no++;
    }
    if(!has_point(b))
    {
        int p=strlen(b);
        b[p]='.';
        b[p+1]='\0';
        all_no++;
    }
    int decimal = add_zero(a, b);
    add_space(a0,b0);
    reverse(a);
    reverse(b);
    add(ans, a, b, decimal);
    reverse(a);
    reverse(b);
    reverse(ans);
    int i=0,num=0,j=0;
    while(ans[i]!='\0')
    {
        if(ans[i]=='.'&&ans[i+1]=='\0')
        ans[i]='\0';
        i++;
    }
    int len_ans=strlen(ans),len_a0=strlen(a0),len_b0=strlen(b0);
    int len_all=0;
    i=0;
    while(ans[i]=='0'&&ans[i+1]!='.')
    {
        num++;i++;
    }
    len_ans=len_ans-num;
    //判断总长度
    if(len_ans>=len_a0&&len_ans>=len_b0)
    {
        len_all=len_ans+3;
    }
    else if(len_a0>=len_ans&&len_a0>=len_b0)
    {
        len_all=len_a0+3;
    }
    else
    {
        len_all=len_b0+3;
    }
    //打印a
    for(j=0;j<len_all-len_a0;j++)
    {
        printf(" ");
    }
    j=0;
    while(a0[j]!='\0')
    {
        printf("%c",a0[j]);
        j++;
    }
    printf("\n");
    //打印b
    printf("+");
    for(j=0;j<len_all-len_b0-1;j++)
    {
        printf(" ");
    }
    j=0;
    while(b0[j]!='\0')
    {
        printf("%c",b0[j]);
        j++;
    }
    printf("\n");
    //打印横线
    for(j=0;j<len_all;j++)
    {
        printf("-");
    }
    printf("\n");
    //打印结果
    for(j=0;j<len_all-len_ans;j++)
    {
        printf(" ");
    }
    j=num;
    while(ans[j]!='\0')
    {
        printf("%c",ans[j]);
        j++;
    }
    printf("\n");
}