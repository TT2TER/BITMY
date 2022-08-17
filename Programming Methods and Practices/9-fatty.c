#include <stdio.h>
#include <string.h>
char com[11] = "fattyhappy";
char s[1050];
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        gets(s);
        int len = strlen(s);
        int has_dif = 0;
        int got_it = 0;
        char dif1, dif2;
        int p1, p2;
        for (int i = 0; i <= len - 10; i++)
        {
            has_dif = 0, got_it = 0;
            for (int j = 0; j < 10; j++)
            {
                if (s[i + j] != com[j] && has_dif == 0)
                {
                    has_dif++;
                    dif1 = com[j];
                    p1 = i + j;
                }
                else if (s[i + j] != com[j] && has_dif == 1)
                {
                    has_dif++;
                    dif2 = com[j];
                    p2 = i + j;
                }
                else if (s[i + j] != com[j])
                {
                    has_dif++;
                }
            }
            if (has_dif == 0)
            {
                printf("%d %d\n",i+3,i+4);
                got_it=1;
                break;
            }
            else if(has_dif==1)
            {
                for(int k=0;k<len;k++)
                {
                    if(s[k]==dif1)
                    {
                        printf("%d %d\n",k+1,p1+1);
                        got_it=1;
                        break;
                    }
                    if(k==i)k+=9;
                }
                if(got_it)break;
            }
            else if(has_dif==2)
            {
                if(s[p1]==dif2&&s[p2]==dif1)
                {
                    printf("%d %d\n",p1+1,p2+1);
                    got_it=1;
                    break;
                }
                continue;
            }
            else{
                continue;
            }
            
        }if(!got_it)printf("-1\n");
    }
    return 0;
}