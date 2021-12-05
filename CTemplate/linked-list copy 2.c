#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int value;
    struct _node *next;
} Node;
typedef struct _list //这个数据结构代表了整个链表,代表了无限可能
{
    Node *head;//指的第一个结点
    Node *tail;//指的倒数第二个结点
} List;

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

void search(List *pList, int number)
{
    Node *p;
    Node *q;
    for (q = NULL, p = pList->head; p; )
    {
        if (p->value == number)
        {
            if (q)//边界条件就是->左边的东西是不是NULL?
            {
                q->next = p->next;
                free(p);
                p=q->next;
            }
            else
            {
                pList->head = p->next;
                free(p);
                p=pList->head;
            }
            
        }
        else
        {
            q=p;
            p = p->next;
        }
    }
}
void del(List *pList)
{
    Node *p;
    Node *q;
    for(p=pList->head,q=p->next;p;p=q,q=p->next)
    {
        free(p);
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
    /*for(;list.head->next!=NULL;list.head=list.head->next/*list.head++)
    {
        printf("%d",list.head->value);
    }
    printf("%d", list.head->value);*/
    print(&list);
    scanf("%d",&number);
    search(&list,number);
    print(&list);
    del(&list);
    return 0;
}