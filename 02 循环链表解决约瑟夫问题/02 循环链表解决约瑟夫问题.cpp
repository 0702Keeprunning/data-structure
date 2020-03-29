#include <iostream>
#include <string>
using namespace std;


struct Linknode {
	Linknode * next; //只维护指针域
};
struct Llist {
	Linknode pHeader;//创建头结点
	int m_size;
};
//初始化链表
Llist * Linklist_init()
{
	Llist * mylist = new Llist;
	if (mylist == NULL)
	{
		return NULL;
	}
	mylist->m_size = 0;
	mylist->pHeader.next = &mylist->pHeader;
}
void insert_Linklist(Llist * mylist, int pos, void * data)
{
	if (mylist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	if (pos<0 || pos>mylist->m_size)
	{
		pos = mylist->m_size;
	}
	//找到pos前的一个结点
	Linknode * pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//找一个新结点保存带插入数据
	Linknode * newnode = (Linknode *)data;

	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	mylist->m_size++;

}

void foreach_Linklist(Llist * mylist, void(*myprient)(void *))
{
	if (mylist == NULL)
	{
		return;
	}
	//第一个结点
	Linknode * pCurrent = mylist->pHeader.next;
	for (int i = 0; i < mylist->m_size; i++)
	{
		//如果遍历完一圈 应该让pcurrent指向第一个结点打印
		if (pCurrent == &mylist->pHeader)
			pCurrent = mylist->pHeader.next;
		myprient(pCurrent);
		pCurrent = pCurrent->next;
	}
}
//按照位置删除结点
void removebypos_linklist(Llist * mylist, int pos)
{
	if (mylist == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= mylist->m_size)
	{
		return;
	}
	//找到pos前的一个结点
	Linknode * pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//当前待删除结点
	//找一个新结点保存带插入数据
	Linknode * del = pCurrent->next;

	pCurrent->next = del->next;

	mylist->m_size--;
}
//按照值删除结点
void removebyvalue_linklist(Llist * mylist, void * data, bool(*mycompare)(void *, void *))
{
	if (mylist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	Linknode * pPrv = &mylist->pHeader;
	//当前结点
	Linknode * pCurrent = mylist->pHeader.next;
	for (int i = 0; i < mylist->m_size; i++)
	{
		//如果找到
		if (mycompare(pCurrent, data))
		{
			pPrv->next = pCurrent->next;

			mylist->m_size--;

			break;
		}
		pPrv = pPrv->next;
		pCurrent = pCurrent->next;
	}


}
//返回链表长度
int size_linklist(Llist * mylist)
{
	if (mylist == NULL)
	{
		return 0;
	}
	return mylist->m_size;
}

//清空链表
void clear_linklist(Llist * mylist)
{
	if (mylist == NULL)
	{
		return;
	}
	mylist->pHeader.next = &mylist->pHeader;
	mylist->m_size = 0;
}
//销毁链表
void destroy_linklist(Llist * mylist)
{
	if (mylist == NULL)
	{
		return;
	}
	delete mylist;
}

struct yuesefu {
	Linknode * node;
	int value;
};


void personprient(void * list)
{
	yuesefu * p = (yuesefu *)list;
	cout << p->value << " ";
}
bool compare(void * mylist, void * data)
{
	yuesefu *p1 = (yuesefu*)mylist;
	yuesefu *p2 = (yuesefu*)data;

	return p1->value == p2->value;
}
//总共M个数 每遇到N个时输出  知道八个值输出完

#define M 8
#define N 3


int main()
{
	//创建列表
	Llist *mylist = Linklist_init();
	//创建值
	yuesefu num[M]; //创建M个值
	for (int i = 0; i < M; i++)
	{
		num[i].value = i + 1;
		//插入到循环链表中
		insert_Linklist(mylist, i, &num[i]);
	}
	foreach_Linklist(mylist, personprient);
	cout << endl;

	//解决约瑟夫问题

	int index = 1;
	//指向第一个数据的指针
	Linknode * pCurrent = mylist->pHeader.next;
	//当链表中数据不为一时
	while (size_linklist(mylist) > 0)
	{
		if (index == N)
		{
			//先输出链表中该位置的值
			yuesefu * numvalue = (yuesefu *)pCurrent;
			cout << numvalue->value << " ";
			//然后该位置的值删除
			Linknode * pnetx = pCurrent->next;
			removebyvalue_linklist(mylist, pCurrent, compare);
			//让当前结点等于下一个节点
			pCurrent = pnetx;
			//如果等于头结点
			if (pCurrent == &mylist->pHeader)
			{
				pCurrent = mylist->pHeader.next;
			}
			index = 1;
				
		}
		pCurrent = pCurrent->next;
		//如果等于头结点 指向第一个数据结点
		if (pCurrent == &mylist->pHeader)
		{
			pCurrent = mylist->pHeader.next;
		}
		index++;
	}
	cout << endl;

	
	system("pause");
	return 0;
}

	