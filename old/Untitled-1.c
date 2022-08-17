#include <stdio.h>
int C(float x, float t)
{
    float i, pl = 1, m = t;
    for (i = x; i >= x - m + 1; i--, t--)
    {
        pl *= i / t;
    }
    return pl;
}
int main()
{
    char arr[10][26] = {'a'};
    int n, i, j, len[10], count[10] = {0}, sum[12][30] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
        len[i] = strlen(arr[i]);
    }
    for (i = 1; i <= 26; i++)
        sum[0][i] = i;
    for (i = 1; i <= 10; i++)
    {
        sum[i][1] = sum[i - 1][25];
        for (j = 2; j <= 27 - i; j++)
        {
            sum[i][j] = sum[i][j - 1] + C(26 - j, i);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = len[i] - 2; j >= 0; j--)
        {
            count[i] += sum[j][26 - j];
        }
        for (j = len[i] - 1; j >= 0; j--)
        {
            if (j == len[i] - 1)
                count[i] += arr[i][j] - arr[i][j - 1];
            else if (j == 0)
                count[i] += sum[len[i] - j - 1][arr[i][j] - 'a'];
            else
                count[i] += sum[len[i] - j - 1][arr[i][j] - arr[i][j - 1] - 1];
        }
    }
    printf("%d", count[0]);
    return 0;
}