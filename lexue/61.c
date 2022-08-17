/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int resort(int *pa[], int num);

int main(int argc, char *argv[])
{

    int a[100];
    int num;

    int *pa[100];
    scanf("%d", &num);

    int i = 0;
    for (i = 0; i < num; i++)
    {
        scanf("%d", &a[i]);
        pa[i] = &a[i];
    }

    resort(pa, num);

    for (i = 0; i < num; i++)
    {
        printf("%d\n", *pa[i]);
    }

    return 0;
}
int resort(int *pa[], int num)
{
    int i, j;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num - 1 - i; j++)
        {
            int *temp;
            if (*pa[j] > *pa[j + 1])
            {
                temp = pa[j];
                pa[j] = pa[j + 1];
                pa[j + 1] = temp;
            }
        }
    }
return 0;
}
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */