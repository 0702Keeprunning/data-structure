#include <iostream>
#include <string>
using namespace std;

struct StackNode
{
	struct StackNode * next;
};

struct LQStack
{
	struct StackNode pHeader;  //ͷ���
	int m_size;	//ջ�Ĵ�С
};

typedef void * LinkStack;

////��ʼ��ջ
LinkStack init_seqStack()
{
	//�ڶ�������һ���ṹ��
	struct LQStack * stack = new struct LQStack;

	if (stack == NULL)
	{
		return NULL;
	}
	stack->pHeader.next = NULL;

	stack->m_size = 0;

}

//��ջ
void push_seqStack(LinkStack stack, LinkStack data)
{
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LQStack * mystack = (struct LQStack *)stack;

	//���õ��û����ݵ�ǰ�ĸ��ֽ�
	struct StackNode * mynode = (struct StackNode *)data;

	//��ջ����
	mynode->next = mystack->pHeader.next;
	mystack->pHeader.next = mynode;
	

	//����ջ�Ĵ�С
	mystack->m_size++;
}

//��ջ
void pop_seqStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	//����ǿ�ջ ��ִ�г�ջ
	struct LQStack * mystack = (struct LQStack *)stack;
	if (mystack->m_size <=0)
	{
		return;
	}

	//��ջ����
	//���õ��û��ĵ�һ������
	struct StackNode * mynode = mystack->pHeader.next;

	mystack->pHeader.next = mynode->next;

	//����ջ�Ĵ�С
	mystack->m_size--;

}

//��ȡջ��Ԫ��
LinkStack top_stack(LinkStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	//����ǿ�ջ ��ִ�л�ȡջ��Ԫ��
	struct LQStack * mystack = (struct LQStack *)stack;
	if (mystack->m_size <= 0)
	{
		return NULL;
	}

	//����ջ��Ԫ��
	return mystack->pHeader.next;  //����һ�������ݵĽڵ㷵��
}

//ջ�Ĵ�С

int size_seqStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	struct LQStack * mystack = (struct LQStack *)stack;
	//����ջ�Ĵ�С
	return mystack->m_size;
}

//�ж�ջ�Ƿ�Ϊ��
bool isEmpty_seqStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	struct LQStack * mystack = (struct LQStack *)stack;

	if (mystack->m_size <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//����ջ
void destroy_seqStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return;
	}

	delete stack;
	stack = NULL;
}

//�û��Զ������������
struct person
{
	struct StackNode * mynode;
	string name;
	int age;

};

void test01()
{
	//׼�������Ԫ��
	struct person p1 = { NULL, "aaa",18 };
	struct person p2 = { NULL,"bbb",19 };
	struct person p3 = { NULL,"ccc",20 };
	struct person p4 = { NULL,"ddd",21 };
	struct person p5 = { NULL,"eee",22 };
	struct person p6 = { NULL,"fff",23 };

	//��ʼ��ջ
	LinkStack stack = init_seqStack();

	//��ջ
	push_seqStack(stack, &p1);
	push_seqStack(stack, &p2);
	push_seqStack(stack, &p3);
	push_seqStack(stack, &p4);
	push_seqStack(stack, &p5);
	push_seqStack(stack, &p6);

	//ջ�Ĵ�С
	cout << "ջ�Ĵ�СΪ��" << size_seqStack(stack) << endl;

	while (isEmpty_seqStack(stack) == 0) //���ջ��Ϊ��
	{
		struct person * top = (struct person *) top_stack(stack);  //ȡ��ջ��Ԫ��

		cout << "������" << top->name << " ���䣺" << top->age << endl;

		//��ջ
		pop_seqStack(stack);

	}

	//ջ�Ĵ�С
	cout << "ջ�Ĵ�СΪ��" << size_seqStack(stack) << endl;

	destroy_seqStack(stack);
}

int main()
{
	test01();
	system("pause");
	return 0;
}