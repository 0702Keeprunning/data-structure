//#include <iostream>
//
//using namespace std;
///* 状态 */
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//typedef int status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */ 
//typedef int boolean;/* Boolean是布尔类型,其值是TRUE或FALSE */
//
//typedef char vertextype; /* 顶点类型应由用户定义 */
//typedef int edgetype;	/* 边上的权值类型应由用户定义 */
//
//#define MAXSIZE 9 /* 存储空间初始分配量 */
//#define MAXEDGE 15
//#define MAXVEX 9
//#define INFINITY 65535
//
//struct MGraph
//{
//	vertextype vexs[MAXVEX];/* 顶点表 */
//	edgetype arc[MAXVEX][MAXVEX];/* 邻接矩阵，可看作边表 */
//	int numVertexes, numEdges; /* 图中当前的顶点数和边数 */
//};
//void CreateMGraph(MGraph *G)
//{
//	int i, j;
//
//	G->numEdges = 15;
//	G->numVertexes = 9;
//
//	/* 读入顶点信息，建立顶点表 */
//	G->vexs[0] = 'A';
//	G->vexs[1] = 'B';
//	G->vexs[2] = 'C';
//	G->vexs[3] = 'D';
//	G->vexs[4] = 'E';
//	G->vexs[5] = 'F';
//	G->vexs[6] = 'G';
//	G->vexs[7] = 'H';
//	G->vexs[8] = 'I';
//
//
//	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
//	{
//		for (j = 0; j < G->numVertexes; j++)
//		{
//			if (i == j)
//				G->arc[i][j] = 0;
//			else
//				G->arc[i][j] = G->arc[j][i] = INFINITY;
//		}
//	}
//
//	G->arc[0][1] = 1;
//	G->arc[0][5] = 1;
//
//	G->arc[1][2] = 1;
//	G->arc[1][8] = 1;
//	G->arc[1][6] = 1;
//
//	G->arc[2][3] = 1;
//	G->arc[2][8] = 1;
//
//	G->arc[3][4] = 1;
//	G->arc[3][7] = 1;
//	G->arc[3][6] = 1;
//	G->arc[3][8] = 1;
//
//	G->arc[4][5] = 1;
//	G->arc[4][7] = 1;
//
//	G->arc[5][6] = 1;
//
//	G->arc[6][7] = 1;
//
//
//	for (i = 0; i < G->numVertexes; i++)
//	{
//		for (j = i; j < G->numVertexes; j++)
//		{
//			G->arc[j][i] = G->arc[i][j];
//		}
//	}
//
//}
//
//boolean visited[MAXVEX]; //代表访问状态的数组 改下标为0表示未访问到  为1表示访问到
//
////邻接矩阵的深度优先递归算法
//void DFS(MGraph *G, int i)
//{
//	int j; //代表i点的下一个邻接点的位置
//	visited[i] = TRUE; //先标记一下该位置已经被访问到
//	cout << G->vexs[i] << " "; //输出一下该顶点数据
//	for (j = 0; j < G->numVertexes; j++)
//	{
//		if (G->arc[i][j] == 1 && !visited[j]) //如果i j两点有边 且 j处没有没访问到
//		{
//			DFS(G, j);  //进入j点 继续递归找一下个邻接点
//		}
//	}
//}
////邻接矩阵的深度优先遍历操作
//void DFSforeach(MGraph *G)
//{
//	int i;
//	for (i = 0; i < G->numVertexes; i++)
//		visited[i] = FALSE;	/* 初始所有顶点状态都是未访问过状态 */
//	for (i = 0; i < G->numVertexes; i++)
//		if (!visited[i])	/* 对未访问过的顶点调用DFS，若是连通图，只会执行一次 */
//			DFS(G, i);
//}
//
////* 用到的队列结构与函数********************************** */
//struct queue
//{
//	int data[MAXSIZE];
//	int front;	/* 头指针 */
//	int back;	/* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
//};
///* 初始化一个空队列q */
//status initqueue(queue *q)
//{
//	q->front = 0;
//	q->back = 0;
//	return OK;
//}
///* 若队列q为空队列,则返回TRUE,否则返回FALSE */
//status queue_empyt(queue *q)
//{
//	if (q->front == q->back)
//		return TRUE;
//	else
//		return FALSE;
//}
///* 若队列未满，则插入元素e为q新的队尾元素 */
//status insert_queue(queue *q, int e)
//{
//	if (q->front + 1 == 10)	/* 队列满的判断 */
//		return ERROR;
//	q->data[q->back] = e;
//	q->back = q->back + 1;
//	if (q->back > 9)
//		q->back = 0;
//	return OK;
//
//}
///* 若队列不空，则删除Q中队头元素，用e返回其值 */
//status remove_queue(queue *q, int *e)
//{
//	if (q->front == q->back)
//		return ERROR;
//	*e = q->data[q->front];
//	q->front = q->front + 1;
//	if (q->front > 9)
//		q->front = 0;
//	return OK;
//}
//
///* 邻接矩阵的广度优先遍历算法 */
//void BFSforeach(MGraph *G)
//{
//	int i, j;
//	queue q;
//	for (i = 0; i < G->numVertexes; i++)
//		visited[i] = FALSE;
//	initqueue(&q);/* 初始化一辅助用的队列 */
//	for (i = 0; i < G->numVertexes; i++)  /* 对每一个顶点做循环 */
//	{
//		if (!visited[i])	/* 若是未访问过就处理 */
//		{
//			visited[i] = TRUE;		/* 设置当前顶点访问过 */
//			cout << G->vexs[i] << " ";
//			insert_queue(&q, i);	/* 将此顶点入队列 */
//			while (!queue_empyt(&q))/* 若当前队列不为空 */
//			{
//				remove_queue(&q, &i);/* 将队头元素出队列，赋值给i */
//
//				for (j = 0; j < G->numVertexes; j++)
//				{
//					/* 判断其它顶点若与当前顶点存在边且未访问过  */
//					if (G->arc[i][j] == 1 && !visited[j])
//					{
//						visited[j] = TRUE;			/* 将找到的此顶点标记为已访问 */
//						cout << G->vexs[j] << " ";		/* 打印顶点 */
//						insert_queue(&q, j);		/* 将找到的此顶点入队列  */
//					}
//				}
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	MGraph G;
//	CreateMGraph(&G);
//	cout << "深度优先遍历" << endl;
//	DFSforeach(&G);
//	cout << endl;
//	BFSforeach(&G);
//	cout << endl;
//	system("pause");
//	return 0;
//}