# include <stdio.h>
typedef struct Fen
{
    char name[22];
    int score;
} fen;
void BubbleSort(fen *arr, int len) //len就是有多少个数,数组长度
{
    int i, j;
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            fen temp;
            if (arr[j].score < arr[j + 1].score)
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
    int n;
    scanf("%d",&n);
    
    fen arr[200];
    for(int i=0;i<n;i++)
    {
        getchar();
        int j=0;
        while((arr[i].name[j]=getchar())!=',')
        {
            j++;
        }
        arr[i].name[j]='\0';
        scanf("%d",&arr[i].score);
    }
    BubbleSort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%s,%d\n",arr[i].name,arr[i].score);
    }
    return 0;
}