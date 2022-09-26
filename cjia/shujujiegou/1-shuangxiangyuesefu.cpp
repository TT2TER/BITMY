#include <cstdio>
#include <cstdlib>
int n, m, k;
typedef struct DuLNode
{
    int data;
    struct DuLNode *prior;
    struct DuLNode *next;
} node, *list;
void Create(list &head)
{
    list present, before;
    int i;
    head = (list)malloc(sizeof(node));
    before = head;
    for (i = 1; i <= n; i++)
    {
        present = (list)malloc(sizeof(node));
        present->data = i;
        present->prior = before;
        before->next = present;
        before = present;
    }
    present->next = head;
    head->prior = present;
}
void Delete(list &P)
{
    P->prior->next = P->next;
    P->next->prior = P->prior;
}
int main()
{
    int i;
    list head, l, R, right, left;
    bool good = true;
    scanf("%d,%d,%d", &n, &k, &m);

    if (!(n && k && m) && good)
    {
        printf("n,m,k must bigger than 0.");
        good = false;
    }
    if (k > n && good)
    {
        printf("k should not bigger than n.");
        good = false;
    }

    if (good)
    {
        Create(head);

        R = head->next;
        while (R->data != k)
        { //找到k
            R = R->next;
        }
        l = R; //初始化

        for (int j = n; j; j)
        {
            right = R;
            left = l;

            for (i = 1; i < m; i++)
            {
                right = right->next;
                left = left->prior;
                if (right == head)
                    right = right->next;
                if (left == head)
                    left = left->prior;
            }

            //下一次的开始
            R = right->next;
            l = left->prior;
            if (R == head)
                R = R->next;
            if (l == head)
                l = l->prior;

            if (right != left)
            {
                j = j - 2;
                printf("%d-%d,", right->data, left->data);
                Delete(right);
                Delete(left);
            }
            else
            {
                j = j - 1;
                printf("%d,", right->data);
                Delete(right);
            }
        }
    }

    printf("\n");
    return 0;
}