#define _CRT_SECURE_NO_WARNINGS //允许使用旧模板库
#include "dynamicArray.h"

struct person
{
	string name;
	int age;

};

//结构体数据类型 回调函数
void myprintPerson(void * data)
{
	struct person * p = (struct person *) data;
	cout << "姓名：" << p->name << " 年龄： " << p->age << endl;
}

int mycomparePerson(void * data1, void * data2)
{
	struct person * p1 = (struct person *)data1;
	struct person * p2 = (struct person *)data2;

	return p1->name == p2->name && p1->age == p2->age;
}

void test01()
{
	//创建动态数组
	struct dynamicArray * arr = init_dynamicArray(5);

	//准备出五个元素
	struct person p1 = { "aaa",18 };
	struct person p2 = { "bbb",19 };
	struct person p3 = { "ccc",20 };
	struct person p4 = { "ddd",21 };
	struct person p5 = { "eee",22 };
	struct person p6 = { "fff",23 };

	//将数据插入动态数组
	insert_dynamicArray(arr, 0, &p1);
	insert_dynamicArray(arr, 0, &p2);
	insert_dynamicArray(arr, 0, &p3);
	insert_dynamicArray(arr, 2, &p4);
	insert_dynamicArray(arr, 10, &p5);
	insert_dynamicArray(arr, 1, &p6);

	

	//ccc fff bbb ddd aaa eee
	//遍历显示
	foreach_dynamicArray(arr, myprintPerson);

	cout << "当前数组容量：" << arr->m_capacity << endl;
	cout << "当前数组大小：" << arr->m_size << endl;

	cout << "--------------删除数组中的元素--按位置删除-----------------" << endl;

	//删除数组中的元素--按位置删除
	removeByPos_dynamicArray(arr, 1);
	foreach_dynamicArray(arr, myprintPerson);

	cout << "当前数组容量：" << arr->m_capacity << endl;
	cout << "当前数组大小：" << arr->m_size << endl;


	cout << "---------------删除数组中的元素--按值删除------------------" << endl;

	struct person p = { "bbb",19 };
	removeByPos_dynamicArray(arr, &p, mycomparePerson);

	foreach_dynamicArray(arr, myprintPerson);

	cout << "当前数组容量：" << arr->m_capacity << endl;
	cout << "当前数组大小：" << arr->m_size << endl;

	cout << "---------------销毁数组------------------" << endl;
	destory_dynamicArray(arr);
	arr = NULL;
	foreach_dynamicArray(arr, myprintPerson);
}
//int数据类型 回调函数
void myprintint(void * data)
{
	int * p = (int *) data;
	cout << "数字：" << *p << endl;
}

void test02()
{
	//创建动态数组
	struct dynamicArray * arr = init_dynamicArray(5);

	//准备出五个元素
	int p1 = 1;
	int p2 = 2;
	int p3 = 3;
	int p4 = 4;
	int p5 = 5;
	int p6 = 6;

	//将数据插入动态数组
	insert_dynamicArray(arr, 0, &p1);
	insert_dynamicArray(arr, 0, &p2);
	insert_dynamicArray(arr, 0, &p3);
	insert_dynamicArray(arr, 2, &p4);
	insert_dynamicArray(arr, 10, &p5);
	insert_dynamicArray(arr, 1, &p6);

	cout << "当前数组容量：" << arr->m_capacity << endl;
	cout << "当前数组大小：" << arr->m_size << endl;
	//3 6 2 4 1 5
	foreach_dynamicArray(arr, myprintint);

}

class people
{
public:
	people(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};

//class数据类型 回调函数
void myprintclass(void * data)
{
	people * p  = (people *) data;
	cout << "姓名：" << p->m_name << " 年龄： " << p->m_age << endl;

}

void test03()
{
	//创建动态数组
	struct dynamicArray * arr = init_dynamicArray(5);

	//准备出五个元素
	people p1 = { "aaa",18 };
	people p2 = { "bbb",19 };
	people p3 = { "ccc",20 };
	people p4 = { "ddd",21 };
	people p5 = { "eee",22 };
	people p6 = { "fff",23 };

	//将数据插入动态数组
	insert_dynamicArray(arr, 0, &p1);
	insert_dynamicArray(arr, 0, &p2);
	insert_dynamicArray(arr, 0, &p3);
	insert_dynamicArray(arr, 2, &p4);
	insert_dynamicArray(arr, 10, &p5);
	insert_dynamicArray(arr, 1, &p6);

	cout << "当前数组容量：" << arr->m_capacity << endl;
	cout << "当前数组大小：" << arr->m_size << endl;
	//ccc fff bbb ddd aaa eee
	foreach_dynamicArray(arr, myprintclass);

}
int main()
{
	test01();
	system("pause");
	return 0;
}