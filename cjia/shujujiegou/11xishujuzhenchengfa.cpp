#include <cstdio>
#include <iostream>
using namespace std;
//————稀疏矩阵的行逻辑链接表示法————//
#define MAX_SIZE 1500 //表示稀疏矩阵的非零元素的最大个数
#define MAX_ROW 1500  //表示稀疏矩阵的行数的最大个数
class Triple
{
public:
    int i, j; //表示非零元素的行下表和列下标
    int val;  //非零元素的值，此处以int类型为例
};
class RLSMatrix
{
public:
    Triple data[MAX_SIZE];     //非零元三元组表
    int rpos[MAX_ROW];         //每行第一个非零元素的位置
    int row_num, col_num, cnt; //稀疏矩阵的行数、列数以及非零元素的个数
};

void MultRLSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &rs)
{
    int arow, brow, p, q, ccol, ctemp[MAX_ROW + 1], t, tp;
    if (M.col_num != N.row_num)
    { //不能相乘
        return;
    }
    if (0 == M.cnt * N.cnt)
    { //有一个是零矩阵
        return;
    }
    // rs初始化
    rs.row_num = M.row_num;
    rs.col_num = N.col_num;
    rs.cnt = 0;
    //从M的第一行开始到最后一行，arow是M的当前行
    for (arow = 1; arow <= M.row_num; arow++)
    {
        for (ccol = 1; ccol <= rs.col_num; ccol++)
        {
            ctemp[ccol] = 0; // rs的当前行的各列元素清零
        }
        rs.rpos[arow] = rs.cnt + 1; //开始时从第一个存储位置开始存，后面是基于前面的
        if (arow < M.row_num)
        {
            tp = M.rpos[arow + 1]; //下一行的起始位置
        }
        else
        {
            tp = M.cnt + 1; //最后一行的边界
        }
        for (p = M.rpos[arow]; p < tp; p++)
        {
            //对M当前行的每一个非零元
            //找到对应元素在N中的行号，即M中当前元的列号
            brow = M.data[p].j;
            //原理同上
            if (brow < N.row_num)
            {
                t = N.rpos[brow + 1];
            }
            else
            {
                t = N.cnt + 1;
            }
            for (q = N.rpos[brow]; q < t; q++)
            {
                ccol = N.data[q].j; //乘积元素在rs中列的位置
                ctemp[ccol] += M.data[p].val * N.data[q].val;
            } // for_q
        }     // for_p
        //该压缩存储该行非零元了
        for (ccol = 1; ccol <= rs.col_num; ccol++)
        {
            if (0 != ctemp[ccol])
            {
                if (++rs.cnt > MAX_SIZE)
                { //注意这里有个++
                    return;
                }
                rs.data[rs.cnt].i = arow;
                rs.data[rs.cnt].j = ccol;
                rs.data[rs.cnt].val = ctemp[ccol];
            }
        }
    } // for_arow
}
/*
算法的主要思想如下：

　实际上它的求解过程与1中的算法本质是一样的，只不过充分利用了三元组的性质和rpos数组的信息。为了得到非零元的乘积，只要对M.data[1,2...]中的每个元素即(i,k,M[i]k])
，找到N.data中所有相应的元素(k,j,N[k][j])

相乘即可，为此

只需在N.data中找到矩阵N中第k行的所有非零元；而rpos数组正好提供了相关的信息。rpos[row]表示矩阵N中第row行，第一个非零元在N.data中的序号；而rpos[row+1]-1表示矩阵N中第row行最后一个非零元素在N.data中的序号(因为data数组中存储的全都是非零元素，而rpos[row+1]是第row+1行中第一个非零元素在data中的位置，所以它的前一个位置一定是第row行中最后一个非零元素在data中的位置)。

此外，有几点需要注意：

(1)由于两个稀疏矩阵相乘的结果矩阵不一定是稀疏矩阵，所以结果矩阵的表示方式不一定要用行逻辑链接顺序表，也可以用二维数组。

(2)该算法的时间复杂度具体分析见《数据结构》p103，总之，矩阵越稀疏，该算法时间复杂度越低，能达到O(mp)数量级。
*/