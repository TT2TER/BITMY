#include <stdio.h>
#include <string.h>
#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
    if(a == 0) return b;
    if(b == 0) return a;
    if(a % 2 == 0 && b % 2 == 0) return 2 * gcd(a >> 1, b >> 1);
    else if(a % 2 == 0)  return gcd(a >> 1, b);
    else if(b % 2 == 0) return gcd(a, b >> 1);
    else return gcd(abs(a - b), min(a, b));
}
int arr[10000][10];
int l = 0;
// int gcd(int a, int b)
// {
//     return a % b ? gcd(b, a % b) : b;
// }
int m, n, gcd1, gcd2, gcd3, i, sum, ans = 0, s, t, p;
int main(void)
{

    scanf("%d", &m);
    for (s = 0; s < m; s++)
    {
        sum = 3;
        ans = 0;
        scanf("%d", &n);
        if (n % 3 == 0)
        {
            printf("%lld %lld %lld\n", n / 3, n / 3, n / 3);
            continue;
        }
        else
        {
            for (int j = n / 3; j < n / 2; j++)
            {
                int i = n - 2 * j;
                p = 2 * gcd(i, j) + j;
                if (p >= sum)
                {
                    //            printf("sum:%d ",sum);
                    sum = p;
                    t = j;
                }
            }
            printf("%lld %lld %lld\n", n - 2 * t, t, t);
        }
    }

    return 0;
}
#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
    if(a == 0) return b;
    if(b == 0) return a;
    if(a % 2 == 0 && b % 2 == 0) return 2 * gcd(a >> 1, b >> 1);
    else if(a % 2 == 0)  return gcd(a >> 1, b);
    else if(b % 2 == 0) return gcd(a, b >> 1);
    else return gcd(abs(a - b), min(a, b));
}