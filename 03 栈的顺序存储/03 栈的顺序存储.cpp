#include <iostream>
#include <string>
using namespace std;

#define MAX 1024

typedef void * seqStack;
//ջ�Ľṹ��
//˳��洢
struct SStack
{
	seqStack data[MAX];  //����
	int m_size;  //ջ��Ԫ�ظ���
};
//��ʼ��ջ
seqStack init_seqStack()
{
	//�ڶ�������һ���ṹ��
	struct SStack * stack = new struct SStack;

	if (stack == NULL)
	{
		return NULL;
	}

	//���ÿһ�������е�Ԫ��
	memset(stack->data, 0, sizeof(seqStack)*MAX);

	stack->m_size = 0;

}

//��ջ
void push_seqStack(seqStack stack, seqStack data)
{
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//�ж�ջ�Ƿ�����
	struct SStack * mystack = (struct SStack *)stack;
	if (mystack->m_size == MAX)
	{
		return;
	}
	//��ջ����
	mystack->data[mystack->m_size] = data;

	//����ջ�Ĵ�С
	mystack->m_size++;
}

//��ջ
void pop_seqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	//����ǿ�ջ ��ִ�г�ջ
	struct SStack * mystack = (struct SStack *)stack;
	if (mystack->m_size <=0)
	{
		return;
	}

	//��ջ����
	mystack->data[mystack->m_size - 1] = NULL;

	//����ջ�Ĵ�С
	mystack->m_size--;

}

//��ȡջ��Ԫ��
seqStack top_stack(seqStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	//����ǿ�ջ ��ִ�л�ȡջ��Ԫ��
	struct SStack * mystack = (struct SStack *)stack;
	if (mystack->m_size <= 0)
	{
		return NULL;
	}

	//����ջ��Ԫ��
	return mystack->data[mystack->m_size - 1];
}

//ջ�Ĵ�С

int size_seqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	struct SStack * mystack = (struct SStack *)stack;
	//����ջ�Ĵ�С
	return mystack->m_size;
}

//�ж�ջ�Ƿ�Ϊ��
bool isEmpty_seqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	struct SStack * mystack = (struct SStack *)stack;

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
void destroy_seqStack(seqStack stack)
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
	string name;
	int age;

};

void test01()
{
	//׼�������Ԫ��
	struct person p1 = { "aaa",18 };
	struct person p2 = { "bbb",19 };
	struct person p3 = { "ccc",20 };
	struct person p4 = { "ddd",21 };
	struct person p5 = { "eee",22 };
	struct person p6 = { "fff",23 };

	//��ʼ��ջ
	seqStack stack = init_seqStack();

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