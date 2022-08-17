#include <stdio.h>
#include <stdlib.h>
typedef struct alpha
{
    char c;
    int num;
    struct alpha *next;
} al;
typedef struct List
{
    al *head;
} list;
int isnum(char a)
{
    if ('1' <= a && '7' >= a)
        return 1;
    else if ('a' <= a && 'd' >= a)
        return 0;
    else
        return 2;
}
void search(list *p, int tag, char in)
{
    al *q;
    if (!tag)
    {
        for (q = p->head; q; q = q->next)
        {
            if (q->c == in){
                printf("%d\n", q->num);
            return;}
        }
    }
    else
    {
        for (q = p->head; q; q = q->next)
        {
            if (q->num == in-'0'){
                printf("%c\n", q->c);
            return;}
        }
    }
}
int main()
{
    list l;
    l.head = NULL;
    char ch[8] = "abcdcba";
    for (int i = 0; i < 7; i++)
    {
        al *p = (al *)malloc(sizeof(al));
        if (i == 0)
        {
            l.head = p;
            p->next = NULL;
            p->c = ch[i];
            p->num = i;
        }
        else
        {
            p->next = l.head;
            l.head = p;
            p->c = ch[i];
            p->num = i;
        }
    }
    // getchar();
    char in;
    scanf("%c", &in);
    int tag;
    tag = isnum(in);
    if (tag == 2)
        printf("N\n");
    else
    {
        search(&l,tag,in);
    }
    return 0;
}