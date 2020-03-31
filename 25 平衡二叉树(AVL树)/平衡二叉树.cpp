#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */


/* 二叉树的二叉链表结点结构定义 */
typedef  struct BiTNode	/* 结点结构 */
{
	int data;	/* 结点数据 */
	int bf; /*  结点的平衡因子 */
	struct BiTNode *lchild, *rchild;	/* 左右孩子指针 */
} BiTNode, *BiTree;


/* 对以p为根的二叉排序树作右旋处理， */
/* 处理之后p指向新的树根结点，即旋转处理之前的左子树的根结点 */
void R_Rotate(BiTree *P)
{
	BiTree L;
	L = (*P)->lchild; /*  L指向P的左子树根结点 */
	(*P)->lchild = L->rchild; /*  L的右子树挂接为P的左子树 */
	L->rchild = (*P);
	*P = L; /*  P指向新的根结点 */
}

/* 对以P为根的二叉排序树作左旋处理， */
/* 处理之后P指向新的树根结点，即旋转处理之前的右子树的根结点0  */
void L_Rotate(BiTree *P)
{
	BiTree R;
	R = (*P)->rchild; /*  R指向P的右子树根结点 */
	(*P)->rchild = R->lchild; /* R的左子树挂接为P的右子树 */
	R->lchild = (*P);
	*P = R; /*  P指向新的根结点 */
}

#define LH +1 /*  左高 */ 
#define EH 0  /*  等高 */ 
#define RH -1 /*  右高 */ 

/*  对以指针T所指结点为根的二叉树作左平衡旋转处理 */
/*  本算法结束时，指针T指向新的根结点 */
void LeftBalance(BiTree *T)
{
	BiTree L, Lr;
	L = (*T)->lchild; /*  L指向T的左子树根结点 */
	switch (L->bf)
	{ /*  检查T的左子树的平衡度，并作相应平衡处理 */
	case LH: /*  新结点插入在T的左孩子的左子树上，要作单右旋处理 */
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH: /*  新结点插入在T的左孩子的右子树上，要作双旋处理 */
		Lr = L->rchild; /*  Lr指向T的左孩子的右子树根 */
		switch (Lr->bf)
		{ /*  修改T及其左孩子的平衡因子 */
		case LH: (*T)->bf = RH;
			L->bf = EH;
			break;
		case EH: (*T)->bf = L->bf = EH;
			break;
		case RH: (*T)->bf = EH;
			L->bf = LH;
			break;
		}
		Lr->bf = EH;
		L_Rotate(&(*T)->lchild); /*  对T的左子树作左旋平衡处理 */
		R_Rotate(T); /*  对T作右旋平衡处理 */
	}
}

/*  对以指针T所指结点为根的二叉树作右平衡旋转处理， */
/*  本算法结束时，指针T指向新的根结点 */
void RightBalance(BiTree *T)
{
	BiTree R, Rl;
	R = (*T)->rchild; /*  R指向T的右子树根结点 */
	switch (R->bf)
	{ /*  检查T的右子树的平衡度，并作相应平衡处理 */
	case RH: /*  新结点插入在T的右孩子的右子树上，要作单左旋处理 */
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
	case LH: /*  新结点插入在T的右孩子的左子树上，要作双旋处理 */
		Rl = R->lchild; /*  Rl指向T的右孩子的左子树根 */
		switch (Rl->bf)
		{ /*  修改T及其右孩子的平衡因子 */
		case RH: (*T)->bf = LH;
			R->bf = EH;
			break;
		case EH: (*T)->bf = R->bf = EH;
			break;
		case LH: (*T)->bf = EH;
			R->bf = RH;
			break;
		}
		Rl->bf = EH;
		R_Rotate(&(*T)->rchild); /*  对T的右子树作右旋平衡处理 */
		L_Rotate(T); /*  对T作左旋平衡处理 */
	}
}

