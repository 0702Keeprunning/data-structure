#include <iostream>
#include <string>
using namespace std;
//构建的二叉树关系
//          A
//        /   \
//       B     F
//        \     \
//         C     G
//        / \   /
//       D   E  H  



struct bineryNode
{
	char ch; //数据域
	struct bineryNode * Lchild; //左子节点
	struct bineryNode * Rchild; //右子节点

};

//递归遍历函数
void recursion(struct bineryNode * node)
{
	if (node == NULL)
	{
		return;
	}

	//先序遍历 先根 左子 右子
	cout << node->ch << " ";

	recursion(node->Lchild);
	
	recursion(node->Rchild);
}
//统计根节点个数
void cacu_leafnum(struct bineryNode * node,int & num)
{
	//递归结束条件
	if (node == NULL)
	{
		return;
	}
	//查找根节点
	if (node->Lchild == NULL && node->Rchild == NULL)
	{
		cout << node->ch << " ";
		num++;
	}

	cacu_leafnum(node->Lchild, num);
	cacu_leafnum(node->Rchild, num);
}
//计算树的深度
int gettreedeep(struct bineryNode * node)
{
	//递归结束条件
	if (node == NULL)
	{
		return NULL;
	}

	//求左子树和右子树的高度
	int Ldeep = gettreedeep(node->Lchild);
	int Rdeep = gettreedeep(node->Rchild);

	//取两者最高值
	int deep = Ldeep > Rdeep ? Ldeep + 1 : Rdeep + 1;

	return deep;
}

//拷贝树
struct bineryNode * copybinerytree(struct bineryNode * node)
{
	//递归结束条件
	if (node == NULL)
	{
		return NULL;
	}
	//先拷贝左子树
	struct bineryNode * Lcopy = copybinerytree(node->Lchild);
	//再拷贝右子树
	struct bineryNode * Rcopy = copybinerytree(node->Rchild);
	//创建新节点 
	struct bineryNode * newnode = new struct bineryNode;

	//开始拷贝
	newnode->Lchild = Lcopy;
	newnode->Rchild = Rcopy;
	newnode->ch = node->ch;

	return newnode;
}
//释放二叉树 后序释放
void freetree(struct bineryNode * node)
{
	if (node == NULL)
	{
		return;
	}
	//释放左节点
	freetree(node->Lchild);
	//释放右节点
	freetree(node->Rchild);
	//释放根节点
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

	//建立关系
	nodeA.Lchild = &nodeB;
	nodeA.Rchild = &nodeF;

	nodeB.Rchild = &nodeC;

	nodeC.Lchild = &nodeD;
	nodeC.Rchild = &nodeE;

	nodeF.Rchild = &nodeG;

	nodeG.Lchild = &nodeH;

	//递归遍历
	recursion(&nodeA);
	cout << endl;

	//树中叶子节点数量
	int num = 0;
	cacu_leafnum(&nodeA,num);
	cout << " 叶子节点个数：" << num << endl;

	//树的深度
	int deep = 0;
	gettreedeep(&nodeA);
	cout << "树的深度为：" << gettreedeep(&nodeA) << endl;

	//拷贝二叉树
	struct bineryNode * newtree = copybinerytree(&nodeA);
	//递归遍历
	recursion(newtree);
	cout << endl;

	//释放二叉树
	freetree(newtree);
	
}

int main()
{
	test01();
	system("pause");
	return 0;
}