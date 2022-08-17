/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

void outlist(PNODE);
void ins_list(PNODE h, int num);
int main()
{
    int num = 1;
    PNODE head;

    head = (PNODE)malloc(sizeof(NODE));
    head->next = NULL;
    head->data = -1;

    while (num != 0)
    {
        scanf("%d", &num);
        if (num != 0)
            ins_list(head, num);
    }

    outlist(head);
    return 0;
}

void outlist(PNODE head)
{
    PNODE p;
    p = head->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

/* This is an example for list. Please programme your code like it.
 */
void ins_list(PNODE h, int num)
{
    // add to linked-list,用malloc分配
    NODE *p = (NODE *)malloc(sizeof(NODE)); //每次分配都是新的？？
    p->data = num;
    p->next = NULL;
    NODE *q = h;
    while (q->next) //当当前这个NODE指向了下一个，也就是说.next指的不是空指针，tail向后挪一个结点
    {
        q = q->next;
    }
    // attach
    q->next=p;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */