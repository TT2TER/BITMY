#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define max 1000

typedef struct chuan
{
    /* data */
    int row;
    char data[max];
    struct chuan *next;
} chuan, *ptchuan;

ptchuan h, t; //开始,结尾
int cnt = 0;
void del(int arrow)
{
    if (arrow > cnt)
    {
        return;
    }
    else
    {
        ptchuan q = h;
        ptchuan pre = h;
        int find = 0;
        int last = 0; //特殊判断最后一个
        while (q->next != NULL)
        {
            q = q->next;
            if (q->row == arrow)
            {
                find = 1;
                ptchuan del = q;
                pre->next = q->next;
                if (q->next != NULL)
                    q = q->next;
                else
                {
                    q = pre;
                    last = 1;
                }

                free(del);
                cnt--;
            }
            if (find && !last)
            {
                q->row = pre->row + 1;
            }
            else if (last)
            {
                t = q;
            }
            pre = q;
        }
    }
    return;
}
int main()
{
    char in[max] = {'\0'};

    h = (ptchuan)malloc(sizeof(chuan));
    h->next = NULL;
    h->row = 0;
    t = h;
    //读入数据
    gets(in);

    while (strcmp(in, "[/Text]") != 0)
    {
        if (strcmp(in, "[Text]") == 0)
        {
            gets(in);
            continue;
        }
        ptchuan p = (ptchuan)malloc(sizeof(chuan));
        p->row = ++cnt;
        strcpy(p->data, in);
        p->next = NULL;
        t->next = p;
        t = p;
        gets(in);
    }
    //读入数据结束
    //读入操作
    char command;
    while ((command = getchar()) != EOF)
    {
        //维护尾指针
        ptchuan wei = h;
        int newcnt=0;
        while (wei->next != NULL)
        {
            newcnt++;
            wei->next->row=wei->row+1;
            wei = wei->next;
        }
        t = wei;
        //printf("%d",newcnt);
        cnt=newcnt;
        getchar();
        if (command == 'c') //修改
        {
            gets(in);
            int a = 0, b = 0, c = 0; //新串第一位偏移量，/符号偏移量，尾巴偏移量
            char n[max] = {'\0'};    //新串
            char o[max] = {'\0'};    //旧
            int findb=0;
            for (c = 0; c < strlen(in); c++)
            {
                if (in[c] == '/' && in[c - 1] != '\\'&&!findb)
                {
                    b = c; //找b
                    findb=1;
                }
                if (in[c] == '/' && in[c - 1] == '\\') //同时处理转义字符
                {
                    int d = c;
                    for (d; d < strlen(in); d++)
                    {
                        in[d - 1] = in[d];
                    }
                    in[--d] = '\0';
                    ///因为整体前移，所以c要前移
                    c--;
                }
            }
            for (int i = 0; i < b; i++)
            {
                o[i] = in[i];
            }
            for (int i = 0; i < strlen(in) - b; i++)
            {
                n[i] = in[i + b + 1];
            }

            //替换操作
            if (strlen(o) <= 0)
                continue;;
            ptchuan p = h;
            while (p->next != NULL)
            {
                p = p->next;
                int check = strlen(p->data) - strlen(o);

                for (int i = 0; i < strlen(p->data); i++)
                {
                    if (memcmp(&p->data[i], o, strlen(o)) == 0)
                    {
                        char temp[max] = {'\0'};
                        memcpy(temp, &p->data[i + strlen(o)], strlen(&p->data[i + strlen(o)]));
                        p->data[i] = '\0';
                        strcat(p->data, n);
                        i = strlen(p->data) - 1;
                        strcat(p->data, temp);
                    }
                }
            }
            //大概没bug啦
        }
        else if (command == 'i') //插入操作
        {
            int arrow;
            scanf("%d", &arrow);
            getchar();
            gets(in);
            for (int c = 0; c < strlen(in); c++)
            {
                if (in[c] == '/' && in[c - 1] == '\\') //同时处理转义字符
                {
                    int d = c;
                    for (d; d < strlen(in); d++)
                    {
                        in[d - 1] = in[d];
                    }
                    in[--d] = '\0';
                    ///因为整体前移，所以c要前移
                    c--;
                }
            }
            if (arrow > cnt)
            {
                ptchuan p = (ptchuan)malloc(sizeof(chuan));
                p->row = ++cnt;
                strcpy(p->data, in);
                p->next = NULL;
                t->next = p;
                t = p;
            }
            else
            {
                ptchuan q = h;
                ptchuan pre = h;
                int find = 0;
                while (q->next != NULL)
                {
                    q = q->next;
                    if (q->row == arrow)
                    {
                        find = 1;
                        //新节点
                        ptchuan p = (ptchuan)malloc(sizeof(chuan));
                        p->row = arrow;
                        ++cnt;
                        strcpy(p->data, in);
                        p->next = q;
                        pre->next = p;
                    }
                    if (find == 1)
                    {
                        q->row = q->row + 1;
                    }
                    pre = q;
                }
            }
            //大概也没bug了
        }
        else if (command == 'd')
        {
            int arrow;
            int find = 0;
            scanf("%d", &arrow);
            getchar();
            del(arrow);
        }
        else if (command == 'f')
        {
            int arrow[max] = {0};
            char c;
            int deled = 0;
            int j = 0; // o表示被合并的偏移量
            scanf("%d", &arrow[j++]);
            while (~scanf("%c", &c))
            {
                if (c == '\n')
                    break;
                    int f;
                scanf("%d", &f);
                if(f!=arrow[0])
                {
                    arrow[j++]=f;
                }
            }
            if (cnt < arrow[0]||arrow[0]<=0)
            {
                continue;
            }
            else
            {
                ptchuan q = h; //指向被粘贴的串
                while (q->next != NULL)
                {
                    q = q->next;
                    if (q->row == arrow[0])
                    {
                        break;
                    }
                }
                for (int i = 1; i < j; i++)
                {
                    if (cnt < arrow[0])
                    {
                        ;
                    }
                    else
                    {
                        ptchuan l = h;
                        while (l->next != NULL)
                        {
                            l = l->next;
                            if (l->row == arrow[i])
                            {
                                strcat(q->data, l->data);
                                break;
                            }
                        }
                    }
                }
                for (int i = 1; i < j; i++)
                {
                    if (arrow[i] > cnt)
                    {
                        continue;
                    }
                    else
                    {
                        ptchuan q = h;
                        ptchuan pre = h;
                        int find = 0;
                        while (q->next != NULL)
                        {
                            q = q->next;
                            if (q->row == arrow[i])
                            {
                                find = 1;
                                ptchuan del = q;
                                pre->next = q->next;
                                deled++;
                                if (q->next != NULL)
                                    q = q->next;
                                else
                                {
                                    q = pre;
                                }
                                free(del);
                            }
                            pre = q;
                        }
                    }
                }
                q = h;
                ptchuan pre = h;
                while (q->next != NULL)
                {
                    q = q->next;
                    q->row = pre->row + 1;
                    pre = q;
                }
                t = q;
            }
            cnt -= deled;
        }
    }
    while (h->next != NULL)
    {
        h = h->next;
        puts(h->data);
    }
    return 0;
}