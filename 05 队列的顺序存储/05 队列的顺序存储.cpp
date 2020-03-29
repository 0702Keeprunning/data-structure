#include "dynamicArray.h"

#define MAX 1024
typedef void * seqQueue;
//��ʼ������
seqQueue init_seqQueue()
{
	struct dynamicArray * queue = init_dynamicArray(MAX);

	return queue;
}

//���
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

//����
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

//���ض�ͷ
seqQueue front_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct dynamicArray * myqueue = (struct dynamicArray *)queue;

	return myqueue->pAddr[0];
}

//���ض�β
seqQueue back_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct dynamicArray * myqueue = (struct dynamicArray *)queue;

	return myqueue->pAddr[myqueue->m_size - 1];
}

//���ض��д�С
int size_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct dynamicArray * myqueue = (struct dynamicArray *)queue;

	return myqueue->m_size;
}

//���ٶ���
void destory_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return;
	}
	struct dynamicArray * myqueue = (struct dynamicArray *)queue;

	destory_dynamicArray(myqueue);
}

//�ж϶����Ƿ�Ϊ��
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
	//��ʼ������
	seqQueue myqueue = init_seqQueue();
	
	//׼������
	struct person p1 = { "aaa",18 };
	struct person p2 = { "bbb",19 };
	struct person p3 = { "ccc",20 };
	struct person p4 = { "ddd",21 };
	struct person p5 = { "eee",22 };
	struct person p6 = { "fff",23 };

	//���
	push_seqQueue(myqueue, &p1);
	push_seqQueue(myqueue, &p2);
	push_seqQueue(myqueue, &p3);
	push_seqQueue(myqueue, &p4);
	push_seqQueue(myqueue, &p5);
	push_seqQueue(myqueue, &p6);
	cout << "�����С��" << size_seqQueue(myqueue) << endl;
	while (isEmpty(myqueue) == 0)
	{
		//���ض�ͷ
		struct person * front =(struct person * )front_seqQueue(myqueue);
		//���ض�ͷ
		struct person * back = (struct person *)back_seqQueue(myqueue);

		cout << "��ͷ������" << front->name << " ���䣺 " << front->age << endl;
		cout << "��β������" << back->name << " ���䣺 " << back->age << endl;

		//����
		pop_seqQueue(myqueue);

	}
	cout << "�����С��" << size_seqQueue(myqueue) << endl;

	destory_seqQueue(myqueue);

	
}

int main()
{
	test01();
	system("pause");
	return 0;
}