#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main()
{
    queue<char *> name;
    char c[22], h[33];
    int n;
    scanf("%d\n", &n);
    while (n--)
    {
        gets(h);
        if (memcmp(h, "Arrive", 6) == 0)
        {
            strcpy(c, &h[7]);
            name.push(c);
            continue;
        }
        else if (memcmp(h, "Leave", 5) == 0)
        {
            if (name.empty())
                ;
            else
                name.pop();
            continue;
        }
        else if (memcmp(h, "QueueHead", 9) == 0)
        {
            if (name.empty())
            {
                printf("Empty queue\n");
            }
            else
            {
                puts(name.front());
            }
            continue;
        }
        else if (memcmp(h, "QueueTail", 9) == 0)
        {
            if (name.empty())
            {
                printf("Empty queue\n");
            }
            else
                puts(name.back());
            continue;
        }
    }
}