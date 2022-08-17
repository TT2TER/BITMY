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
void createList(PNODE);
void deployList(PNODE head1, PNODE head2, PNODE head3);

int main()
{
    PNODE head1, head2, head3;

    head1 = (PNODE)malloc(sizeof(NODE));
    head1->next = NULL;
    head1->data = -1;

    head2 = (PNODE)malloc(sizeof(NODE));
    head2->next = NULL;
    head2->data = -1;

    head3 = (PNODE)malloc(sizeof(NODE));
    head3->next = NULL;
    head3->data = -1;

    createList(head1);               // 这是你要完成的函数
    createList(head2);               // 这是你要完成的函数
    deployList(head1, head2, head3); // 这是你要完成的函数
    outlist(head3);
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

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
void createList(PNODE h)
{
    int number;
    do
    {
        scanf("%d", &number);
        if (number != 0)
        {
            NODE *p = (NODE *)malloc(sizeof(NODE)); //每次分配都是新的？？
            p->data = number;
            p->next = NULL;
            while(h->next)
            {
                h=h->next;
            }
            h->next=p;
        }
    } while (number != 0);
}
void deployList(PNODE head1, PNODE head2, PNODE head3)
{
    while(head1->next&&head2->next)
    {
        NODE *p=(NODE *)malloc(sizeof(NODE)),*q=(NODE *)malloc(sizeof(NODE));
        p->data=head1->next->data;
        p->next=q;
        q->data=head2->next->data;
        q->next=NULL;
        head3->next=p;
        while(head3->next)
        {
            head3=head3->next;
        }
        head1=head1->next;
        head2=head2->next;
    }
    if(head1->next)
    {
        head3->next=head1->next;
    }
    if(head2->next)
    {
        head3->next=head2->next;
    }
}