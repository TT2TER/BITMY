#include <stdio.h>
#include <string.h>

int main()
{
    char str1[15];
    char str2[15];
    int ret;

    strcpy(str1, "12");
    strcpy(str2, "2");

    ret = strcmp(str1, str2);

    if (ret < 0)
    {
        printf("str1 С�� str2");
    }
    else if (ret > 0)
    {
        printf("str1 ���� str2");
    }
    else
    {
        printf("str1 ���� str2");
    }

    return (0);
}