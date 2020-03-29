#include <iostream>
#include <string>
using namespace std;

//����ڵ�����
struct QueueNode
{
	struct QueueNode * next;  //ָ����
};

//����ṹ��
struct QUList
{
	struct QueueNode pHeader;  //ͷ�ڵ�

	int m_size;	//������

	struct QueueNode * pTail;  //β�����ݵ�ַָ�루������������β�壩
};

typedef void * LinkQueue;

//��ʼ������
LinkQueue init_Queuelist()
{
	struct QUList * myqueue = new struct QUList;

	if (myqueue == NULL)
	{
		return NULL;
	}

	myqueue->pHeader.next = NULL;

	myqueue->m_size = 0;

	//һ��ʼ�����������λ�þ���ͷ����λ��
	myqueue->pTail = &myqueue->pHeader;

	return myqueue;
}

//���
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

	//ȡ���û������� ǰ�ĸ��ֽ�
	struct QueueNode * myNode = (struct QueueNode *)data;

	//β��
	myqueue->pTail->next = myNode;
	myNode->next = NULL;

	//β������ָ��Ҫָ����º���β�����ݴ�
	myqueue->pTail = myNode;

	//���¶��г���
	myqueue->m_size++;


}

//����
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

	//���õ���һ�������ݵĽڵ�
	struct QueueNode *first = myqueue->pHeader.next;

	//����
	myqueue->pHeader.next = first->next;

	//���¶��г���
	myqueue->m_size--;


}

//���ض�ͷ
LinkQueue front_Queuelist(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct QUList * myqueue = (struct QUList *) queue;

	return myqueue->pHeader.next;
}

//���ض�β
LinkQueue back_Queuelist(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct QUList * myqueue = (struct QUList *) queue;

	return myqueue->pTail;
}

//���ض����С
int size_Queuelist(LinkQueue queue)
{
	if (queue == NULL)
	{ 
		return NULL;
	}
	struct QUList * myqueue = (struct QUList *) queue;
	return myqueue->m_size;
}

//�ж϶����Ƿ�Ϊ��
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

//���ٶ���
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
	//��ʼ������
	LinkQueue myqueue = init_Queuelist();

	//׼������
	struct person p1 = { NULL,"aaa",18 };
	struct person p2 = { NULL,"bbb",19 };
	struct person p3 = { NULL,"ccc",20 };
	struct person p4 = { NULL,"ddd",21 };
	struct person p5 = { NULL,"eee",22 };
	struct person p6 = { NULL,"fff",23 };

	//���
	push_Queuelist(myqueue, &p1);
	push_Queuelist(myqueue, &p2);
	push_Queuelist(myqueue, &p3);
	push_Queuelist(myqueue, &p4);
	push_Queuelist(myqueue, &p5);
	push_Queuelist(myqueue, &p6);
	cout << "�����С��" << size_Queuelist(myqueue) << endl;
	while (isEmpty(myqueue) == 0)
	{
		//���ض�ͷ
		struct person * front = (struct person *)front_Queuelist(myqueue);
		//���ض�ͷ
		struct person * back = (struct person *)back_Queuelist(myqueue);

		cout << "��ͷ������" << front->name << " ���䣺 " << front->age << endl;
		cout << "��β������" << back->name << " ���䣺 " << back->age << endl;

		//����
		pop_Queuelist(myqueue);

	}
	cout << "�����С��" << size_Queuelist(myqueue) << endl;

	destory_Queuelist(myqueue);
}

int main()
{
	test01();
	system("pause");
	return 0;
}