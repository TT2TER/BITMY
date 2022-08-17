/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int gettoken(char s[]);
int ati(char s[]);
void ita(int n, char s[]);

int main()
{
    char a[100], c;
    char b[100];
    int res, n;

    while ((res = gettoken(a)) != EOF)
    {
        if (res == 0)
        {
            n = ati(a);
            ita(n, b);
            puts(b);
        }
    }
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
int gettoken(char s[])
{
    int i = 0;
    int allnum = 1;
    int onlyspace = 1;
    memset(s, 0, sizeof(s));
    do
    {
        if ((s[i] = getchar()) == EOF)
        {
            break;
        }
        if (isspace(s[i]))
        {
            s[i] = '\0';
            break;
        }
        else
            onlyspace = 0;
        if (!isdigit(s[i]))
        {
            allnum = 0;
        }
        i++;
    } while (s[i-1] != EOF);
    if (s[i] == EOF && onlyspace == 1)
    {
        return EOF;
    }
    if (allnum == 1 && onlyspace == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int ati(char s[])
{
    int num = 0, cnt = 0;
    while (s[cnt] != '\0')
    {
        num = num * 10 + s[cnt] - '0';
        cnt++;
    }
    return num;
}
void ita(int n, char s[])
{
    memset(s, 0, sizeof(s));
    int cnt = 0, i, temp;
    while (n)
    {
        s[cnt++] = n % 10 + '0';
        n /= 10;
    }
    for (i = 0; i < (cnt + 1) / 2; i++)
    {
        temp = s[i];
        s[i] = s[cnt - i - 1];
        s[cnt - i - 1] = temp;
    }
}