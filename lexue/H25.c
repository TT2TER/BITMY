#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *n, int a, int b) //数组，待交换函数的角标
{
    int temp;
    temp = n[a];
    n[a] = n[b];
    n[b] = temp;
}
void ISort(int *a, int len)
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
// 3路快排递归，递归和排序要写在一起了，可以用结构体或者数组指针，之后再包装成函数吧
void QuickSort3(int *a, int begin, int end)
{
    //*优化，随机锚点
    time_t t;
    /* 初始化随机数发生器 */
    srand((unsigned)time(&t));
    int ran = rand() % (end - begin) + begin;
    swap(a, begin, ran);
    //*
    int Index = begin; //标定量度
    int i = begin + 1; //从下标1开始遍历；
    int lt = begin;    // less than部分的最后一个元素
    int gt = end;      // great than 部分的第一个元素的前一个元素，避免数组越界所以设定为首元素的前一个元素下标
    while (i <= gt)    //判断条件，当i与greater than部分第一个元素重合时停止搜索，也即若gt中元素为零，那么i刚越界时就不进入循环
    {
        if (a[i] == a[Index]) //当相等时直接向后一位
        {
            i++;
            continue; //每次都跳出循环判断准入条件
        }
        if (a[i] < a[Index]) //小于时交换相等集合的第一个元素和i，i集合整体后错一位，i++,lt集合增加一位，lt++
        {
            swap(a, i, lt + 1);
            i++;
            lt++;
            continue;
        }
        if (a[i] > a[Index]) //大于时交换i和gt指向的元素
        {
            swap(a, i, gt);
            gt--;
        }
    }
    swap(a, begin, lt); //将lt集合中最后的元素和Index交换
    lt--;               //交换完成后lt集合向前错一位
    /*
    //三目运算符用来判断是不是至少有一个元素，防止随机化出问题
    begin<lt?QuickSort3(a,begin,lt):1;
    gt+1<end?QuickSort3(a,gt+1,end):1;
    */
    //三目运算符判断是不是用Isort
    lt - begin >= 10 ? QuickSort3(a, begin, lt) : ISort(&a[begin], lt - begin + 1);
    end - gt - 1 >= 10 ? QuickSort3(a, gt + 1, end) : ISort(&a[gt + 1], end - gt);
}
int main()
{
    int n, pr, arr[1010];
    scanf("%d %d", &n, &pr);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    QuickSort3(arr, 0, n - 1);
    int left = n;
    int allsmaller = 0;
    for (int i = 0; i < n; i++)
    {
        if (pr <= arr[i])
        {
            arr[i] = -1;
            pr += 2;
            left--;
        }
    }
    pr+=left;
    printf("%d\n",pr);
    return 0;
}