Status ListInsert(SqList &L, int i, ElemType e)
{ //在顺序线性表L中第 i (1≤i≤L.length+1)个位置之前插入元素e,
    if (1 <= i && i <= L.listsize)
    {
        if (L.length >= L.listsize)
            return ERROR;
        for (int j = L.listsize; j > i; j--)
            L.elem[j-1] = L.elem[j - 1-1];
        L.elem[i-1] = e;
        L.length++;
        return OK;
    }
    else
        return ERROR;
}

Status GetElem(SqList L, int i, ElemType &e)
{
    if (i <= L.length && i >= 1)
        e = L.elem[i - 1];
    else
        return ERROR;
    return OK;
}

int ListLength(SqList L)
{
    return L.length;
}