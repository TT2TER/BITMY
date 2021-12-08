#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct _node
{
    int value;
    struct _node *next;
} Node;
typedef struct _list //这个数据结构代表了整个链表,代表了无限可能
{
    Node *head; //指的第一个结点
    Node *tail; //指的倒数第二个结点
} List;
/*
typedef struct GNode//广义表
{
    int tag;
    union
    {
        ElementType Data;
        struct GNode *Sublist;
    } URegion;
    struct GNode *next;
} GList;
*/
// TODO:头结点本身就是空的怎么办
void add(List *plist, int number)
{
    // add to linked-list,用malloc分配
    Node *p = (Node *)malloc(sizeof(Node)); //每次分配都是新的？？
    p->value = number;
    p->next = NULL;
    //找到这个之前的Node
    if (plist->tail)
    {
        while (plist->tail->next) //当当前这个Node指向了下一个，也就是说.next指的不是空指针，tail向后挪一个结点
        {
            plist->tail = plist->tail->next;
        }
        // attach
        plist->tail->next = p;
    }
    else
    {
        plist->head = p;
        plist->tail = p;
    }
}
void print(List *pList)
{
    Node *p;
    for (p = pList->head; p; p = p->next)
    {
        printf("%d\n", p->value);
    }
}

void searchanddel(List *pList, int number)
{
    Node *p;
    Node *q;
    for (q = NULL, p = pList->head; p;)
    {
        if (p->value == number)
        {
            if (q) //边界条件就是->左边的东西是不是NULL?
            {
                q->next = p->next;
                free(p);
                p = q->next;
            }
            else
            {
                pList->head = p->next;
                free(p);
                p = pList->head;
            }
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
}
/*
void del(List *pList)
{
    Node *p;
    Node *q;
    for (p = pList->head, q = p->next; p; p = q, q = p->next)//错误原因是因为最后p->next的p=q=NULL
    {
        free(p);
    }
}
*/
void del(List *pList)
{
    Node *p;
    Node *q;
    for (p = pList->head; p; p = q)
    {
        q = p->next;
        free(p);
    }
}

void reverse(List *pList)
{
    if (!pList->head)//如果链表是空的
        return;
    if (!pList->head->next) //如果只有一个元素
        return;
    Node *p = pList->head->next;
    Node *q = NULL;
    Node *o = NULL;
    if (!q)
    {
        q = p->next;
        if (q)
        {
            if (q->next)
            {
                o = q->next;
            }
        }
        p->next = pList->head;
        pList->head->next = NULL;
        pList->tail = p;
    }
    while (q && o)
    {
        q->next = p;
        if (o->next)
            break;
        else
        {
            p = q;
            q = o;
            o = o->next;
        }
    }
    if (!o)
    {
        if (!q)
        {
            pList->head = p;
        }
        else
        {
            q->next = p;
            pList->head = q;
        }
    }
    else
    {
        o->next = q;
        pList->head = o;
    }
}
int main()
{
    List list;
    list.head = list.tail = NULL;
    int number;
    do
    {
        scanf("%d", &number);
        if (number != -1)
        {
            add(&list, number);
        }
    } while (number != -1);
    print(&list);
    scanf("%d", &number);
    searchanddel(&list, number);
    reverse(&list);
    print(&list);
    del(&list);
    return 0;
}
// TODO:head++为什么不行？
/*
    for(;list.head->next!=NULL;list.head=list.head->next//list.head++)
    {
        printf("%d\n",list.head->value);
        //printf("%p\n",list.head);
    }
    //printf("%d", sizeof(Node));
    getchar();getchar();
    */