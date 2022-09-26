#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    queue<string> name;
    int n;
    cin>>n;
    while (n--)
    {
        string h;
        cin >> h;
        if (h[0] == 'A')
        {
            string c;
            cin >> c;
            name.push(c);
        }
        else if (h[0] == 'L')
        {
            if (name.empty())
                continue;
            else
                name.pop();
        }
        else if (h[5] == 'H') 
        {
            if (name.empty())
            {
                cout<<"Empty queue"<<endl;
            }
            else
            {
                cout << name.front()<<endl;
            }
        }
        else if (h[5] == 'T')
        {
            if (name.empty())
            {
                cout<<"Empty queue"<<endl;
            }
            else
                cout << name.back()<<endl;
        }
    }
    return 0;
}