
#include <stdio.h>
#include <string.h>

int ispalind(char s[], int left, int right) //left:开始下标，right：结束下标
{
    int ret = 0;
    if (s[left] == s[right])
        ret = left >= right ? 1 : ispalind(s, ++left, --right);
    if (s[left] != s[right])
        ret = 0;
    return ret;
}

int main()
{
    char a[100];
    int left, right;
    int d=0;
    int meml=-1,memr=-1;
    gets(a);
    //left = 0;
    int len = strlen(a);
    //right = strlen(a) - 1;
    for (int i = 0; i < len; i++)
    {
        left = i;
        for (int j = 0; j < len; j++)
        {
            right = len - 1 - j;
            if (left < right)
            {
                if (ispalind(a, left, right))
                {
                    if(right-left>d)
                    {
                        d=right-left;
                        meml=left;
                        memr=right;
                    }
                }
                
            }
            if(left>=right)
            {
                break;
            }
        }
    }
    if(meml==-1&&memr==-1)
    printf("No Output");
    else
    {
        for(int k=meml;k<=memr;k++)
        printf("%c",a[k]);
    }
    printf("\n");
    // if (ispalind(a, left, right))
    //     printf("Yes\n");
    // else
    //     printf("No\n");
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */