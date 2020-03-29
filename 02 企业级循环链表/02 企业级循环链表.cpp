#include <iostream>
#include <string>
using namespace std;


struct Linknode {
	Linknode * next; //只维护指针域
};
struct Llist{
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

void foreach_Linklist(Llist * mylist,void(*myprient)(void *))
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
		if(mycompare(pCurrent,data))
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
		return ;
	}
	delete mylist;
}

struct person{
	Linknode * node;
	string m_name;
	int age;
};


void personprient(void * list)
{
	person * p = (person *)list;
	cout << "姓名：" << p->m_name << " 年龄：" << p->age << endl;
}
bool compare(void * mylist, void * data)
{
	person *p1 = (person*)mylist;
	person *p2 = (person*)data;

	return p1->m_name == p2->m_name && p1->age == p2->age;
}
int main()
{
	//创建列表
	Llist *mylist = Linklist_init();
	//
	//准备出五个元素
	person p1 = { NULL,"aaa",18 };
	person p2 = { NULL,"bbb",19 };
	person p3 = { NULL,"ccc",20 };
	person p4 = { NULL,"ddd",21 };
	person p5 = { NULL,"eee",22 };
	person p6 = { NULL,"fff",23 };
	//插入链表
	insert_Linklist(mylist, 0, &p1);
	insert_Linklist(mylist, 0, &p2);
	insert_Linklist(mylist, 1, &p3);
	insert_Linklist(mylist, 0, &p4);
	insert_Linklist(mylist, 1, &p5);
	insert_Linklist(mylist, 10, &p6);
	foreach_Linklist(mylist, personprient);

	cout << size_linklist(mylist) << endl;
	cout << "-------------------------" << endl;
	removebypos_linklist(mylist, 0);
	foreach_Linklist(mylist, personprient);
	cout << size_linklist(mylist) << endl;
	cout << "-------------------------" << endl;
	person p7 = { NULL,"fff",23 };
	removebyvalue_linklist(mylist, &p7, compare);
	foreach_Linklist(mylist, personprient);
	cout << size_linklist(mylist) << endl;
	cout << "-------------------------" << endl;
	clear_linklist(mylist);
	foreach_Linklist(mylist, personprient);
	cout << size_linklist(mylist) << endl;
	cout << "-------------------------" << endl;
	destroy_linklist(mylist);

	system("pause"); 
	return 0;
}

