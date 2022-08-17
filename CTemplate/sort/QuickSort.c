#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    //*优化，随机锚点
    time_t t;
    /* 初始化随机数发生器 */
    srand((unsigned)time(&t));
    int ran = rand() % (end - begin) + begin;
    swap(a, begin, ran);
    //*
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

int judge(int l, int r)
{
    if (r - l < 10)
        return 1;
    else
        return 0;
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

//双路快排递归
void QuickSort2(int *a, int begin, int end)
{

    if (begin < end) //这样区间内至少有两个元素
    {

        if (judge(begin, end))//区间范围很小时可用插入排序，提速，减少递归层数；
        {
            ISort(&a[begin],end-begin+1);
        } 
        else
        {
            int pivot = partition(a, begin, end);
            QuickSort2(a, begin, pivot - 1);
            QuickSort2(a, pivot + 1, end); //递归，而且不再动刚刚的锚点
        }
    }
}

//3路快排递归，递归和排序要写在一起了，可以用结构体或者数组指针，之后再包装成函数吧
void QuickSort3(int *a,int begin,int end)
{
    //*优化，随机锚点
    time_t t;
    /* 初始化随机数发生器 */
    srand((unsigned)time(&t));
    int ran = rand() % (end - begin) + begin;
    swap(a, begin, ran);
    //*
    int Index = begin; //标定量度
    int i=begin+1;//从下标1开始遍历；
    int lt=begin;//less than部分的最后一个元素
    int gt=end;//great than 部分的第一个元素的前一个元素，避免数组越界所以设定为首元素的前一个元素下标
    while(i<=gt)//判断条件，当i与greater than部分第一个元素重合时停止搜索，也即若gt中元素为零，那么i刚越界时就不进入循环
    {
        if(a[i]==a[Index])//当相等时直接向后一位
        {
            i++;
            continue;//每次都跳出循环判断准入条件
        }
        if(a[i]<a[Index])//小于时交换相等集合的第一个元素和i，i集合整体后错一位，i++,lt集合增加一位，lt++
        {
            swap(a,i,lt+1);
            i++;
            lt++;
            continue;
        }
        if(a[i]>a[Index])//大于时交换i和gt指向的元素
        {
            swap(a,i,gt);
            gt--;
        }
    }
    swap(a,begin,lt);//将lt集合中最后的元素和Index交换
    lt--;//交换完成后lt集合向前错一位
    /*
    //三目运算符用来判断是不是至少有一个元素，防止随机化出问题
    begin<lt?QuickSort3(a,begin,lt):1;
    gt+1<end?QuickSort3(a,gt+1,end):1;
    */
    //三目运算符判断是不是用Isort
    lt-begin>=10?QuickSort3(a,begin,lt):ISort(&a[begin],lt-begin+1);
    end-gt-1>=10?QuickSort3(a,gt+1,end):ISort(&a[gt+1],end-gt);
}

int main()
{
    int a[8] = {7, 6, 7, 4, 5, 2, 7, 8}; //数组接口
    const int begin = 0;
    int end = 7; //最大长度，最后一个元素下标
    //QuickSort2(a, begin, end);
    QuickSort3(a,begin,end);
    return 0;
}