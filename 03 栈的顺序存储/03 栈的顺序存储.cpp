#include <iostream>
#include <string>
using namespace std;

#define MAX 1024

typedef void * seqStack;
//栈的结构体
//顺序存储
struct SStack
{
	seqStack data[MAX];  //数组
	int m_size;  //栈的元素个数
};
//初始化栈
seqStack init_seqStack()
{
	//在堆区创建一个结构体
	struct SStack * stack = new struct SStack;

	if (stack == NULL)
	{
		return NULL;
	}

	//清空每一个数组中的元素
	memset(stack->data, 0, sizeof(seqStack)*MAX);

	stack->m_size = 0;

}

//入栈
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

	//判断栈是否满了
	struct SStack * mystack = (struct SStack *)stack;
	if (mystack->m_size == MAX)
	{
		return;
	}
	//入栈操作
	mystack->data[mystack->m_size] = data;

	//更新栈的大小
	mystack->m_size++;
}

//出栈
void pop_seqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	//如果是空栈 不执行出栈
	struct SStack * mystack = (struct SStack *)stack;
	if (mystack->m_size <=0)
	{
		return;
	}

	//出栈操作
	mystack->data[mystack->m_size - 1] = NULL;

	//更新栈的大小
	mystack->m_size--;

}

//获取栈顶元素
seqStack top_stack(seqStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	//如果是空栈 不执行获取栈顶元素
	struct SStack * mystack = (struct SStack *)stack;
	if (mystack->m_size <= 0)
	{
		return NULL;
	}

	//返回栈顶元素
	return mystack->data[mystack->m_size - 1];
}

//栈的大小

int size_seqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	struct SStack * mystack = (struct SStack *)stack;
	//返回栈的大小
	return mystack->m_size;
}

//判断栈是否为空
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

//销毁栈
void destroy_seqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return;
	}

	delete stack;
	stack = NULL;
}

//用户自定义的数据类型
struct person
{
	string name;
	int age;

};

void test01()
{
	//准备出五个元素
	struct person p1 = { "aaa",18 };
	struct person p2 = { "bbb",19 };
	struct person p3 = { "ccc",20 };
	struct person p4 = { "ddd",21 };
	struct person p5 = { "eee",22 };
	struct person p6 = { "fff",23 };

	//初始化栈
	seqStack stack = init_seqStack();

	//入栈
	push_seqStack(stack, &p1);
	push_seqStack(stack, &p2);
	push_seqStack(stack, &p3);
	push_seqStack(stack, &p4);
	push_seqStack(stack, &p5);
	push_seqStack(stack, &p6);

	//栈的大小
	cout << "栈的大小为：" << size_seqStack(stack) << endl;

	while (isEmpty_seqStack(stack) == 0) //如果栈不为空
	{
		struct person * top = (struct person *) top_stack(stack);  //取出栈顶元素

		cout << "姓名：" << top->name << " 年龄：" << top->age << endl;

		//出栈
		pop_seqStack(stack);

	}

	//栈的大小
	cout << "栈的大小为：" << size_seqStack(stack) << endl;

	destroy_seqStack(stack);


}

int main()
{
	test01();
	system("pause");
	return 0;
}