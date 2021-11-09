#include <stdio.h>
#include <math.h>
#include <string.h>
char a[100];
int sum(int len, int start)
{
    int s = 0;
    for (int i = 0; i <= len; i++)
    {
        int b = pow(10, len - i);
        s += (a[start + i] - '0') * b;
    }
    int a = s;
    s = 0;
    return a;
}
int main()
{
    gets(a);
    int d = strlen(a);
    int start = 0, end, len, i;
    int max, min;
    int flag = 0;

    for (i = 0; i < d - 3; i++)
    {
        if (i == 0)
        {
            if (a[i] == '-')
                start = 1;
            else
                start = 0;
        }
        if (i != 0)
        {
            if (a[i - 1] == ',' && a[i] == '-')
                start = i + 1;
            else if (a[i - 1] == ',')
                start = i;
        }
        if (a[i + 1] == ',')
        {
            end = i;
            len = end - start;
            int c, b; //c不带正负 b带正负
            c = sum(len, start);
            b = a[start - 1] == '-' ? -c : c;
            if (flag == 0)
            {
                max = min = b;
            }
            else
            {
                if (b > max)
                    max = b;
                if (b < min)
                    min = b;
            }
            flag = 1;
        }
    }
    int ret;
    switch (a[d - 3])
    {
    case '+':
        ret = max + min;
        if (max < 0)
        {
            printf("(%d) + (%d) = %d\n", max, min, ret);
        }
        else if (min < 0)
        {
            printf("%d + (%d) = %d\n", max, min, ret);
        }
        else
            printf("%d + %d = %d\n", max, min, ret);
        break;
    case '-':
        ret = max - min;
        if (max < 0)
        {
            printf("(%d) - (%d) = %d\n", max, min, ret);
        }
        else if (min < 0)
        {
            printf("%d - (%d) = %d\n", max, min, ret);
        }
        else
            printf("%d - %d = %d\n", max, min, ret);
        break;
    case '*':
        ret = max * min;
        if (max < 0)
        {
            printf("(%d) * (%d) = %d\n", max, min, ret);
        }
        else if (min < 0)
        {
            printf("%d * (%d) = %d\n", max, min, ret);
        }
        else
            printf("%d * %d = %d\n", max, min, ret);
        break;
    case '%':
        ret = max % min;
        if (max < 0)
        {
            printf("(%d) % (%d) = %d\n", max, min, ret);
        }
        else if (min < 0)
        {
            printf("%d % (%d) = %d\n", max, min, ret);
        }
        else
            printf("%d % %d = %d\n", max, min, ret);
        break;
    case '/':
        ret = max / min;
        if (max < 0)
        {
            printf("(%d) / (%d) = %d\n", max, min, ret);
        }
        else if (min < 0)
        {
            printf("%d / (%d) = %d\n", max, min, ret);
        }
        else
            printf("%d / %d = %d\n", max, min, ret);
        break;
    }
    //printf("%c",a[d-3]);
    return 0;
}