#include <stdio.h>
#include <string.h>

int ispalind(char s[], int left, int right); //left:开始下标，right：结束下标

int main()
{
    char a[100];
    int left, right;

    gets(a);
    left = 0;
    right = strlen(a) - 1;
    if (ispalind(a, left, right))
        printf("Yes\n");
    else
        printf("No\n");
}
int ispalind(char s[], int left, int right) //left:开始下标，right：结束下标
{
    int ret = 0;
    if (s[left] == s[right])
        ret = left >= right ? 1 : ispalind(s, ++left, --right);
    if (s[left] != s[right])
        ret = 0;
    return ret;
}