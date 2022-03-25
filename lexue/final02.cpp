#include<stdio.h>
#include<windows.h>
struct list
{
       int data;
       struct list *next;
 
};
struct list *List_Create (int n)
{
       struct list *h=NULL,*p=NULL, *q=NULL;
       int x=0, i=0;
       h=( struct list *) malloc (sizeof(struct list));
       p=h;
       for(i=1; i<=n;i++)
       {
              scanf("%d",&x);
              q=( struct list *) malloc (sizeof(struct list));
              q->data=x;
      
       p->next=q;
       
              p=q;
}
p->next=NULL;
return h;
}
 
void List_Output(struct list *h)
{
       struct list *p=NULL;
       p=h->next;
       printf("The linked list only for even number:");
       while(p!=NULL)
       {
              if(p->data%2==0) printf("%d->",p->data);
      
p=p->next;
              
}
printf("End\n");
}
int main()
{
       struct list *h=NULL;
       h=List_Create(10);
       List_Output(h);
}
