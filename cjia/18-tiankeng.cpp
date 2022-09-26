#include <iostream>
#include <stack>
#include <cstring>
#include<cstdio>
using namespace std;

int main()
{
    long int n;
    while (scanf("%ld", &n) != EOF)
    { 
        stack<long long int> left;
        while (n--)
        {
            long long int cur;
            scanf("%lld", &cur);
            if (left.empty())
            {
                left.push(cur);
            }
            else if (cur % 2 == left.top() % 2)
            {
                left.pop();
            }
            else
            {
                left.push(cur);
            }
        }
        if(left.size()<=1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}