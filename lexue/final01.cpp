#include<stdio.h>
#include<windows.h>
int main()
{       FILE * fp=NULL;
        char ch, str[100]="";
        int i=0;
 
       fp=fopen("c:\\data.txt", "r");
        if(fp==NULL)
        {        printf("Can't open file\n");
                 exit(0);
        }
        fgets(str,100,fp);
        fclose(fp);
       while(str[i]!='\0')
        {    if(islower(str[i]))  str[i]=str[i]-32 ;
            //islower()�ж���ڲ����Ƿ�ΪСд�ַ����䷵��ֵΪ"True"��"False"
             i++;
         }
 
        fp=fopen("c:\\data.txt","a+");
         if(fp==NULL)
          {        printf("Can't open file\n");
                 exit(0);
          }
         fputs(str,fp);
         rewind(fp);
        while ((ch=fgetc(fp))!= EOF) 
        fputc(ch,stdout);
         fclose(fp);
} 
