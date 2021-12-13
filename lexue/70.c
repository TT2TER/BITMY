#include <stdio.h>
void print(int a)
{
    switch (a)
    {
    case 0:
        printf("7D");
        break;
    case 1:
        printf("50");
        break;
    case 2:
        printf("37");
        break;
    case 3:
        printf("57");
        break;
    case 4:
        printf("5A");
        break;
    case 5:
        printf("4F");
        break;
    case 6:
        printf("6F");
        break;
    case 7:
        printf("54");
        break;
    case 8:
        printf("7F");
        break;
    case 9:
        printf("5F");
        break;
    }
}
int main()
{
    int a;
    while (1)
    {
        scanf("%d", &a);
        if (a == 0)
            break;
        else
        {
            print(a/10000);
            printf(" ");
            a%=10000;
            print(a/1000);printf(" ");
            a%=1000;
            print(a/100);printf(" ");
            a%=100;
            print(a/10);printf(" ");
            a%=10;
            print(a);printf("\n");
        }
    }
    return 0;
}