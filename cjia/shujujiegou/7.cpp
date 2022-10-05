#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;
struct Ret
{
    int num;
    bool m; // n/y
};
stack<int> num;
stack<char> sig;

typedef struct var
{
    char name[10];
    char num[10];
    struct var *next;
} var, *ptvar;
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

int char2num(char *q)
{
    return (int)(*q - '0');
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

int main()
{

    int flag; //数字0，（ 为1，其他2
    char expr[100], *p, *nega;
    char fnega = '0';

    char g[100]; //读进来整个字符串，然后处理字符串
    memset(g, '\0', 100);
    gets(g);
    ptvar en;
    ptvar h = (ptvar)malloc(sizeof(var));
    strcpy(h->name, "0");
    strcpy(h->num, "2");
    en = h;
    h->next = NULL;

    // test，最终请注释掉这段代码
    ptvar z = (ptvar)malloc(sizeof(var));
    strcpy(z->name, "abc");
    strcpy(z->num, "2");
    z->next = NULL;
    en->next = z;
    en = z;
    //代码结束

    while (strcmp("end", g) != 0) // end功能
    {
        memset(expr, '\0', 100);
        int option = 1; // 1为方程，2为问号，输出
        char now[10] = {'\0'};
        if (g[0] == '?')
            option = 2;
        if (option == 2)
        {
            int i;
            for (i = 0; i < 10 && g[i + 2] != '\0'; i++)
            {
                now[i] = g[i + 2];
            }
            now[i] = '\0';
            //操作
            ptvar q = h;
            int done = 0;
            while (q->next != NULL && !done)
            {
                q = q->next;
                if (strcmp(q->name, now) == 0)
                {
                    printf("%s=%s\n", now, q->num);
                    //初始化，继续循环
                    memset(g, '\0', 100);
                    gets(g);
                    done = 1;
                    break;
                }
            }
            if (done)
                continue;
        }
        else if (option == 1)
        {
            int i;
            for (i = 0; i < 10 && g[i] != '='; i++)
            {
                now[i] = g[i];
            }
            now[i] = '\0'; //处理等号左边
            int j;
            for (j = 0; j + i < 100 && g[i + j + 1] != '\0'; j++)
            {
                expr[j] = g[i + j + 1];
            }
            expr[j++] = '#';
            expr[j] = '\0'; //处理等号右边

            //处理等号右边的字符
            int tail = 0;
            j = 0;
            for (j = 0; j < strlen(expr); j) //前后指针遍历
            {
                while ((expr[j] > 'z' || expr[j] < 'a') && expr[j] != '\0')
                {
                    j++;
                }
                tail = j;
                while (expr[tail] <= 'z' && expr[tail] >= 'a' && expr[tail] != '\0')
                {
                    tail++;
                }

                char tochange[10];
                char temp[100];

                strcpy(temp, &expr[tail]);

                int k;
                for (k = 0; k < tail - j; k++)
                {
                    tochange[k] = expr[j + k];
                }
                expr[j] = '\0';
                tochange[k] = '\0';
                ptvar q = h;
                while (q->next != NULL)
                {
                    q = q->next;
                    if (strcmp(q->name, tochange) == 0)
                    {
                        strcat(expr, q->num);
                        strcat(expr, temp);
                    }
                }
            }
        }
        while (!num.empty())
        {
            num.pop();
        }
        while (!sig.empty())
        {
            sig.pop();
        }
        //以下为计算模块
        flag = 2;

        p = expr;
        nega = expr;

        // 第一个符号是负数号且第二个字符是数字
        // 把负数号替换为0
        if (*nega == '-' && *(nega + 1) == '(')
        { //型如-(2+2)+1 直接在num.stack中插入一个0
            num.push(char2num(&fnega));
        }

        if (*nega == '-' && *(nega + 1) >= '0' && *(nega + 1) <= '9')
        {
            *nega = '0';
        }
        nega++;
        // 遍历每一个字符
        for (; *nega != '\0'; nega++)
        {
            if ((*(nega - 1) < '0' || *(nega - 1) > '9') && (*nega == '-') && *(nega - 1) != ')')
            {
                *nega = '0';
            }
        }
        sig.push('#');
        int dead = 0;
        while (*p != '#' || sig.top() != '#')
        {
            if (*p >= '0' && *p <= '9')
            {
                if (flag == 0)
                {
                    if (num.top() <= 0)
                    {
                        int q = num.top();
                        num.pop();
                        num.push((q * 10 + char2num(p++) * (-1)));
                    }
                    else
                    {
                        int q = num.top();
                        num.pop();
                        num.push(q * 10 + char2num(p++));
                    }
                }
                else
                    num.push(char2num(p++));
                flag = 0;
            }
            else
            {
                //（+
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
                //左括号标记为1
                if (*p == '(')
                {
                    flag = 1;
                }
                else
                    flag = 2;

                if (sig.empty())
                {
                    printf("error.\n");
                    {
                        dead = 1;
                        break;
                    }
                }
                else
                {
                    char ch = sig.top(), ans;
                    sig.pop();
                    //优先级比较
                    ans = compare(ch, *p);
                    if (ans == ' ')
                    {
                        printf("error.\n");
                        {
                            dead = 1;
                            break;
                        }
                    }
                    else if (ans == '<')
                    {
                        sig.push(ch);
                        sig.push(*p++);
                        continue;
                    }

                    else if (ans == '=')
                    {
                        p++;
                        continue;
                    }
                    else
                    {
                        int integer_x, integer_y;
                        integer_y = num.top();
                        num.pop();
                        integer_x = num.top();
                        num.pop();
                        Ret judge = operate(integer_x, integer_y, ch);
                        if (judge.m == false)
                        {
                            dead = 1;
                            break;
                        }
                        else
                            num.push(judge.num);
                        continue;
                    }
                    p++;
                }
            }
        }
        if (!dead && num.size() == 1 && sig.size() == 1)
        {
            //printf("%d\n", num.top());
            int ansnum = num.top();
            char ans[10] = {'\0'};
            // if(ansnum<0)
            // {
            //     strcat(ans,"-");
            //     ansnum=-ansnum;
            // }
            //itoa(ansnum, ans, 10);
            snprintf(ans, sizeof(ans), "%d", ansnum);
            ptvar q = h;
            int had = 0;
            while (q->next != NULL)
            {
                q = q->next;
                if (strcmp(q->name,now)==0)
                {
                    //更新现有
                    strcpy(q->name, now);
                    strcpy(q->num, ans);
                    had = 1;
                    break;
                }
            }
            if (!had)
            {
                ptvar z = (ptvar)malloc(sizeof(var));
                strcpy(z->name, now);
                strcpy(z->num, ans);
                z->next = NULL;
                en->next = z;
                en = z;
            }
            // printf("%s",ans);
        }

        else if (!dead)
        {
            printf("error.\n");
        }
        memset(g, '\0', 100);
        gets(g);
    }
    return 0;
}