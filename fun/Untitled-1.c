#include <stdio.h>
#include <string.h>
#define id "id="
#define lang "language="
#define tit "title="
#define urls "http"
int main()
{
    freopen("sports.m3u", "r", stdin);
    freopen("2.txt", "w", stdout);
    char a;
    char oneturn[1500];

    while ((a = getchar()) != EOF)
    {
        int i = 0, j;
        memset(oneturn, '\0', 1500);
        while ((a = getchar()) != '#')
        {
            if(a=='\n')continue;
            oneturn[i] = a;
            i++;
        }
        oneturn[i] = '\0';
        char name[300];

        char *ret, *urlstart;
        j = 0;

        ret = strstr(oneturn, tit);
        if (ret == NULL)
            continue;
        i = 0;
        while (ret[i] != ',')
        {
            i++;
        }
        for (++i; ret[i] != ':'; i++, j++)
        {
            if(ret[i]=='(')break;
            name[j] = ret[i];
        }

        //j = j - 4;
        urlstart = ret;
        name[j++] = '\0';//增加属性时把\0改为-

        //printf("\n%d\n",strlen(name));
        // ret = strstr(oneturn,id);
        // if(ret==NULL)continue;
        // for(i=4;ret[i]!='\"';i++,j++)
        // {
        //     name[j]=ret[i];
        // }

        /* 语言
        ret = strstr(oneturn, lang);
        if (ret == NULL)
            continue;
        for (i = 10; ret[i] != '\"'; i++, j++)
        {
            if (ret[i] == ';')
                name[j] = '&';
            else
                name[j] = ret[i];
        }
        */

        name[j] = '\0';

        ret = strstr(urlstart, urls);
        if (ret == NULL)
            continue;

        printf("%s,%s;\n",name,ret);
    }
    return 0;
}