#include <stdio.h>
#include <ctype.h>
char temp[1000];
int main()
{
    // freopen("1.out","w",stdout);
    int i = 1;
    int len = 0;
    int need_top = 1, need_space = 0;
    while ((temp[i] = getchar()) != EOF)
    {
        if (!isalpha(temp[i]) && !isalpha(temp[i - 1]))
        {
            printf("%c", temp[i]), i = 0;
            if (temp[i] == '.' || temp[i] == '?' || temp[i] == '!')
            {
                need_top = 1;
            }
        }

        if (!isalpha(temp[i]) && isalpha(temp[i - 1]))
        {
            len = i;
            if (need_top)
            {
                temp[1] = toupper(temp[1]);
                for (int j = 2; j <= len; j++)
                {
                    temp[j] = tolower(temp[j]);
                }
                need_top = 0;
                i = 0;
                if (temp[len] == '.' || temp[len] == '?' || temp[len] == '!')
                {
                    need_top = 1;
                }
            }
            else
            {
                for (int j = 1; j <= len; j++)
                {
                    temp[j] = tolower(temp[j]);
                }
                if (temp[len] == '.' || temp[len] == '?' || temp[len] == '!')
                {
                    need_top = 1;
                }
                i=0;
            }
            if (need_space)
                ;
            for (int j = 1; j <= len; j++)
            {
                printf("%c", temp[j]);
            }
        }
        i++;
    }
    return 0;
}