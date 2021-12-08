#include <stdio.h>
#include <stdlib.h>
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
        return ;//TODO:return 一个什么东西呢？
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
    push(4, s);
    printf("%d\n",pop(s));
    push(233,s);
    printf("%d",pop(s));
    return 0;
}