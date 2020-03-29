#include <iostream>
#include <string>
using namespace std;

//����ڵ�����
struct LinkNode
{
	struct LinkNode * next;  //ָ����
};

//����ṹ��
struct LList
{
	struct LinkNode pHeader;  //ͷ�ڵ�

	int m_size;	//������
};

typedef void * LinkList;

//��ʼ������
LinkList init_LinkList()
{
	struct LList * mylist = new struct LList;

	if (mylist == NULL)
	{
		return NULL;
	}

	mylist->pHeader.next = NULL;

	mylist->m_size = 0;

	return mylist;
}

//����ڵ�
void insert_linklist(LinkList list, int pos, LinkList data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	//����������Աָ��list��ʲô  ����ʹ������˵��֪��list��ʲô
	struct LList * mylist = (struct LList *)list;
	if (pos<0 || pos>mylist->m_size)
	{
		//��Чλ�ý���β��
		pos = mylist->m_size;
	}
	//���û������� ǰ�ĸ��ֽ�תΪ LinkNode��
	struct LinkNode * myNode = (struct LinkNode *)data;

	//������ʱ�ڵ�
	//ͨ��ѭ���ҵ�������posλ�õ�ǰһ���ڵ�
	struct LinkNode * pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//���½ڵ���뵽������
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;

	//����������
	mylist->m_size++;
}

//��������
//�ص����������û��Լ�ȥ������ӡ����
void foreach_linklist(LinkList list, void(*myprient)(void *))
{
	if (list == NULL)
	{
		return;
	}
	//����������Աָ��list��ʲô  ����ʹ������˵��֪��list��ʲô
	struct LList * mylist = (struct LList *)list;
	//����һ����ʱ�ڵ� ���������һ�������ݵĽڵ�
	struct LinkNode * pCurrent = mylist->pHeader.next;
	for (int i = 0; i < mylist->m_size; i++)
	{
		//�ص�������Ϊ�����û��Լ�ȥ��ӡ���� ��Ϊ�������û������ ��֪��Ӧ�ô�ӡʲô
		myprient(pCurrent);
		//Ȼ�����������һ���ڵ�
		pCurrent = pCurrent->next;
	}

}

void removebyposLinkList(LinkList list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	//����������Աָ��list��ʲô  ����ʹ������˵��֪��list��ʲô
	struct LList * mylist = (struct LList *)list;
	if (pos<0 || pos>mylist->m_size)
	{
		return;
	}
	//������ʱ�ڵ�
	//ͨ��ѭ���ҵ�������posλ�õ�ǰһ���ڵ�
	struct LinkNode * pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//�����ɾ���Ľڵ�	
	struct LinkNode *pDel = pCurrent->next;

	//��ʼɾ��
	pCurrent->next = pDel->next;

	//delete pDel;  //�������ڲ�ά���������ͷŷ��������

	//����������
	mylist->m_size--;
}

//��ֵɾ���ڵ�
void removebyvalueLinkList(LinkList list, LinkList data, int(*compare)(LinkList, LinkList))
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//����������Աָ��list��ʲô  ����ʹ������˵��֪��list��ʲô
	struct LList * mylist = (struct LList *)list;

	//����������ʱ�ڵ�
	struct LinkNode * pPrve = &mylist->pHeader;
	struct LinkNode * pCurrent = pPrve->next;

	for (int i = 0; i < mylist->m_size; i++)
	{
		//�����û�ȥ������αȽ�
		if (compare(pCurrent, data))
		{
			//����ָ��ָ��
			pPrve->next = pCurrent->next;

			//ɾ���ڵ�
			pCurrent = NULL;

			mylist->m_size--;
			//��breakֻɾ����һ����data��ͬ�� ��break��ɾ����data��ͬ�����нڵ�
			break;
		}
		//����ָ��ָ�����
		pPrve = pCurrent;
		pCurrent = pCurrent->next;

	}
}

//�������
void clearLinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	//����������Աָ��list��ʲô  ����ʹ������˵��֪��list��ʲô
	struct LList * mylist = (struct LList *)list;
	mylist->pHeader.next = NULL;
	mylist->m_size = 0;
}

//����������
int size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return 0;
	}

	//����������Աָ��list��ʲô  ����ʹ������˵��֪��list��ʲô
	struct LList * mylist = (struct LList *)list;

	return mylist->m_size;
}

//��������
void destoryLinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	clearLinkList(list);

	delete list;
}

//�û��Զ������������
struct person
{
	struct LinkNode node;  //Լ���õ�ǰ�ĸ��ֽ�
	string name;
	int age;

};

//�û��Լ�д�ıȽϺ���
int structcompare(LinkList data1, LinkList data2)
{
	struct person * p1 = (struct person *)data1;
	struct person * p2 = (struct person *)data2;

	return p1->name == p2->name && p1->age == p2->age;
}
//�û��Լ�д�Ĵ�ӡ����
void myprientstruct(LinkList data)
{
	struct person * p = (struct person *)data;
	cout << "������" << p->name << " ���䣺 " << p->age << endl;
}


void test01()
{
	//��ʼ������
	LinkList list = init_LinkList();

	//׼�������Ԫ��
	struct person p1 = { NULL,"aaa",18 };
	struct person p2 = { NULL,"bbb",19 };
	struct person p3 = { NULL,"ccc",20 };
	struct person p4 = { NULL,"ddd",21 };
	struct person p5 = { NULL,"eee",22 };
	struct person p6 = { NULL,"fff",23 };

	//��������
	insert_linklist(list, 0, &p1);
	insert_linklist(list, 0, &p2);
	insert_linklist(list, 1, &p3);
	insert_linklist(list, 0, &p4);
	insert_linklist(list, 1, &p5);
	insert_linklist(list, 10, &p6);
	
	//ddd eee bbb ccc aaa fff
	//�û���Ҫ�Լ�ָ����ӡʲô���� ��齻���û�ȥд
	foreach_linklist(list, myprientstruct);
	cout << "�����ȣ�" << size_LinkList(list) << endl;

	cout << "--------------��λ��ɾ��------------------" << endl;
	//��λ��ɾ��
	removebyposLinkList(list, 0);
	//ddd bbb ccc aaa fff
	//�û���Ҫ�Լ�ָ����ӡʲô���� ��齻���û�ȥд
	foreach_linklist(list, myprientstruct);
	cout << "�����ȣ�" << size_LinkList(list) << endl;

	cout << "--------------��ֵɾ��------------------" << endl;
	struct person p7 = { NULL,"ccc",20 };
	//��ֵɾ��
	removebyvalueLinkList(list, &p7, structcompare);
	//ddd bbb aaa fff
	//�û���Ҫ�Լ�ָ����ӡʲô���� ��齻���û�ȥд
	foreach_linklist(list, myprientstruct);
	cout << "�����ȣ�" << size_LinkList(list) << endl;

	cout << "--------------�������------------------" << endl;

	clearLinkList(list);
	foreach_linklist(list, myprientstruct);
	cout << "�����ȣ�" << size_LinkList(list) << endl;

	cout << "--------------��������------------------" << endl;
	destoryLinkList(list);
}

int main()
{
	test01();
	system("pause");
	return 0;
}