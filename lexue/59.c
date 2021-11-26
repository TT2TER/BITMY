/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char *resort(char *a);
int main(int argc, char *argv[])
{

    char a[100];
    gets(a);
    puts(resort(a));
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
char *resort(char *a)
{
    int i,j;
    int len=0;
    while(a[len]!='\0'){len++;}
    for(i=0;i<len;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            int temp;
            if(a[j]>a[j+1])
            {temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;}
        }
    }
    return a;
}