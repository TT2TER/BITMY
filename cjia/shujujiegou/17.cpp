#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef struct treenode
{
    char data;
    int parents;
    int degree;
} Tnode;

int CreateTree(char in[100], Tnode tree[100], int list[100])
{
    int i, j, k = 1, len, kuo = 0;
    len = strlen(in);
    if (in[0] == '('&&in[1]==')')
    {
        return 0;
    }
    tree[0].data = in[1];
        tree[0].parents = -1;
        list[0] = 1;

    for (i = 0; i < len; i++)
    {
        tree[i].data = in[i];
        tree[i].parents = -1;
        tree[i].degree = 0;
    }

    for (i = 2; i < len - 1; i++)
    {
        if (in[i] == ',' || in[i] == '(' || in[i] == ')')
        {
            continue;
        }
        else
        {
            for (j = i, kuo = 0; j >= 0 && kuo != 2; j--)
            {
                if (in[j] == '(')
                {
                    kuo++;
                    if (kuo == 2)
                    {
                        break;
                    }
                }
                else if (in[j] == ')')
                {
                    kuo--;
                }
            }
            tree[i].data = in[i];
            tree[i].parents = j + 1;
            tree[j + 1].degree++;
            list[k++] = i;
        }
    }
    return k;
}

void PrintTree(Tnode tree[100], int list[100], int i)
{
    int space = 0, j = i;
    if (i == 0)
    {
        printf("%c\n", tree[list[i]].data);
        return;
    }
    i = list[i];
    while (tree[i].parents != -1)
    {
        space += 4;
        i = tree[i].parents;
    }
    for (i = 0; i < space; i++)
    {
        printf(" ");
    }
    printf("%c\n", tree[list[j]].data);
}

int main()
{
    int i, j, k, n, max, degree[100], list[100];
    char in[100];
    Tnode tree[100];

    gets(in);
    n = CreateTree(in, tree, list);
    for (i = 0, max = 0; i < n; i++)
    {
        PrintTree(tree, list, i);
        if (tree[list[i]].degree > max)
        {
            max = tree[list[i]].degree;
        }
    }
    for (i = 0; i <= max; i++)
    {
        degree[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        degree[tree[list[i]].degree]++;
    }
    printf("Degree of tree: %d\n", max);
    for (i = 0; i <= max; i++)
    {
        printf("Number of nodes of degree %d: %d\n", i, degree[i]);
    }
    return 0;
}