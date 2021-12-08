#include <stdio.h>
#include <stdlib.h>
typedef struct _Node
{
    char c;
    struct _Node *next;
} Node;
typedef struct _List
{
    Node *head;
    Node *tail;
} List;
void add(List *ans, char ch)
{
    // add to linked-list,用malloc分配
    Node *p = (Node *)malloc(sizeof(Node)); //每次分配都是新的？？
    p->c = ch;
    p->next = NULL;
    //找到这个之前的Node
    if (ans->tail)
    {
        while (ans->tail->next) //当当前这个Node指向了下一个，也就是说.next指的不是空指针，tail向后挪一个结点
        {
            ans->tail = ans->tail->next;
        }
        // attach
        ans->tail->next = p;
    }
    else
    {
        ans->head = p;
        ans->tail = p;
    }
}
int IsSmall(char a, char b)
{
    return a < b ? 1 : 0;
}
void merge(List *ans, List *l1, List *l2) // 怎么做到不改变别的子列？用malloc新开。
{
    Node *o = l1->head;
    Node *q = l2->head;
    // Node temp = {'\0', NULL};
    while (o || q)
    {
        if (!ans->head)
        {
            Node *p = (Node *)malloc(sizeof(Node));
            if (IsSmall(o->c, q->c))
            {
                // temp = *o;
                *p = *o;
                ans->head = p;
                ans->tail = p;
                o = o->next;
            }
            else
            {
                // temp = *q;
                *p = *q;
                ans->head = p;
                ans->tail = p;
                q = q->next;
            }
        }
        else
        {
            while (o || q)
            {
                Node *p = (Node *)malloc(sizeof(Node));
                if (!o && q)
                {
                    // temp=*q;
                    *p = *q;
                    ans->tail->next = p;
                    ans->tail = p;
                    q = q->next;
                }
                else if (!q && o)
                {
                    // temp=*o;
                    *p = *o;
                    ans->tail->next = p;
                    ans->tail = p;
                    o = o->next;
                }
                else
                {
                    if (IsSmall(o->c, q->c))
                    {
                        // temp = *o;
                        *p = *o;
                        ans->tail->next = p;
                        ans->tail = p;
                        o = o->next;
                    }
                    else
                    {
                        // temp = *q;
                        *p = *q;
                        ans->tail->next = p;
                        ans->tail = p;
                        q = q->next;
                    }
                }
            }
        }
    }
}
void delsame(List *ans)
{
    Node *p;
    Node *q;
    for (q = NULL, p = ans->head; p;)
    {
        if (p->next)
        {
            if (p->c == p->next->c)
            {
                if (q) //边界条件就是->左边的东西是不是NULL?
                {
                    q->next = p->next;
                    free(p);
                    p = q->next;
                }
                else
                {
                    ans->head = p->next;
                    free(p);
                    p = ans->head;
                }
            }
            else
            {
                q = p;
                p = p->next;
            }
        }
        else break;
    }
}
void print(List *ans)
{
    Node *p;
    for (p = ans->head; p; p = p->next)
    {
        printf("%c", p->c);
        if(p->next)
        {
            printf(" ");
        }
        else
        printf("\n");
    }
    
}
List list[3];
int main()
{

    int i;
    char c;
    for (i = 1; i <= 2; i++)
    {
        do
        {
            scanf("%c", &c);
            if (c != '\n' && c != ' ')
            {
                add(&list[i], c);
            }
        } while (c != '\n');
    }
    merge(&list[0], &list[1], &list[2]);
    delsame(&list[0]);
    print(&list[0]);
    return 0;
}
