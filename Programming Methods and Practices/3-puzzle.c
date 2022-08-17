#include <stdio.h>
#define max 16
int ans = 17*17;
int map[max + 2][max + 2];
int curent[max + 2][max + 2];
int l = 0, w = 0;

int if_line_all_zero(int a[])
{
    int answ = 1;
    for (int i = 1; i <= w; i++)
    {
        if (a[i] != 0)
        {
            answ = 0;
            break;
        }
    }
    return answ;
}

void change(int *a)
{
    if (*a == 1)
    {
        *a = 0;
    }
    else
    {
        *a = 1;
    }
    return;
}

void one_step(int a[max + 2][max + 2], int a0, int b0)
{
    change(&a[a0][b0]);
    change(&a[a0 - 1][b0]);
    change(&a[a0][b0 - 1]);
    change(&a[a0 + 1][b0]);
    change(&a[a0][b0 + 1]);
    return;
}
int is_yes()
{
    int count=0;
        for (int i = 1; i <= l; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                curent[i][j] = map[i][j];
            }
        }
        for (int i = 1; i < l; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if(curent[i][j]==1)
                {
                    one_step(curent,i+1,j);
                    count++;
                }
            }
        }
        if(if_line_all_zero(curent[l]))
        {
            if(l!=1)return count;
            else return -2;
        }
        else return -1;

}

void dfs(int position, int count)
{
    if (position == w)
    {
        int answer = is_yes();
        if (answer == -1)
        {
            return;
        }
        else if(answer==-2&&count<ans)
        {
            ans=count;
            return;
        }
        else if (answer + count < ans)
        {
            ans= answer + count;
            return;
        }
        else return;
    }

    one_step(map,1,position);
    dfs(position+1,count+1);

    one_step(map,1,position);
    dfs(position+1,count);
}

int main()
{
    scanf("%d %d\n", &l, &w);
    if (l==1&&w==1)
    {
        char c=getchar();
        if((c-'0')==1)
        {
            ans=1;
        }
        else ans=0;
        printf("%d\n",ans);
        return 0;
    }
    for (int i = 1; i <= l; i++)
    { char c;
        for (int j = 1; j <= w; j++)
        {
            
            c=getchar();
            map[i][j]=c-'0';
        }
        c=getchar();
    }
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}