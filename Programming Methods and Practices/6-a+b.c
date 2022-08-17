#include <stdio.h>
#include <string.h>
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
void add(char *ans, char *a, char *b)
{
    int len1 = strlen(a);
    int len2 = strlen(b);
    int position = 0, next = 0;
    while (position < len1 && position < len2)
    {
        int sum = a[position] + b[position] + next - 2 * '0';
        ans[position] = sum % 2 + '0';
        next = sum / 2;
        position++;
    }
    while (position >= len1 && position < len2)
    {
        int sum = +b[position] + next - '0';
        ans[position] = sum % 2 + '0';
        next = sum / 2;
        position++;
    }
    while (position < len1 && position >= len2)
    {
        int sum = +a[position] + next - '0';
        ans[position] = sum % 2 + '0';
        next = sum / 2;
        position++;
    }
    if (next != 0)
    {
        ans[position] = '1';
        position++;
    }
    ans[position] = '\0';
}
int main()
{
    int t = 0;
    scanf("%d", &t);
    char a[100002], b[100002], ans[100004];
    for (int i = 0; i < t; i++)
    {

        scanf("%s %s", a, b);
        reverse(a);
        reverse(b);
        add(ans, a, b);
        reverse(a);
        reverse(b);
        reverse(ans);
    int len=strlen(ans)+2;
    int len1=strlen(a);
    int len2=strlen(b);
    for(int i=0;i<len-len1;i++)printf(" ");
    puts(a);
    printf("+");
    for(int i=0;i<len-len2-1;i++)printf(" ");
    puts(b);
    for(int i=0;i<len;i++)printf("-");
    printf("\n");
    for(int i=0;i<2;i++)printf(" ");
    puts(ans);
        //
    }

    return 0;
}