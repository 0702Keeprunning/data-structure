#include <iostream>
#include <string>
using namespace std;

//链表节点属性
struct QueueNode
{
	struct QueueNode * next;  //指针域
};

//链表结构体
struct QUList
{
	struct QueueNode pHeader;  //头节点

	int m_size;	//链表长度

	struct QueueNode * pTail;  //尾部数据地址指针（方便用来进行尾插）
};

typedef void * LinkQueue;

//初始化队列
LinkQueue init_Queuelist()
{
	struct QUList * myqueue = new struct QUList;

	if (myqueue == NULL)
	{
		return NULL;
	}

	myqueue->pHeader.next = NULL;

	myqueue->m_size = 0;

	//一开始链表最后数据位置就是头结点的位置
	myqueue->pTail = &myqueue->pHeader;

	return myqueue;
}

//入队
void push_Queuelist(LinkQueue queue, LinkQueue data)
{
	if (queue == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct QUList * myqueue = (struct QUList *) queue;

	//取出用户的数据 前四个字节
	struct QueueNode * myNode = (struct QueueNode *)data;

	//尾插
	myqueue->pTail->next = myNode;
	myNode->next = NULL;

	//尾部数据指针要指向更新后最尾部数据处
	myqueue->pTail = myNode;

	//更新队列长度
	myqueue->m_size++;


}

//出队
void pop_Queuelist(LinkQueue queue)
{
	if (queue == NULL)
	{
		return;
	}
	struct QUList * myqueue = (struct QUList *) queue;

	if (myqueue->m_size <= 0)
	{
		return;
	}
	if (myqueue->m_size == 1)
	{
		myqueue->pHeader.next = NULL;
		myqueue->pTail = &myqueue->pHeader;
		myqueue->m_size = 0;
		return;
	}

	//先拿到第一个有数据的节点
	struct QueueNode *first = myqueue->pHeader.next;

	//出队
	myqueue->pHeader.next = first->next;

	//更新队列长度
	myqueue->m_size--;


}

//返回对头
LinkQueue front_Queuelist(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct QUList * myqueue = (struct QUList *) queue;

	return myqueue->pHeader.next;
}

//返回对尾
LinkQueue back_Queuelist(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct QUList * myqueue = (struct QUList *) queue;

	return myqueue->pTail;
}

//返回队伍大小
int size_Queuelist(LinkQueue queue)
{
	if (queue == NULL)
	{ 
		return NULL;
	}
	struct QUList * myqueue = (struct QUList *) queue;
	return myqueue->m_size;
}

//判断队列是否为空
bool isEmpty(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct QUList * myqueue = (struct QUList *) queue;
	if (myqueue->m_size <= 0)
	{
		return true;
	}
	return false;
}

//销毁队列
void destory_Queuelist(LinkQueue queue)
{
	if (queue == NULL)
	{
		return;
	}

	delete queue;
}


struct person
{
	void * node;
	string name;
	int age;

};

void test01()
{
	//初始化队列
	LinkQueue myqueue = init_Queuelist();

	//准备数据
	struct person p1 = { NULL,"aaa",18 };
	struct person p2 = { NULL,"bbb",19 };
	struct person p3 = { NULL,"ccc",20 };
	struct person p4 = { NULL,"ddd",21 };
	struct person p5 = { NULL,"eee",22 };
	struct person p6 = { NULL,"fff",23 };

	//入队
	push_Queuelist(myqueue, &p1);
	push_Queuelist(myqueue, &p2);
	push_Queuelist(myqueue, &p3);
	push_Queuelist(myqueue, &p4);
	push_Queuelist(myqueue, &p5);
	push_Queuelist(myqueue, &p6);
	cout << "数组大小：" << size_Queuelist(myqueue) << endl;
	while (isEmpty(myqueue) == 0)
	{
		//返回对头
		struct person * front = (struct person *)front_Queuelist(myqueue);
		//返回对头
		struct person * back = (struct person *)back_Queuelist(myqueue);

		cout << "对头姓名：" << front->name << " 年龄： " << front->age << endl;
		cout << "对尾姓名：" << back->name << " 年龄： " << back->age << endl;

		//出队
		pop_Queuelist(myqueue);

	}
	cout << "数组大小：" << size_Queuelist(myqueue) << endl;

	destory_Queuelist(myqueue);
}

int main()
{
	test01();
	system("pause");
	return 0;
}