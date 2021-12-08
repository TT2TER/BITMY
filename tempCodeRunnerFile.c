#include <stdio.h>
#include <string.h>
struct s
{
    char x;
    char y;
};

int main()
{
    struct s
    t[9]={{'a','d'},{'b','w'},{'c','k'},{'d',';'},
    {'e','i'},{'i','a'},{'k','b'},{';','c'},{'w','e'}};
    int i,j;
    char c[20];
    gets(c);
    for(i=0;c[i]!='0';i++)
    {
        for(j=0;;j++)
        {
            if(c[i]==t[j].x)
            {
                printf("%c",t[j].y);break;
            }
            if(j==8)
            {
                printf("%c",c[i]);break;
            }
        }
    }
    return 0;
}

