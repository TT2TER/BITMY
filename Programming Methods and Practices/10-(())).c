#include <stdio.h>
#include <string.h>
long long int l[100010], r[100010];
char cur[100010];
int main()
{
    long long int t;
    scanf("%lld\n", &t);
    while (t--)
    {
        gets(cur);
        long long int len = strlen(cur);
        long long int left = 0, right = 0;
        long long int from_left = 0, from_right = 0;
        for (long long int j = 0; j < len; j++)
        {
            if (cur[j] == '(')
            {
                from_left++;
            }
            if (cur[j] == ')')
            {
                from_left--;
            }

            if (from_left < 0)
            {
                break;
            }
        }
        for (long long int j = len - 1; j >= 0; j--)
        {
            if (cur[j] == '(')
            {
                from_right--;
            }

            if (cur[j] == ')')
            {
                from_right++;
            }

            if (from_right < 0)
            {
                break;
            }
        }
        if (from_left < 0 && from_right < 0)
        {
            continue;
        }
        else
        {
            for (long long int i = 0; i < len; i++)
            {
                if (cur[i] == ')')
                {
                    left++;
                }
                else if (cur[i] == '(')
                {
                    right++;
                }
            }
            if (left >= right)
            {
                long long int temp = left - right;
                l[temp]++;
            }
            else if (right > left)
            {
                long long int temp = right - left;
                r[temp]++;
            }
        }
    }
    long long int sum = 0;
    for (int i = 0; i < 100010; i++)
    {

        if (l[i] <= r[i])
        {
            sum += l[i];
        }
        else
        {
            sum += r[i];
        }
    }
    sum += l[0] / 2;
    printf("%lld\n", sum);
}