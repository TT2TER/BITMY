#include <stdio.h>

void InsertionSortBase(int *a, int len)
{
    for (int i = 1; i < len; i++) //第0号元素默认为有序排列，故从第一号元素开始
    {
        int j = i;
        if (a[j] < a[j - 1]) //结果前小后大
        {
            int Index = a[j];
            while (j > 0 && Index < a[j - 1])
            {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = Index;
        }
    }
}

int main()
{
    int a[8] = {1, 2, 3, 9, 5, 6, 7, 8}; //数组接口
    int len = 8;                         //最大长度，最后一个元素下标
    InsertionSortBase(a, len);
    return 0;
}