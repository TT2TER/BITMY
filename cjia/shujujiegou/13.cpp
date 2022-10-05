#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define TElemType char

typedef struct BiTNode
{ // 结点结构
    TElemType data;
    struct BiTNode *lchild, *rchild;
    // 左右孩子指针
} BiTNode, *BiTree;

void CreateBiTree(BiTree &T, char pre[], int &n) //
{
    char ch = pre[n++];
    if (ch == '\0')
        return; //终止条件
    if (ch == '#')
    {
        T = NULL;
    }
    else
    {
        if (!(T = (BiTree)malloc(sizeof(BiTNode))))
            exit(0);
        T->data = ch;                    // 生成根结点（基本操作）
        CreateBiTree(T->lchild, pre, n); // 构造左子树
        CreateBiTree(T->rchild, pre, n); // 构造右子树
    }                                    // if (ch==‘#') …else

} // CreateBiTree

int CountLeaf(BiTree T)
{
    if (!T)
        return 0;
    if ((!T->lchild) && (!T->rchild)) //终止条件
        return 1;
    return CountLeaf(T->lchild) + CountLeaf(T->rchild);
} // CountLeaf

void visit(BiTNode T)
{
    printf("%c", T.data);
}

void Preorder(BiTree T)
{
    if (T == NULL)
        return;
    visit(*T);
    Preorder(T->lchild);
    Preorder(T->rchild);
}

void Preorderprint(BiTree T, int deep)
{
    if (T == NULL)
        return;
    for (int i = 0; i < deep * 4; i++)
        printf(" ");
    printf("%c\n", T->data);
    deep++;
    Preorderprint(T->lchild, deep);
    Preorderprint(T->rchild, deep);
}

void Inorder(BiTree T)
{
    if (T == NULL)
        return;
    Inorder(T->lchild);
    visit(*T);
    Inorder(T->rchild);
}

void Postorder(BiTree T)
{
    if (T == NULL)
        return;
    Postorder(T->lchild);
    Postorder(T->rchild);
    visit(*T);
}

void print(BiTree root)
{
    int deep = 0;
    Preorderprint(root, deep);
    printf("pre_sequence  : ");
    Preorder(root);
    printf("\n");
    printf("in_sequence   : ");
    Inorder(root);
    printf("\n");
    printf("post_sequence : ");
    Postorder(root);
    printf("\n");
}
void ChangeChild(BiTree T)
{
    if(T==NULL)
    return;
    BiTree temp;
    ChangeChild(T->lchild);
    ChangeChild(T->rchild);
    temp=T->lchild;
    T->lchild=T->rchild;
    T->rchild=temp;
}

int main()
{
    char in[100];
    BiTree root = NULL;
    gets(in);
    int st = 0;
    printf("BiTree\n");
    CreateBiTree(root, in, st);
    print(root);
    printf("Number of leaf: %d\n", CountLeaf(root));
    ChangeChild(root);
    printf("BiTree swapped\n");
    print(root);
    return 0;
}
