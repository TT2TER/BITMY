#include <stdio.h>

//双指针法
//交换函数
void swap(int *n, int a, int b) //数组，待交换函数的角标
{
    int temp;
    temp = n[a];
    n[a] = n[b];
    n[b] = temp;
}

//确定锚点位置顺便分好锚点左右大小
int partition(int *a, int begin, int end)
{
    int Index = begin; //标定量度
    //先让end走，end先移到和begin重合，再交换，这时while循环外面的swap才是一个比Index小的数和Index交换。
    //如果Index在后面，那就begin开始动
    //这样也成功解决了第一个数就是最小的的情况
    while (begin < end) //如果要左小右大改一下下面两个while的大于小于号即可
    {
        while (begin < end && a[end] >= a[Index]) //挑选右边小的放在左边
            end--;
        while (begin < end && a[begin] <= a[Index]) //挑选左边小的放在右边
            begin++;
        swap(a, begin, end); //交换招待的两个符合要求的数的位置或者重合时自己交换自己
    }
    swap(a, end, Index); //把锚点换到最终位置，再也不动
    return begin;        //begin==right
}

//快排递归
void QuickSort(int *a, int begin, int end)
{

    if (begin < end) //这样区间内至少有两个元素
    {
        int pivot = partition(a, begin, end);
        QuickSort(a, begin, pivot - 1);
        QuickSort(a, pivot + 1, end); //递归，而且不再动锚点
    }
}

int main()
{
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8}; //数组接口
    const int begin = 0;
    int end = 7; //最大长度，最后一个元素下标
    QuickSort(a, begin, end);
    return 0;
}