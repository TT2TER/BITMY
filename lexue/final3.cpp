#include<stdio.h>
#include<string.h>
int main()
{
	char l[220];
	gets(l);
	int n=strlen(l);
	int i;
	//printf("%c",l[n-1]);
	int num=l[n-1]-'0';
	for(i=0;i<num;i++)
	{
		printf("%c",l[i]);
	}
	for(i=num-1;i>=0;i--)
	{
		printf("%c",l[i]);
	}
	printf("\n");
	return 0;
}

