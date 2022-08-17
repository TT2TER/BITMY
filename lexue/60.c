/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int merge_sort(char *a, char *b, char *c);
int main(int argc, char *argv[])
{

    char a[100];
    char b[100];
    char c[200];

    gets(a);
    gets(b);
    merge_sort(a, b, c);
    puts(c);
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
int merge_sort(char *a, char *b, char *c)
{
    int i,j;
    int len1=0,len2=0;
    while(a[len1]!='\0'){len1++;}
    while(b[len2]!='\0'){len2++;}
    for(i=0;i<200;i++)
    {
        c[i]='\0';
    }
    for(i=0;i<len1;i++)
    {
        c[i]=a[i];
    }
    for(;i<len1+len2;i++)
    {
        c[i]=b[i-len1];
    }
    for(i=0;i<len1+len2;i++)
    {
        for(j=0;j<len1+len2-1-i;j++)
        {
            int temp;
            if(c[j]>c[j+1])
            {temp=c[j];
            c[j]=c[j+1];
            c[j+1]=temp;}
        }
    }
    return 1;
}