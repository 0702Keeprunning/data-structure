#include <iostream>
#include <string>
using namespace std;

//链表节点属性
struct LinkNode
{
	struct LinkNode * next;  //指针域
};

//链表结构体
struct LList
{
	struct LinkNode pHeader;  //头节点

	int m_size;	//链表长度
};

typedef void * LinkList;

//初始化链表
LinkList init_LinkList()
{
	struct LList * mylist = new struct LList;

	if (mylist == NULL)
	{
		return NULL;
	}

	mylist->pHeader.next = NULL;

	mylist->m_size = 0;

	return mylist;
}

//插入节点
void insert_linklist(LinkList list, int pos, LinkList data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	//交付给程序员指令list是什么  对于使用者来说不知道list是什么
	struct LList * mylist = (struct LList *)list;
	if (pos<0 || pos>mylist->m_size)
	{
		//无效位置进行尾插
		pos = mylist->m_size;
	}
	//将用户的数据 前四个字节转为 LinkNode型
	struct LinkNode * myNode = (struct LinkNode *)data;

	//创建临时节点
	//通过循环找到链表中pos位置的前一个节点
	struct LinkNode * pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//将新节点插入到链表中
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;

	//更新链表长度
	mylist->m_size++;
}

//遍历链表
//回调函数：让用户自己去操作打印数据
void foreach_linklist(LinkList list, void(*myprient)(void *))
{
	if (list == NULL)
	{
		return;
	}
	//交付给程序员指令list是什么  对于使用者来说不知道list是什么
	struct LList * mylist = (struct LList *)list;
	//创建一个临时节点 访问链表第一个有数据的节点
	struct LinkNode * pCurrent = mylist->pHeader.next;
	for (int i = 0; i < mylist->m_size; i++)
	{
		//回调函数是为了让用户自己去打印数据 因为链表是用户输入的 他知道应该打印什么
		myprient(pCurrent);
		//然后继续访问下一个节点
		pCurrent = pCurrent->next;
	}

}

void removebyposLinkList(LinkList list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	//交付给程序员指令list是什么  对于使用者来说不知道list是什么
	struct LList * mylist = (struct LList *)list;
	if (pos<0 || pos>mylist->m_size)
	{
		return;
	}
	//创建临时节点
	//通过循环找到链表中pos位置的前一个节点
	struct LinkNode * pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//保存待删除的节点	
	struct LinkNode *pDel = pCurrent->next;

	//开始删除
	pCurrent->next = pDel->next;

	//delete pDel;  //链表现在不维护数据域，释放反而会出错

	//更新链表长度
	mylist->m_size--;
}

//按值删除节点
void removebyvalueLinkList(LinkList list, LinkList data, int(*compare)(LinkList, LinkList))
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//交付给程序员指令list是什么  对于使用者来说不知道list是什么
	struct LList * mylist = (struct LList *)list;

	//创建两个临时节点
	struct LinkNode * pPrve = &mylist->pHeader;
	struct LinkNode * pCurrent = pPrve->next;

	for (int i = 0; i < mylist->m_size; i++)
	{
		//交给用户去设置如何比较
		if (compare(pCurrent, data))
		{
			//更改指针指向
			pPrve->next = pCurrent->next;

			//删除节点
			pCurrent = NULL;

			mylist->m_size--;
			//有break只删除第一个与data相同的 无break可删除与data相同的所有节点
			break;
		}
		//两个指针指向后移
		pPrve = pCurrent;
		pCurrent = pCurrent->next;

	}
}

//清空链表
void clearLinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	//交付给程序员指令list是什么  对于使用者来说不知道list是什么
	struct LList * mylist = (struct LList *)list;
	mylist->pHeader.next = NULL;
	mylist->m_size = 0;
}

//返回链表长度
int size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return 0;
	}

	//交付给程序员指令list是什么  对于使用者来说不知道list是什么
	struct LList * mylist = (struct LList *)list;

	return mylist->m_size;
}

//销毁链表
void destoryLinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	clearLinkList(list);

	delete list;
}

//用户自定义的数据类型
struct person
{
	struct LinkNode node;  //约定好的前四个字节
	string name;
	int age;

};

//用户自己写的比较函数
int structcompare(LinkList data1, LinkList data2)
{
	struct person * p1 = (struct person *)data1;
	struct person * p2 = (struct person *)data2;

	return p1->name == p2->name && p1->age == p2->age;
}
//用户自己写的打印函数
void myprientstruct(LinkList data)
{
	struct person * p = (struct person *)data;
	cout << "姓名：" << p->name << " 年龄： " << p->age << endl;
}


void test01()
{
	//初始化链表
	LinkList list = init_LinkList();

	//准备出五个元素
	struct person p1 = { NULL,"aaa",18 };
	struct person p2 = { NULL,"bbb",19 };
	struct person p3 = { NULL,"ccc",20 };
	struct person p4 = { NULL,"ddd",21 };
	struct person p5 = { NULL,"eee",22 };
	struct person p6 = { NULL,"fff",23 };

	//插入数据
	insert_linklist(list, 0, &p1);
	insert_linklist(list, 0, &p2);
	insert_linklist(list, 1, &p3);
	insert_linklist(list, 0, &p4);
	insert_linklist(list, 1, &p5);
	insert_linklist(list, 10, &p6);
	
	//ddd eee bbb ccc aaa fff
	//用户需要自己指定打印什么数据 这块交给用户去写
	foreach_linklist(list, myprientstruct);
	cout << "链表长度：" << size_LinkList(list) << endl;

	cout << "--------------按位置删除------------------" << endl;
	//按位置删除
	removebyposLinkList(list, 0);
	//ddd bbb ccc aaa fff
	//用户需要自己指定打印什么数据 这块交给用户去写
	foreach_linklist(list, myprientstruct);
	cout << "链表长度：" << size_LinkList(list) << endl;

	cout << "--------------按值删除------------------" << endl;
	struct person p7 = { NULL,"ccc",20 };
	//按值删除
	removebyvalueLinkList(list, &p7, structcompare);
	//ddd bbb aaa fff
	//用户需要自己指定打印什么数据 这块交给用户去写
	foreach_linklist(list, myprientstruct);
	cout << "链表长度：" << size_LinkList(list) << endl;

	cout << "--------------清空链表------------------" << endl;

	clearLinkList(list);
	foreach_linklist(list, myprientstruct);
	cout << "链表长度：" << size_LinkList(list) << endl;

	cout << "--------------销毁链表------------------" << endl;
	destoryLinkList(list);
}

int main()
{
	test01();
	system("pause");
	return 0;
}