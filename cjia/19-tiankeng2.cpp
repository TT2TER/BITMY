#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    long int a;
    while (scanf("%ld", &a) != EOF)
    {
        stack<long long int> left;
        long long int cur;
        long long int max = 0;
        int ji = 0;
        while (a--)
        {

            scanf("%lld", &cur);
            if (cur > max)
                max = cur;
            if (left.empty() || cur < left.top())
            {
                left.push(cur);
            }
            else if (cur == left.top())
            {
                left.pop();
            }
            else
            {
                ji = 1;
            }
        }
        if(ji);
        else if(left.size()==0)
        {
            ji=0;
        }
        else if(left.size()==1)
        {
            if(left.top()>=max)
            {
                ji=0;
            }
            else ji=1;
        }
        else ji=1;

        if(ji)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
}