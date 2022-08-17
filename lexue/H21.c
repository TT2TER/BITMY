#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ElementType int
typedef struct snode
{
    ElementType Data;
    struct snode *next;
} stack;
stack *creatstack()
{
    //这是堆栈的头结点
    stack *s = (stack *)malloc(sizeof(stack));
    s->next = NULL;
    return s;
}
int isempty(stack *s)
{
    return (s->next == NULL);
}
void push(ElementType item, stack *s)
{
    stack *p = (stack *)malloc(sizeof(stack));
    p->Data = item;
    p->next = s->next;
    s->next = p;
}
ElementType pop(stack *s)
{
    if (isempty(s))
    {
        return -1; // TODO:return 一个什么东西呢？
    }
    else
    {
        stack *p;
        ElementType top;
        p = s->next;
        s->next = p->next;
        top = p->Data;
        free(p);
        return top;
    }
}
int main()
{
    stack *s = creatstack();
    char c;
    int num=0;
    while ((c = getchar()) != EOF) //读入方式
    {
        if (c == ' ' || c == '\n')
            continue;
        if (isdigit(c))
        {
            num = c - '0';
            while ((c = getchar()) != EOF)
            {
                if (c == ' '||c=='\n')
                {
                    push(num,s);
                    num = 0;
                    break;
                }
                else
                    num = num * 10 + c - '0';
            }
        }
        else
        {
            int b = pop(s);
            int a = pop(s);
            switch (c)
            {
            case '+':
                push(a + b, s);
                break;
            case '*':
                push(a * b, s);
                break;
            case '-':
                push(a - b, s);
                break;
            case '/':
                push(a / b, s);
                break;
            }
        }
    }
    printf("%d\n", pop(s));
    return 0;
}