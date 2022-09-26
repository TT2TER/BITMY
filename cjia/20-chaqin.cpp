#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    long int n, m;
    scanf("%ld %ld", &n, &m);
    stack<long int> box[100010];
    for (long int i = 0; i < n; i++) 
    {
        while (box[i].empty())
        {
            box[i].push(i);
        }
    }
    for (long int i = 0; i < m; i++)
    {
        long int f, t; // from,to
        scanf("%ld %ld", &f, &t);
        while (!box[f].empty())
        {
            box[t].push(box[f].top());
            box[f].pop();
        }
    }
    for (long int i = 0; i < n; i++)
    {
        long int num = box[i].size();
        if (num)
        {
            printf("%ld ",num);
            for (long int j = 0; j < num - 1; j++)
            {
                printf("%ld ",box[i].top());
                box[i].pop();
            }
            printf("%ld\n",box[i].top());
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
