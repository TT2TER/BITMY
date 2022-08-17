#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int value;
    struct _node *next;
} Node;
//不常用
typedef struct _list //这个数据结构代表了整个链表,代表了无限可能
{
    Node *head; //指的第一个结点
    Node *tail; //指的倒数第二个结点
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
Node * search(List *plist, int num)
{
    Node *curr=plist->head;
    Node *last=plist->tail;
    for(int i=1;curr!=last;i=i+1>num?1:i+1)
    {
        if(i==num)
        {
            last->next=curr->next;
            free(curr);
            curr=last->next;
        }
        else
        {
            last=last->next;
            curr=curr->next;
        }
    }
    return curr;
}
int main()
{
    int n, num;
    scanf("%d %d", &n, &num);
    List list;
    list.head = list.tail = NULL;
    for(int i=1;i<=n;i++)
    {
        add(&list,i);
    }
    list.tail=list.tail->next;
    list.tail->next=list.head;
    printf("The left child is NO %d.\n",search(&list,num)->value);
    return 0;
}