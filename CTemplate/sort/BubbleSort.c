#include <stdio.h>
void BubbleSort(int *arr, int len) //len就是有多少个数,数组长度
{
    int i, j;
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            int temp;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    BubbleSort(arr, len);
    return 0;
}
