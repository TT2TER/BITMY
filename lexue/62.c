/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 4

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int resort(int (*pa)[COL], int row, int col);

int main(int argc, char *argv[])
{

    int a[ROW][COL];
    //    int col;

    int(*pa)[COL];

    int i = 0, j = 0;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
            scanf("%d", &a[i][j]);
    }
    pa = a;

    resort(a, ROW, COL);

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
    return 0;
}
int resort(int (*pa)[COL], int row, int col)
{
    for (int k = 0; k < row; k++)
    {
        int i, j;
        for (i = 0; i < col; i++)
        {
            for (j = 0; j < col - 1 - i; j++)
            {
                int temp;
                if ((*pa)[j] > (*pa)[j + 1])
                {
                    temp = (*pa)[j];
                    (*pa)[j] = (*pa)[j + 1];
                    (*pa)[j + 1] = temp;
                }
            }
        }
        pa++;
    }
    return 0;
}
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */