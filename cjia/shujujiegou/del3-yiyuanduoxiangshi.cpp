/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coef, exp;
    struct node *next;
} NODE;

void multiplication(NODE *, NODE *, NODE *);
void input(NODE *);
void output(NODE *);

void input(NODE *head)
{
    int flag, sign, sum, x;
    char c;

    NODE *p = head;

    while ((c = getchar()) != '\n')
    {
        if (c == '<')
        {
            sum = 0;
            sign = 1;
            flag = 1;
        }
        else if (c == '-')
            sign = -1;
        else if (c >= '0' && c <= '9')
        {
            sum = sum * 10 + c - '0';
        }
        else if (c == ',')
        {
            if (flag == 1)
            {
                x = sign * sum;
                sum = 0;
                flag = 2;
                sign = 1;
            }
        }
        else if (c == '>')
        {
            p->next = (NODE *)malloc(sizeof(NODE));
            p->next->coef = x;
            p->next->exp = sign * sum;
            p = p->next;
            p->next = NULL;
            flag = 0;
        }
    }
}

void output(NODE *head)
{
    while (head->next != NULL)
    {
        head = head->next;
        printf("<%d,%d>,", head->coef, head->exp);
    }
    printf("\n");
}

int main()
{
    NODE *head1, *head2, *head3;

    head1 = (NODE *)malloc(sizeof(NODE));
    input(head1);

    head2 = (NODE *)malloc(sizeof(NODE));
    input(head2);

    head3 = (NODE *)malloc(sizeof(NODE));
    head3->next = NULL;
    multiplication(head1, head2, head3);

    output(head3);
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
void multiplication(NODE *a, NODE *b, NODE *c)
{
    node *aa, *bb, *cc;
    aa = a;
    bb = b;
    cc = c;
    cc->exp = -1;
    int hasa = 1, hasb = 1;
    while (aa->next != NULL)
    {

        aa = aa->next;
        node *bbb = bb;
        while (bbb->next != NULL)
        {
            int added = 0;
            node *ccc = cc;
            bbb = bbb->next;

            int s = aa->coef * bbb->coef;
            int e = aa->exp + bbb->exp;

            if (s == 0 && e != 0)
                continue;
            while (ccc->exp < e && !added)
            {
                if (ccc->next)
                    ccc = ccc->next;
                else
                {
                    ccc->next = (NODE *)malloc(sizeof(NODE));
                    ccc->next->coef = s;
                    ccc->next->exp = e;
                    ccc = ccc->next;
                    ccc->next = NULL;
                    added = 1;
                    break;
                }
            }
            if (ccc->exp == e && !added)
            {
                ccc->coef = ccc->coef + s;
                added = 1;
            }
            if (ccc->exp > e && !added)
            {
            }
        }
    }

    if (aa->exp == bb->exp && hasa && hasb)
    {
        int s = aa->coef * bb->coef;
        cc->next = (NODE *)malloc(sizeof(NODE));
        cc->next->coef = s;
        cc->next->exp = aa->exp;
        cc = cc->next;
        cc->next = NULL;
    }
    if ((hasa && hasb && aa->exp > bb->exp) || (hasb && !hasa))
    {
        int s = bb->coef;
        cc->next = (NODE *)malloc(sizeof(NODE));
        cc->next->coef = s;
        cc->next->exp = bb->exp;
        cc = cc->next;
        cc->next = NULL;
    }
    if ((hasa && hasb && aa->exp < bb->exp) || (!hasb && hasa))
    {
        int s = aa->coef;
        cc->next = (NODE *)malloc(sizeof(NODE));
        cc->next->coef = s;
        cc->next->exp = aa->exp;
        cc = cc->next;
        cc->next = NULL;
    }
}
}