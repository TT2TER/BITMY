#include <stdio.h>
int main()
{
    int h;
    char c;
    scanf("%d %c", &h, &c);
    const int H = h;
    char ch[2 * H];
    if ('a' <= c && c <= 'z')
    {
        for (int i = 1; i <= 2 * H - 1; i++)
        {
            ch[i] = c;
            c = c == 'z' ? 'a' : c + 1;
        }
        for (int i = 1; i <= H; i++)
        {
            for (int j = 1; j < i; j++)
            {
                printf(" ");
            }
            printf("%c", ch[i]);

            for (int j = 1; j <= 2 * (H - i) - 1; j++)
                printf(" ");
            if (i != H)
                printf("%c", ch[2 * H - i]);
            printf("\n");
            // printf("%c",ch[i]);
            // printf("%c",ch[2*H-i]);
        }
    }
    if ('A' <= c && c <= 'Z')
    {
        for (int i = 1; i <= 2 * H - 1; i++)
        {
            ch[i] = c;
            c = c == 'Z' ? 'A' : c + 1;
        }
        for (int i = 1; i <= H; i++)
        {
            for (int j = 1; j < i; j++)
            {
                printf(" ");
            }
            printf("%c", ch[i]);

            for (int j = 1; j <= 2 * (H - i) - 1; j++)
                printf(" ");
            if (i != H)
                printf("%c", ch[2 * H - i]);
            printf("\n");
            // printf("%c",ch[i]);
            // printf("%c",ch[2*H-i]);
        }
    }
    
    return 0;
}
