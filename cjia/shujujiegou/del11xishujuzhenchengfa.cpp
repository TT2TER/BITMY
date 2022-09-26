#include <cstdio>
#include <iostream>
using namespace std;
#define DataType int
#define MAXSIZE 12500

typedef struct
{
    int row, col;   //该非零元的行下标和列下标
    DataType value; // 该非零元的值
} Triple;           // 三元组类型

typedef struct
{
    Triple data[MAXSIZE]; //三元数组
    int Rows, Cols;       //行数、列数
    int Terms;            //元素个数
} SparseMatrix;           // 稀疏矩阵类型

// void TranMatrix(SparseMatrix A, SparseMatrix &B)
// { //采用三元组表存储稀疏矩阵，求A的转置矩阵B
//     B.Rows = A.Cols;
//     B.Cols = A.Rows;
//     B.Terms = A.Terms;
//     if (B.Terms <= 0)
//         return;
//     int q = 0; // q为B.data[ ]当前三元组的位置(下标)
//     for (int row = 0; row < B.Rows; ++row)
//         for (int p = 0; p < A.Terms; ++p) // p:扫描A.data指示器
//             if (A.data[p].col == row)
//             {
//                 B.data[q].row = A.data[p].col;
//                 B.data[q].col = A.data[p].row;
//                 B.data[q].value = A.data[p].value;
//                 ++q;
//             }

// } //  TransposeSMtrix
// int FastTransposeSMatrix(SparseMatrix A, SparseMatrix &B)
// {
//     B.Rows = A.Cols;
//     B.Cols = A.Rows;
//     B.Terms = A.Terms; //步骤1
//     if (B.Terms <= 0)
//         return 0;
//     int num[MAXSIZE];
//     int cpot[MAXSIZE];
//     for (int col = 0; col <= A.Cols - 1; ++col)
//         num[col] = 0; //步骤2
//     for (int t = 0; t <= A.Terms - 1; ++t)
//         ++num[A.data[t].row];
//     cpot[1] = 0; //步骤3
//     for (int col = 1; col <= A.Cols; ++col)
//         cpot[col] = cpot[col - 1] + num[col - 1];
//     for (int p = 0; p <= A.Terms - 1; ++p)
//     {
//         int col = A.data[p].col;
//         int q = cpot[col];
//         B.data[q].row = A.data[p].col;
//         B.data[q].col = A.data[p].row;
//         B.data[q].value = A.data[p].value;
//         cpot[col]++;
//     } //步骤4
//     return 1;
// } // FastTransposeSMatrix

int main()
{
    int m = 2;
    SparseMatrix M[m];
    for (int i = 0; i < m; i++)
    {
        int a, b, num;
        scanf("%d\n%d\n%d", &a, &b, &num);

        M[i].Rows = a;
        M[i].Cols = b;
        M[i].Terms = num;
        for (int j = 0; j < num; j++)
        {
            scanf("%d %d %d", &M[i].data[j].row, &M[i].data[j].col, &M[i].data[j].value);
            // printf("%d,%d,%d\n",M[i].data[j].row,M[i].data[j].col,M[i].data[j].value);
        }
    }
    SparseMatrix S;
    // int a=FastTransposeSMatrix( M[1],  S);
    S.Rows = M[0].Rows;
    S.Cols = M[1].Cols;
    S.Terms = 0;
    if (M[0].Terms * M[1].Terms != 0)
    {

        for (int arrow = 1; arrow <= M[0].Rows; arrow++)
        {
            int ctemp[M[0].Rows + 1] = {0};
            
        }
    }
    return 0;
}