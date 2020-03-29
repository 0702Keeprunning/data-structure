#include <iostream>
#include <string>
using namespace std;

struct StackNode
{
	struct StackNode * next;
};

struct LQStack
{
	struct StackNode pHeader;  //头结点
	int m_size;	//栈的大小
};

typedef void * LinkStack;

////初始化栈
LinkStack init_seqStack()
{
	//在堆区创建一个结构体
	struct LQStack * stack = new struct LQStack;

	if (stack == NULL)
	{
		return NULL;
	}
	stack->pHeader.next = NULL;

	stack->m_size = 0;

}

//入栈
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

	//先拿到用户数据的前四个字节
	struct StackNode * mynode = (struct StackNode *)data;

	//入栈操作
	mynode->next = mystack->pHeader.next;
	mystack->pHeader.next = mynode;
	

	//更新栈的大小
	mystack->m_size++;
}

//出栈
void pop_seqStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	//如果是空栈 不执行出栈
	struct LQStack * mystack = (struct LQStack *)stack;
	if (mystack->m_size <=0)
	{
		return;
	}

	//出栈操作
	//先拿到用户的第一个数据
	struct StackNode * mynode = mystack->pHeader.next;

	mystack->pHeader.next = mynode->next;

	//更新栈的大小
	mystack->m_size--;

}

//获取栈顶元素
LinkStack top_stack(LinkStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	//如果是空栈 不执行获取栈顶元素
	struct LQStack * mystack = (struct LQStack *)stack;
	if (mystack->m_size <= 0)
	{
		return NULL;
	}

	//返回栈顶元素
	return mystack->pHeader.next;  //将第一个有数据的节点返回
}

//栈的大小

int size_seqStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	struct LQStack * mystack = (struct LQStack *)stack;
	//返回栈的大小
	return mystack->m_size;
}

//判断栈是否为空
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

//销毁栈
void destroy_seqStack(LinkStack stack)
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
	struct StackNode * mynode;
	string name;
	int age;

};

void test01()
{
	//准备出五个元素
	struct person p1 = { NULL, "aaa",18 };
	struct person p2 = { NULL,"bbb",19 };
	struct person p3 = { NULL,"ccc",20 };
	struct person p4 = { NULL,"ddd",21 };
	struct person p5 = { NULL,"eee",22 };
	struct person p6 = { NULL,"fff",23 };

	//初始化栈
	LinkStack stack = init_seqStack();

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