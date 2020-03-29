#include <iostream>
#include <string>
using namespace std;
//�����Ķ�������ϵ
//          A
//        /   \
//       B     F
//        \     \
//         C     G
//        / \   /
//       D   E  H  



struct bineryNode
{
	char ch; //������
	struct bineryNode * Lchild; //���ӽڵ�
	struct bineryNode * Rchild; //���ӽڵ�

};

//�ݹ��������
void recursion(struct bineryNode * node)
{
	if (node == NULL)
	{
		return;
	}

	//������� �ȸ� ���� ����
	cout << node->ch << " ";

	recursion(node->Lchild);
	
	recursion(node->Rchild);
}
//ͳ�Ƹ��ڵ����
void cacu_leafnum(struct bineryNode * node,int & num)
{
	//�ݹ��������
	if (node == NULL)
	{
		return;
	}
	//���Ҹ��ڵ�
	if (node->Lchild == NULL && node->Rchild == NULL)
	{
		cout << node->ch << " ";
		num++;
	}

	cacu_leafnum(node->Lchild, num);
	cacu_leafnum(node->Rchild, num);
}
//�����������
int gettreedeep(struct bineryNode * node)
{
	//�ݹ��������
	if (node == NULL)
	{
		return NULL;
	}

	//�����������������ĸ߶�
	int Ldeep = gettreedeep(node->Lchild);
	int Rdeep = gettreedeep(node->Rchild);

	//ȡ�������ֵ
	int deep = Ldeep > Rdeep ? Ldeep + 1 : Rdeep + 1;

	return deep;
}

//������
struct bineryNode * copybinerytree(struct bineryNode * node)
{
	//�ݹ��������
	if (node == NULL)
	{
		return NULL;
	}
	//�ȿ���������
	struct bineryNode * Lcopy = copybinerytree(node->Lchild);
	//�ٿ���������
	struct bineryNode * Rcopy = copybinerytree(node->Rchild);
	//�����½ڵ� 
	struct bineryNode * newnode = new struct bineryNode;

	//��ʼ����
	newnode->Lchild = Lcopy;
	newnode->Rchild = Rcopy;
	newnode->ch = node->ch;

	return newnode;
}
//�ͷŶ����� �����ͷ�
void freetree(struct bineryNode * node)
{
	if (node == NULL)
	{
		return;
	}
	//�ͷ���ڵ�
	freetree(node->Lchild);
	//�ͷ��ҽڵ�
	freetree(node->Rchild);
	//�ͷŸ��ڵ�
	delete node;
	node = NULL;
}

void test01()
{
	struct bineryNode nodeA = { 'A',NULL,NULL };
	struct bineryNode nodeB = { 'B',NULL,NULL };
	struct bineryNode nodeC = { 'C',NULL,NULL };
	struct bineryNode nodeD = { 'D',NULL,NULL };
	struct bineryNode nodeE = { 'E',NULL,NULL };
	struct bineryNode nodeF = { 'F',NULL,NULL };
	struct bineryNode nodeG = { 'G',NULL,NULL };
	struct bineryNode nodeH = { 'H',NULL,NULL };

	//������ϵ
	nodeA.Lchild = &nodeB;
	nodeA.Rchild = &nodeF;

	nodeB.Rchild = &nodeC;

	nodeC.Lchild = &nodeD;
	nodeC.Rchild = &nodeE;

	nodeF.Rchild = &nodeG;

	nodeG.Lchild = &nodeH;

	//�ݹ����
	recursion(&nodeA);
	cout << endl;

	//����Ҷ�ӽڵ�����
	int num = 0;
	cacu_leafnum(&nodeA,num);
	cout << " Ҷ�ӽڵ������" << num << endl;

	//�������
	int deep = 0;
	gettreedeep(&nodeA);
	cout << "�������Ϊ��" << gettreedeep(&nodeA) << endl;

	//����������
	struct bineryNode * newtree = copybinerytree(&nodeA);
	//�ݹ����
	recursion(newtree);
	cout << endl;

	//�ͷŶ�����
	freetree(newtree);
	
}

int main()
{
	test01();
	system("pause");
	return 0;
}