void multiplication(NODE *a, NODE *b, NODE *c)
{

    NODE *p1, *p2, *p3;
    p1 = p2 = p3 = c;//p1用于建立第一个结点，p3记录上一次的结点位置:帮助p2寻找指数对应位置的结点
    NODE *aa = a->next, *bb = b->next;
    int s = 0, e = 0;
    

    while(aa != NULL)
    {
        while(bb != NULL)
        {
            s = aa->coef * bb->coef;
            if (s == 0)
            {
                bb = bb->next;
                continue;
            }

            e = aa->exp + bb->exp;

            if (p1->next == NULL)
            {
                NODE *t = (NODE*)malloc(sizeof(NODE));
                t->coef = s;
                t->exp = e;
                t->next = NULL;

                p1->next = t;
            }
            else
            {
                if(p3->next != NULL && e > p3->next->exp)
                {//和上一次的比较，优化插入过程，如果比上一次cha入的大：
                    p2 = p3;

                    while(p2->next != NULL && e > p2->next->exp)
                    {
                        p2 = p2->next;
                        p3 = p2;
                    }
                }
                else
                {
                    while(p2->next != NULL && e > p2->next->exp)
                    {
                        p2 = p2->next;
                        p3 = p2;
                    }
                }

                NODE *temp = p2->next;//temp是标记p2，处理待插入
                if(p2->next == NULL)
                {
                    NODE *t = (NODE*)malloc(sizeof(NODE));
                    t->coef = s;
                    t->exp = e;
                    t->next = NULL;

                    p2->next = t;
                }
                else if(temp->exp == e)
                {
                    temp->coef += s;
                    if(temp->coef == 0)
                    {
                        NODE *dele = temp->next;
                        p2->next = dele;
                        free(temp);
                    }
                }
                else if(temp->exp > e)
                {
                    NODE *t = (NODE*)malloc(sizeof(NODE));
                    t->coef = s;
                    t->exp = e;

                    p2->next = t;
                    t->next = temp;
                }
            }
            
            bb = bb->next;
            p2 = c;//初始化p2
        }
        
        bb = b->next;
        aa = aa->next;
    }

    
    if(c->next == NULL)
    {
        NODE *t = (NODE*)malloc(sizeof(NODE));
        t->coef = 0;
        t->exp = 0;
        t->next = NULL;

        c->next = t;
    }
    return;
}