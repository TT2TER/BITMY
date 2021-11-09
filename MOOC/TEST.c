#include <stdio.h>
#include <string.h>
int main()
{
    int n, m, i, j, b, c;
    char d[200][200];//
    char *s[200];
    for (i = 1; i <=200; i++)
        s[i] = d[i];

    scanf("%d%d ", &n, &m);
    for (i = 1; i <= n; i++)
    {
        gets(d[i]);
    }
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d ", &b, &c);
        char *x;
        x = s[b];
        s[b] = s[c];
        s[c] = x;
    }
    for (i = 1; i <= n; i++)
    {
        puts(s[i]);
    }
    return 0;
}
