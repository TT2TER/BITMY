#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;
#define MAX 9999999
struct Ret
{
    int num;
    bool m; // n/y
} ;

int figure[100];  //存入数字
char symbol[100]; //存入操作符
//下标
int topf = -1;
int tops = -1;
//一起用来定位优先顺序
char operation[9] =
    {'+', '-', '*', '/', '(', ')', '#', '^', '%'};
char checklist[9][9] = {
    {'>', '>', '<', '<', '<', '>', '>', '<', '<'},
    {'>', '>', '<', '<', '<', '>', '>', '<', '<'},
    {'>', '>', '>', '>', '<', '>', '>', '<', '>'},
    {'>', '>', '>', '>', '<', '>', '>', '<', '>'},
    {'<', '<', '<', '<', '<', '=', ' ', '<', '<'},
    {'>', '>', '>', '>', ' ', '>', '>', '>', '>'},
    {'<', '<', '<', '<', '<', ' ', '=', '<', '<'},
    {'>', '>', '>', '>', '<', '>', '>', '<', '>'},
    {'>', '>', '>', '>', '<', '>', '>', '<', '>'}};

int number(char *q)
{
    return (int)(*q - '0');
}

void push_figure(int q)
{
    figure[++topf] = q;
}

void push_symbol(char ch)
{
    symbol[++tops] = ch;
}

int pop_figure()
{
    return figure[topf--];
}
//取出刚刚存入的这个符号
char pop_symbol()
{
    return symbol[tops--];
}

char compare(char x, char y)
{
    int a, b; //用来定位下标输出优先顺序
    for (int i = 0; i < 9; i++)
    {
        if (operation[i] == x)
        {
            a = i;
            break;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (operation[i] == y)
        {
            b = i;
            break;
        }
    }
    //得到优先级关系并且作为返回值
    return checklist[a][b];
}

Ret operate(int x, int y, char symbol)
{
    Ret ret;
    switch (symbol)
    {
    case '+':
        ret.num = x + y;
        ret.m = true;
        break;
    case '-':
        ret.num = x - y;
        ret.m = true;
        break;
    case '*':
        ret.num = x * y;
        ret.m = true;
        break;
    case '/':
        if (y)
        {
            ret.num = x / y;
            ret.m = true;
            break;
        }
        else
        {
            printf("Divide 0.\n");
            ret.m = false;
            break;
        }
    case '%':
        ret.num = (int)fmod(x, y);
        ret.m = true;
        break;
    case '^':
        if (y >= 0)
        {
            ret.num = (int)pow(x, y);
            ret.m = true;
            break;
        }
        else
        {
            printf("error.\n");
            ret.m = false;
            break;
        }
    default:
        printf("error.\n");
        ret.m = false;
        break;
    }
    return ret;
}

int main(int argc, char *argv[])
{
    int n;
    int flag; //数字0，（ 为1，其他2
    char expression[100], *p, *negative;
    char firstnega = '0';

    // freopen("file.txt","r",stdin);
    scanf("%d", &n);

    while (n--)
    {
        flag = 2;
        memset(expression, '\0', 100);
        scanf("%s", expression);

        strcat(expression, "#");
        p = expression;
        negative = expression;

        // 第一个符号是负数号且第二个字符是数字
        // 把负数号替换为0
        //指针操作，原来的也会被修改
        if (*negative == '-' && *(negative + 1) == '(')
        { //这种情况  -(2+2)+1 直接在figure中插入一个0
            push_figure(number(&firstnega));
        }

        if (*negative == '-' && *(negative + 1) >= '0' && *(negative + 1) <= '9')
        {
            *negative = '0';
        }
        negative++;
        // 遍历每一个字符
        // 前一个字符不是数字，这个字符是“-”号
        // 就把这个字符替换为0
        for (; *negative != '\0'; negative++)
        {
            if ((*(negative - 1) < '0' || *(negative - 1) > '9') && (*negative == '-') && *(negative - 1) != ')')
            {
                *negative = '0';
            }
        }
        //在栈symbol中插入#
        push_symbol('#');
        int dead = 0;
        while (*p != '#' || symbol[tops] != '#')
        {
            // 遇到数字
            if (*p >= '0' && *p <= '9')
            {
                if (flag == 0)
                {
                    //如果之前有负数的符号的话会改为0，然后0在这里作为判断标志在figure里面存入负数
                    if (figure[topf] <= 0)
                        push_figure(pop_figure() * 10 + number(p++) * (-1));
                    else
                        push_figure(pop_figure() * 10 + number(p++));
                }
                else
                    push_figure(number(p++));
                //说明已经插入过数字了,注意是一位一位的插入
                flag = 0;
            }
            //不是数字
            else
            {
                //考虑的是（+这种情况
                if (flag == 1)
                {
                    if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%' || *p == '^')
                    {
                        printf("error.\n");
                        {
                            dead = 1;
                            break;
                        }
                    }
                }
                //扫描到左括号时这种情况标记为1
                if (*p == '(')
                {
                    flag = 1;
                }
                else
                    flag = 2;

                if (tops == -1)
                {
                    printf("error.\n");
                    {
                        dead = 1;
                        break;
                    }
                }
                else
                {
                    char ch = pop_symbol(), ans;
                    // 把现在扫描到的这个符号和刚刚存入的那个操作符进行优先级比较
                    ans = compare(ch, *p);
                    if (ans == ' ')
                    {
                        printf("error.\n");
                        {
                            dead = 1;
                            break;
                        }
                    }
                    //优先级小，将其存入
                    else if (ans == '<')
                    {
                        push_symbol(ch); //把取出来的重新存进去
                        push_symbol(*p++);
                        continue;
                    }
                    // 优先级相同，tops指向上一位不变动，直接扫描下一个p，待会插入时直接覆盖掉（
                    else if (ans == '=')
                    {

                        p++;
                        continue;
                    }
                    else
                    {
                        //对x,y,ch进行运算，并将数字存进

                        int integer_x, integer_y;
                        integer_y = pop_figure();
                        integer_x = pop_figure();
                        Ret judge = operate(integer_x, integer_y, ch);
                        if (judge.m == false)
                        {
                            dead = 1;
                            break;
                        }
                        else
                            push_figure(judge.num);
                        continue;
                    }
                    p++;
                }
            }
        }
        if (!dead && topf == 0 && tops == 0)
            printf("%d\n", figure[topf]);
        else if (!dead)
        {
            printf("error.\n");
        }
        // 初始化，重新开始新的算式运算
        memset(expression, '\0', 100);
        topf = -1;
        tops = -1;
    }
    return 0;
}