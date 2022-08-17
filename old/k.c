#include <stdio.h>
#include <string.h>
long long  arr[10000][10];
long long l = 0;
long long gcd(long long a, long long b)
{
    return a % b ? gcd(b, a % b) : b;
}
long long function(long long n)
{
    long long i, j, k;
    for (i = 1; i < n - 1; i++)
    {
        for (j = i; j <= (n - i) / 2; j++)
        {
            k = n - i - j;
            arr[l][0] = i;
            arr[l][1] = j;
            arr[l][2] = k;
            l++;
        }
    }
    long long a=l;
    l=0;
    return a - 1;
}

int main(void)
{
    long long m, n, gcd1, gcd2, gcd3, i, sum = 3, ans = 0, s;
    scanf("%lld", &m);
    for (s = 0; s < m; s++)
    {
        sum=3;ans=0;
        scanf("%lld", &n);
        long long L = function(n);
        for (i = 0; i < L + 1; i++)
        {
            gcd1 = gcd(arr[i][0], arr[i][1]);
            gcd2 = gcd(arr[i][0], arr[i][2]);
            gcd3 = gcd(arr[i][2], arr[i][1]);
            if ((gcd1 + gcd2 + gcd3) >= sum)
            {
                sum = gcd1 + gcd2 + gcd3;
                ans = i;
            }
        }
        printf("%lld %lld %lld\n", arr[ans][0], arr[ans][1], arr[ans][2]);
    }

    return 0;
}