#define _CRT_SECURE_NO_WARNINGS //����ʹ�þ�ģ���
#include "dynamicArray.h"

struct person
{
	string name;
	int age;

};

//�ṹ���������� �ص�����
void myprintPerson(void * data)
{
	struct person * p = (struct person *) data;
	cout << "������" << p->name << " ���䣺 " << p->age << endl;
}

int mycomparePerson(void * data1, void * data2)
{
	struct person * p1 = (struct person *)data1;
	struct person * p2 = (struct person *)data2;

	return p1->name == p2->name && p1->age == p2->age;
}

void test01()
{
	//������̬����
	struct dynamicArray * arr = init_dynamicArray(5);

	//׼�������Ԫ��
	struct person p1 = { "aaa",18 };
	struct person p2 = { "bbb",19 };
	struct person p3 = { "ccc",20 };
	struct person p4 = { "ddd",21 };
	struct person p5 = { "eee",22 };
	struct person p6 = { "fff",23 };

	//�����ݲ��붯̬����
	insert_dynamicArray(arr, 0, &p1);
	insert_dynamicArray(arr, 0, &p2);
	insert_dynamicArray(arr, 0, &p3);
	insert_dynamicArray(arr, 2, &p4);
	insert_dynamicArray(arr, 10, &p5);
	insert_dynamicArray(arr, 1, &p6);

	

	//ccc fff bbb ddd aaa eee
	//������ʾ
	foreach_dynamicArray(arr, myprintPerson);

	cout << "��ǰ����������" << arr->m_capacity << endl;
	cout << "��ǰ�����С��" << arr->m_size << endl;

	cout << "--------------ɾ�������е�Ԫ��--��λ��ɾ��-----------------" << endl;

	//ɾ�������е�Ԫ��--��λ��ɾ��
	removeByPos_dynamicArray(arr, 1);
	foreach_dynamicArray(arr, myprintPerson);

	cout << "��ǰ����������" << arr->m_capacity << endl;
	cout << "��ǰ�����С��" << arr->m_size << endl;


	cout << "---------------ɾ�������е�Ԫ��--��ֵɾ��------------------" << endl;

	struct person p = { "bbb",19 };
	removeByPos_dynamicArray(arr, &p, mycomparePerson);

	foreach_dynamicArray(arr, myprintPerson);

	cout << "��ǰ����������" << arr->m_capacity << endl;
	cout << "��ǰ�����С��" << arr->m_size << endl;

	cout << "---------------��������------------------" << endl;
	destory_dynamicArray(arr);
	arr = NULL;
	foreach_dynamicArray(arr, myprintPerson);
}
//int�������� �ص�����
void myprintint(void * data)
{
	int * p = (int *) data;
	cout << "���֣�" << *p << endl;
}

void test02()
{
	//������̬����
	struct dynamicArray * arr = init_dynamicArray(5);

	//׼�������Ԫ��
	int p1 = 1;
	int p2 = 2;
	int p3 = 3;
	int p4 = 4;
	int p5 = 5;
	int p6 = 6;

	//�����ݲ��붯̬����
	insert_dynamicArray(arr, 0, &p1);
	insert_dynamicArray(arr, 0, &p2);
	insert_dynamicArray(arr, 0, &p3);
	insert_dynamicArray(arr, 2, &p4);
	insert_dynamicArray(arr, 10, &p5);
	insert_dynamicArray(arr, 1, &p6);

	cout << "��ǰ����������" << arr->m_capacity << endl;
	cout << "��ǰ�����С��" << arr->m_size << endl;
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

//class�������� �ص�����
void myprintclass(void * data)
{
	people * p  = (people *) data;
	cout << "������" << p->m_name << " ���䣺 " << p->m_age << endl;

}

void test03()
{
	//������̬����
	struct dynamicArray * arr = init_dynamicArray(5);

	//׼�������Ԫ��
	people p1 = { "aaa",18 };
	people p2 = { "bbb",19 };
	people p3 = { "ccc",20 };
	people p4 = { "ddd",21 };
	people p5 = { "eee",22 };
	people p6 = { "fff",23 };

	//�����ݲ��붯̬����
	insert_dynamicArray(arr, 0, &p1);
	insert_dynamicArray(arr, 0, &p2);
	insert_dynamicArray(arr, 0, &p3);
	insert_dynamicArray(arr, 2, &p4);
	insert_dynamicArray(arr, 10, &p5);
	insert_dynamicArray(arr, 1, &p6);

	cout << "��ǰ����������" << arr->m_capacity << endl;
	cout << "��ǰ�����С��" << arr->m_size << endl;
	//ccc fff bbb ddd aaa eee
	foreach_dynamicArray(arr, myprintclass);

}
int main()
{
	test01();
	system("pause");
	return 0;
}