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
void deployList(PNODE);

int main()
{
    int num = 1;
    PNODE head;

    head = (PNODE)malloc(sizeof(NODE));
    head->next = NULL;
    head->data = -1;

    createList(head); // 这是你要完成的函数
    deployList(head); // 这是你要完成的函数
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
void deployList(PNODE h)
{
    NODE *tail;
    tail=h;
    NODE *oldtail;
    while(tail->next)
    {
        tail=tail->next;
    }
    oldtail=tail;
    NODE *last,*curr;
    last=h;
    curr=h->next;
    while(curr!=oldtail)
    {
        if(curr->data%2)
        {
            NODE* temp;
            last->next=curr->next;
            temp=curr;
            curr=curr->next;
            tail->next=temp;
            temp->next=NULL;
            tail=tail->next;
        }
        else
        {
            curr=curr->next;
            last=last->next;
        }   
    }

}