/*  若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个 */
/*  数据元素为e的新结点，并返回1，否则返回0。若因插入而使二叉排序树 */
/*  失去平衡，则作平衡旋转处理，布尔变量taller反映T长高与否。 */
Status InsertAVL(BiTree *T, int e, Status *taller)
{
	if (!*T)
	{ /*  插入新结点，树“长高”，置taller为TRUE */
		*T = (BiTree)new BiTNode;
		(*T)->data = e; (*T)->lchild = (*T)->rchild = NULL; (*T)->bf = EH;
		*taller = TRUE;
	}
	else
	{
		if (e == (*T)->data)
		{ /*  树中已存在和e有相同关键字的结点则不再插入 */
			*taller = FALSE; return FALSE;
		}
		if (e < (*T)->data)
		{ /*  应继续在T的左子树中进行搜索 */
			if (!InsertAVL(&(*T)->lchild, e, taller)) /*  未插入 */
				return FALSE;
			if (*taller) /*   已插入到T的左子树中且左子树“长高” */
				switch ((*T)->bf) /*  检查T的平衡度 */
				{
				case LH: /*  原本左子树比右子树高，需要作左平衡处理 */
					LeftBalance(T);	*taller = FALSE; break;
				case EH: /*  原本左、右子树等高，现因左子树增高而使树增高 */
					(*T)->bf = LH; *taller = TRUE; break;
				case RH: /*  原本右子树比左子树高，现左、右子树等高 */
					(*T)->bf = EH; *taller = FALSE; break;
				}
		}
		else
		{ /*  应继续在T的右子树中进行搜索 */
			if (!InsertAVL(&(*T)->rchild, e, taller)) /*  未插入 */
				return FALSE;
			if (*taller) /*  已插入到T的右子树且右子树“长高” */
				switch ((*T)->bf) /*  检查T的平衡度 */
				{
				case LH: /*  原本左子树比右子树高，现左、右子树等高 */
					(*T)->bf = EH; *taller = FALSE;	break;
				case EH: /*  原本左、右子树等高，现因右子树增高而使树增高  */
					(*T)->bf = RH; *taller = TRUE; break;
				case RH: /*  原本右子树比左子树高，需要作右平衡处理 */
					RightBalance(T); *taller = FALSE; break;
				}
		}
	}
	return TRUE;
}

/* 从二叉排序树中删除结点p，并重接它的左或右子树。 */
Status Delete(BiTree *p)
{
	BiTree q, s;
	if ((*p)->rchild == NULL) /* 右子树空则只需重接它的左子树（待删结点是叶子也走此分支) */
	{
		q = *p; *p = (*p)->lchild; free(q);
	}
	else if ((*p)->lchild == NULL) /* 只需重接它的右子树 */
	{
		q = *p; *p = (*p)->rchild; free(q);
	}
	else /* 左右子树均不空 */
	{
		q = *p; s = (*p)->lchild;
		while (s->rchild) /* 转左，然后向右到尽头（找待删结点的前驱） */
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data; /*  s指向被删结点的直接前驱（将被删结点前驱的值取代被删结点的值） */
		if (q != *p)
			q->rchild = s->lchild; /*  重接q的右子树 */
		else
			q->lchild = s->lchild; /*  重接q的左子树 */
		free(s);
	}
	return TRUE;
}

/* 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点, */
/* 并返回TRUE；否则返回FALSE。 */
Status DeleteBST(BiTree *T, int key)
{
	if (!*T) /* 不存在关键字等于key的数据元素 */
		return FALSE;
	else
	{
		if (key == (*T)->data) /* 找到关键字等于key的数据元素 */
			return Delete(T);
		else if (key < (*T)->data)
			return DeleteBST(&(*T)->lchild, key);
		else
			return DeleteBST(&(*T)->rchild, key);

	}
}
//递归遍历函数
void recursion(BiTree node)
{
	if (node == NULL)
	{
		return;
	}

	//中序遍历 先根 左子 右子
	recursion(node->lchild);

	cout << node->data << " ";

	recursion(node->rchild);
}

int main(void)
{
	int i;
	int a[10] = { 3,2,1,4,5,6,7,10,9,8 };
	BiTree T = NULL;
	Status taller;
	for (i = 0; i < 10; i++)
	{
		InsertAVL(&T, a[i], &taller);
	}
	recursion(T);
	cout << endl;
	DeleteBST(&T, 7);
	recursion(T);
	cout << endl;
	system("pause");
	return 0;
}