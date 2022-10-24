#include <cstdio>
#include <iostream>
#include <cmath>

#define MAXVEX 11			 // 最大顶点数
#define GRAPH_INFINITY 65535 /* 用65535来代表∞ */
#define MAXSIZE 1000		 /* 存储空间初始分配量 */

typedef int VertexType;
typedef int EdgeType;
typedef struct
{
	VertexType vexs[MAXVEX];	  /* 顶点表 */
	EdgeType arc[MAXVEX][MAXVEX]; /* 邻接矩阵，可看作边表 */
	int numNodes, numEdges;		  /* 图中当前的顶点数和边数  */
} MGraph;

void CreateMGraph(MGraph *G)
{
	int i, j, k, w = 1;
	scanf("%d", &G->numNodes); //读边
	for (i = 0; i < G->numNodes; i++)
	{
		G->vexs[i] = i;
	}
	for (i = 0; i < G->numNodes; i++)
		for (j = 0; j < G->numNodes; j++)
			G->arc[i][j] = GRAPH_INFINITY; /* 邻接矩阵初始化 */

	scanf("%d", &i);
	while (i != -1)
	{
		scanf("%d", &j);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j]; /* 因为是无向图，矩阵对称 */
		G->numEdges++;
		scanf("%d", &i);
	}
}

/* 循环队列的顺序存储结构 */
typedef struct
{
	int data[MAXSIZE];
	int front; /* 头指针 */
	int rear;  /* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
} Queue;

/* 初始化一个空队列Q */
int InitQueue(Queue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return 1;
}

/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
int QueueEmpty(Queue Q)
{
	if (Q.front == Q.rear) /* 队列空的标志 */
		return 1;
	else
		return 0;
}

/* 若队列未满，则插入元素e为Q新的队尾元素 */
int EnQueue(Queue *Q, int e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) /* 队列满的判断 */
		return 0;
	Q->data[Q->rear] = e;			   /* 将元素e赋值给队尾 */
	Q->rear = (Q->rear + 1) % MAXSIZE; /* rear指针向后移一位置， */
									   /* 若到最后则转到数组头部 */
	return 1;
}

/* 若队列不空，则删除Q中队头元素，用e返回其值 */
int DeQueue(Queue *Q, int *e)
{
	if (Q->front == Q->rear) /* 队列空的判断 */
		return 0;
	*e = Q->data[Q->front];				 /* 将队头元素赋值给e */
	Q->front = (Q->front + 1) % MAXSIZE; /* front指针向后移一位置， */
										 /* 若到最后则转到数组头部 */
	return 1;
}
/* ****************************************************** */

int visited[MAXVEX]; /* 访问标志的数组 */

/* 邻接矩阵的广度遍历算法 */
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for (i = 0; i < G.numNodes; i++)
		visited[i] = 0;
	InitQueue(&Q);					 /* 初始化一辅助用的队列 */
	for (i = 0; i < G.numNodes; i++) /* 对每一个顶点做循环 */
	{
		if (!visited[i]) /* 若是未访问过就处理 */
		{
			visited[i] = 1;			  /* 设置当前顶点访问过 */
			if(i==0)
			{
				;
			}
			else
			printf("\n");
			printf("%d", G.vexs[i]); /* 打印顶点，也可以其它操作 */
			EnQueue(&Q, i);			  /* 将此顶点入队列 */
			int ii;
			while (!QueueEmpty(Q))	  /* 若当前队列不为空 */
			{
				DeQueue(&Q, &ii); /* 将队对元素出队列，赋值给ii */
				for (j = 0; j < G.numNodes; j++)
				{
					/* 判断其它顶点若与当前顶点存在边且未访问过  */
					if (G.arc[ii][j] == 1 && !visited[j])
					{
						visited[j] = 1;			  /* 将找到的此顶点标记为已访问 */
						printf("-%d", G.vexs[j]); /* 打印顶点 */
						EnQueue(&Q, j);			  /* 将找到的此顶点入队列  */
					}
				}
			}
		}
	}
	printf("\n");
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	BFSTraverse(G);
	return 0;
}
