#include <stdio.h>
#include<string.h>
typedef struct key
{
    char x;
    char y;
} k;
int main()
{
    k a[9] = {{'a', 'd'},
              {'b', 'w'},
              {'c', 'k'},
              {'d', ';'},
              {'e', 'i'},
              {'i', 'a'},
              {'k', 'b'},
              {';', 'c'},
              {'w', 'e'}};
    int i,j;
    char c[20]="\0";
    gets(c);
    int len=strlen(c);
    for(i=0;i<len;i++)
    {
        for(j=0;;j++)
        {
            if(c[i]==a[j].x)
            {
                printf("%c",a[j].y);
                break;
            }
            if(j==8)
            {
                printf("%c",c[i]);
                break;
            }
        }
    }
    printf("\n");
    return 0;
}