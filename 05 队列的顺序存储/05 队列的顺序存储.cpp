#include "dynamicArray.h"

#define MAX 1024
typedef void * seqQueue;
//初始化队列
seqQueue init_seqQueue()
{
	struct dynamicArray * queue = init_dynamicArray(MAX);

	return queue;
}

//入队
void push_seqQueue(seqQueue queue, seqQueue data)
{
	if (queue == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct dynamicArray * myqueue = (struct dynamicArray *)queue;
	if (myqueue->m_size >= MAX)
	{
		return;
	}

	insert_dynamicArray(myqueue, myqueue->m_size, data);

}

//出队
void pop_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return;
	}
	struct dynamicArray * myqueue = (struct dynamicArray *)queue;
	if (myqueue->m_size <=0)
	{
		return;
	}

	removeByPos_dynamicArray(myqueue, 0);

}

//返回对头
seqQueue front_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct dynamicArray * myqueue = (struct dynamicArray *)queue;

	return myqueue->pAddr[0];
}

//返回队尾
seqQueue back_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct dynamicArray * myqueue = (struct dynamicArray *)queue;

	return myqueue->pAddr[myqueue->m_size - 1];
}

//返回队列大小
int size_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct dynamicArray * myqueue = (struct dynamicArray *)queue;

	return myqueue->m_size;
}

//销毁队列
void destory_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return;
	}
	struct dynamicArray * myqueue = (struct dynamicArray *)queue;

	destory_dynamicArray(myqueue);
}

//判断队列是否为空
bool isEmpty(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct dynamicArray * myqueue = (struct dynamicArray *)queue;

	if (myqueue->m_size <= 0)
	{
		return true;
	}
	return false;
}


struct person
{
	string name;
	int age;

};

void test01()
{
	//初始化队列
	seqQueue myqueue = init_seqQueue();
	
	//准备数据
	struct person p1 = { "aaa",18 };
	struct person p2 = { "bbb",19 };
	struct person p3 = { "ccc",20 };
	struct person p4 = { "ddd",21 };
	struct person p5 = { "eee",22 };
	struct person p6 = { "fff",23 };

	//入队
	push_seqQueue(myqueue, &p1);
	push_seqQueue(myqueue, &p2);
	push_seqQueue(myqueue, &p3);
	push_seqQueue(myqueue, &p4);
	push_seqQueue(myqueue, &p5);
	push_seqQueue(myqueue, &p6);
	cout << "数组大小：" << size_seqQueue(myqueue) << endl;
	while (isEmpty(myqueue) == 0)
	{
		//返回对头
		struct person * front =(struct person * )front_seqQueue(myqueue);
		//返回对头
		struct person * back = (struct person *)back_seqQueue(myqueue);

		cout << "对头姓名：" << front->name << " 年龄： " << front->age << endl;
		cout << "对尾姓名：" << back->name << " 年龄： " << back->age << endl;

		//出对
		pop_seqQueue(myqueue);

	}
	cout << "数组大小：" << size_seqQueue(myqueue) << endl;

	destory_seqQueue(myqueue);

	
}

int main()
{
	test01();
	system("pause");
	return 0;
}