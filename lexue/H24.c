/*ORZ PQ DaShen 你编的题目太啰嗦了DOGE*/
#include <stdio.h>
int num[100000];
//双指针法
//交换函数
void swap(int *n, int a, int b) //数组，待交换函数的角标
{
    int temp;
    temp = n[a];
    n[a] = n[b];
    n[b] = temp;
    temp = num[a];
    num[a] = num[b];
    num[b] = temp;
}

//确定锚点位置顺便分好锚点左右大小
int partition(int *a, int begin, int end)
{
    int Index = begin; //标定量度，左小右大。
    //先让end走，end先移到和begin重合，再交换，这时while循环外面的swap才是一个比Index小的数和Index交换。
    //如果Index在后面，那就begin开始动
    //这样也成功解决了第一个数就是最小的的情况
    while (begin < end)
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
void quickSort(int *a, int begin, int end)
{

    if (begin < end) //这样区间内至少有两个元素
    {
        int pivot = partition(a, begin, end);
        quickSort(a, begin, pivot - 1);
        quickSort(a, pivot + 1, end); //递归，而且不再动锚点
    }
}

void BSortSpecial(int *arr, int N,int start)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N - 1 - i; j++)
        {
            int temp;
            if (num[j+start] < num[j+start + 1]&&arr[j]==arr[j+1])
            {
                temp = num[j+start];
                num[j+start] = num[j+start + 1];
                num[j +start+ 1] = temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
    char name[10];
    scanf("%s", name);
    freopen(name, "r", stdin);

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        const int N = n + 3;
        int level[N];
        for (int k = 0; k < n; k++)
        {
            scanf("%d %d", &num[k], &level[k]);
        }
        int begin = 0;
        int end = n - 1;
        quickSort(level, begin, end);
        int j;
        while(level[j]<100)
        {
            j++;
        }
        if(n>j)
        {
            BSortSpecial(&level[j], n-j,j);
        for(int k=n-1;k>=j;k--)
        {
            printf("%d\n",num[k]);
        }
        }
        else
        {
            printf("This OJ is too easy for PQ Dashen!\n");
        }
        if(i!=t-1)printf("\n");
    }
    return 0;
}