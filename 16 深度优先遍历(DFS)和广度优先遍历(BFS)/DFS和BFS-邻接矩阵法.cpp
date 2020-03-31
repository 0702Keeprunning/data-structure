//#include <iostream>
//
//using namespace std;
///* ״̬ */
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//typedef int status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */ 
//typedef int boolean;/* Boolean�ǲ�������,��ֵ��TRUE��FALSE */
//
//typedef char vertextype; /* ��������Ӧ���û����� */
//typedef int edgetype;	/* ���ϵ�Ȩֵ����Ӧ���û����� */
//
//#define MAXSIZE 9 /* �洢�ռ��ʼ������ */
//#define MAXEDGE 15
//#define MAXVEX 9
//#define INFINITY 65535
//
//struct MGraph
//{
//	vertextype vexs[MAXVEX];/* ����� */
//	edgetype arc[MAXVEX][MAXVEX];/* �ڽӾ��󣬿ɿ����߱� */
//	int numVertexes, numEdges; /* ͼ�е�ǰ�Ķ������ͱ��� */
//};
//void CreateMGraph(MGraph *G)
//{
//	int i, j;
//
//	G->numEdges = 15;
//	G->numVertexes = 9;
//
//	/* ���붥����Ϣ����������� */
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
//	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
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
//boolean visited[MAXVEX]; //�������״̬������ ���±�Ϊ0��ʾδ���ʵ�  Ϊ1��ʾ���ʵ�
//
////�ڽӾ����������ȵݹ��㷨
//void DFS(MGraph *G, int i)
//{
//	int j; //����i�����һ���ڽӵ��λ��
//	visited[i] = TRUE; //�ȱ��һ�¸�λ���Ѿ������ʵ�
//	cout << G->vexs[i] << " "; //���һ�¸ö�������
//	for (j = 0; j < G->numVertexes; j++)
//	{
//		if (G->arc[i][j] == 1 && !visited[j]) //���i j�����б� �� j��û��û���ʵ�
//		{
//			DFS(G, j);  //����j�� �����ݹ���һ�¸��ڽӵ�
//		}
//	}
//}
////�ڽӾ����������ȱ�������
//void DFSforeach(MGraph *G)
//{
//	int i;
//	for (i = 0; i < G->numVertexes; i++)
//		visited[i] = FALSE;	/* ��ʼ���ж���״̬����δ���ʹ�״̬ */
//	for (i = 0; i < G->numVertexes; i++)
//		if (!visited[i])	/* ��δ���ʹ��Ķ������DFS��������ͨͼ��ֻ��ִ��һ�� */
//			DFS(G, i);
//}
//
////* �õ��Ķ��нṹ�뺯��********************************** */
//struct queue
//{
//	int data[MAXSIZE];
//	int front;	/* ͷָ�� */
//	int back;	/* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */
//};
///* ��ʼ��һ���ն���q */
//status initqueue(queue *q)
//{
//	q->front = 0;
//	q->back = 0;
//	return OK;
//}
///* ������qΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
//status queue_empyt(queue *q)
//{
//	if (q->front == q->back)
//		return TRUE;
//	else
//		return FALSE;
//}
///* ������δ���������Ԫ��eΪq�µĶ�βԪ�� */
//status insert_queue(queue *q, int e)
//{
//	if (q->front + 1 == 10)	/* ���������ж� */
//		return ERROR;
//	q->data[q->back] = e;
//	q->back = q->back + 1;
//	if (q->back > 9)
//		q->back = 0;
//	return OK;
//
//}
///* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */
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
///* �ڽӾ���Ĺ�����ȱ����㷨 */
//void BFSforeach(MGraph *G)
//{
//	int i, j;
//	queue q;
//	for (i = 0; i < G->numVertexes; i++)
//		visited[i] = FALSE;
//	initqueue(&q);/* ��ʼ��һ�����õĶ��� */
//	for (i = 0; i < G->numVertexes; i++)  /* ��ÿһ��������ѭ�� */
//	{
//		if (!visited[i])	/* ����δ���ʹ��ʹ��� */
//		{
//			visited[i] = TRUE;		/* ���õ�ǰ������ʹ� */
//			cout << G->vexs[i] << " ";
//			insert_queue(&q, i);	/* ���˶�������� */
//			while (!queue_empyt(&q))/* ����ǰ���в�Ϊ�� */
//			{
//				remove_queue(&q, &i);/* ����ͷԪ�س����У���ֵ��i */
//
//				for (j = 0; j < G->numVertexes; j++)
//				{
//					/* �ж������������뵱ǰ������ڱ���δ���ʹ�  */
//					if (G->arc[i][j] == 1 && !visited[j])
//					{
//						visited[j] = TRUE;			/* ���ҵ��Ĵ˶�����Ϊ�ѷ��� */
//						cout << G->vexs[j] << " ";		/* ��ӡ���� */
//						insert_queue(&q, j);		/* ���ҵ��Ĵ˶��������  */
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
//	cout << "������ȱ���" << endl;
//	DFSforeach(&G);
//	cout << endl;
//	BFSforeach(&G);
//	cout << endl;
//	system("pause");
//	return 0;
//}