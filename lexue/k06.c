#include <stdio.h>
#define L sizeof(st)
typedef struct stu
{
    int id;
    char name[40];
    int score;
} st;
st s[2000];
int main()
{
    int n, tmp;
    int ans;
    scanf("%d",&ans);
    FILE *fp = fopen("slist.dat", "rb");
    int i=0;
    // while (fscnaf(fp,"%d %s %d",&data[i].id,data[i].name,&data[i].score)!=EOF)
    // {
    //     i++;
    // }
    for(i=0;i<2000;i++)
    {
        fread(&s[i],L,1,fp);
        if(ans==s[i].id)
        printf("<Ñ§ºÅ>%d<ÐÕÃû>%s<³É¼¨>%d\n",s[i].id,s[i].name,s[i].score);
    }
    fclose(fp);
    return 0;
}