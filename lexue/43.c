#include <stdio.h>
//#include<math.h>
#include <string.h>
int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}; //从w[0]开始使用
char y[12] = "10X98765432";                                        //字符数组初始化时，数组大小一定要大于字符串长度+1，否则编译错误。
int mo[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char num[1000][20];
int intnum[1000][20], len[1000];
int mod(int i) //计算校验码函数,//验证成功返回1,失败为0
{
    int sum = 0, md = 0;
    int j;
    for (j = 0; j < 17; j++)
    {
        sum += (w[j] * intnum[i][j]);
    }
    md = sum % 11;
    //return (y[md]==num[i][17]);
    return md;
}

int check(int a, int i)
{
    return (y[a] == num[i][17]);
}
void conver(int i) //将字符型的数字转换为整形,i为行数
{
    int j;
    for (j = 0; j < 17; j++)
    {
        intnum[i][j] = (int)num[i][j] - 48;
    }
}

int eighteen(int i)
{
    int ret = 0;
    if (num[i][12 + 2] == '9' && num[i][13 + 2] == '9' && (num[i][14 + 2] == '6' || num[i][14 + 2] == '7' || num[i][14 + 2] == '8' || num[i][14 + 2] == '9'))
    {
        ret = 1;
    }
    return ret;
}
int main(void)
{
    //freopen("1.in","r",stdin);
    int n;
    scanf("%d", &n);
    int i, j, a;
    for (i = 0; i < n; i++) //读取,判断15位
    {
        scanf("%s", num[i]);
        len[i] = strlen(num[i]);
        if (num[i][15] == '\0')
        {
            int tj;
            for (tj = 15; tj >= 6; tj--)
                num[i][tj + 2] = num[i][tj]; //将15位向后移动两位
            if (eighteen(i))
            {
                num[i][6] = '1';
                num[i][7] = '8';
            }
            else
            {
                num[i][6] = '1';
                num[i][7] = '9';
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        conver(i);
        if (len[i] != 15 && len[i] != 18)
        {
            printf("Invalid\n");
        }
        else if (num[i][17] == '\0')
        {
            num[i][17] = y[mod(i)];
            num[i][18] = '\0';
            printf("%s\n", num[i]);
        }
        else if (num[i][18] == '\0')
        {
            if (check(mod(i), i))
                printf("Valid\n");
            else
                printf("Invalid\n");
        }
        else
            printf("Invalid\n");
    }
    return 0;
}