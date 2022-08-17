#include <stdio.h>
#include <string.h>
int main()
{
    int guess, high = 11, low = -1;
    char judgement[10];
    while (scanf("%d", &guess))
    {
        if (guess == 0)
            break;
        getchar();
        gets(judgement);
        if (strcmp(judgement, "too high") == 0)
        {
            if (guess < high)
            {
                high = guess;
            }
        }
        else if (strcmp(judgement, "too low") == 0)
        {
            if (guess > low)
            {
                low = guess;
            }
        }
        else if (strcmp(judgement, "right on") == 0)
        {
            if ((guess > low) && (guess < high))
            {
                printf("Tom may be honest\n");
            }
            else
            {
                printf("Tom is dishonest\n");
            }
            high = 11;
            low = -1;
        }
    }
    return 0;
}