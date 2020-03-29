#include <iostream>
#include <string>
using namespace std;


struct Linknode {
	Linknode * next; //ֻά��ָ����
};
struct Llist{
	Linknode pHeader;//����ͷ���
	int m_size;
};
//��ʼ������
Llist * Linklist_init()
{
	Llist * mylist = new Llist;
	if (mylist == NULL)
	{
		return NULL;
	}
	mylist->m_size = 0;
	mylist->pHeader.next = &mylist->pHeader;
}
void insert_Linklist(Llist * mylist, int pos, void * data)
{
	if (mylist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	if (pos<0 || pos>mylist->m_size)
	{
		pos = mylist->m_size;
	}
	//�ҵ�posǰ��һ�����
	Linknode * pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//��һ���½�㱣�����������
	Linknode * newnode = (Linknode *)data;

	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	mylist->m_size++;

}

void foreach_Linklist(Llist * mylist,void(*myprient)(void *))
{
	if (mylist == NULL)
	{
		return;
	}
	//��һ�����
	Linknode * pCurrent = mylist->pHeader.next;
	for (int i = 0; i < mylist->m_size; i++)
	{
		//���������һȦ Ӧ����pcurrentָ���һ������ӡ
		if (pCurrent == &mylist->pHeader)
			pCurrent = mylist->pHeader.next;
		myprient(pCurrent);
		pCurrent = pCurrent->next;
	}
}
//����λ��ɾ�����
void removebypos_linklist(Llist * mylist, int pos)
{
	if (mylist == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= mylist->m_size)
	{
		return;
	}
	//�ҵ�posǰ��һ�����
	Linknode * pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//��ǰ��ɾ�����
	//��һ���½�㱣�����������
	Linknode * del = pCurrent->next;

	pCurrent->next = del->next;

	mylist->m_size--;
}
//����ֵɾ�����
void removebyvalue_linklist(Llist * mylist, void * data, bool(*mycompare)(void *, void *))
{
	if (mylist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	Linknode * pPrv = &mylist->pHeader;
	//��ǰ���
	Linknode * pCurrent = mylist->pHeader.next;
	for (int i = 0; i < mylist->m_size; i++)
	{
		//����ҵ�
		if(mycompare(pCurrent,data))
		{
			pPrv->next = pCurrent->next;

			mylist->m_size--;

			break;
		}
		pPrv = pPrv->next;
		pCurrent = pCurrent->next;
	}


}
//����������
int size_linklist(Llist * mylist)
{
	if (mylist == NULL)
	{
		return 0;
	}
	return mylist->m_size;
}

//�������
void clear_linklist(Llist * mylist)
{
	if (mylist == NULL)
	{
		return;
	}
	mylist->pHeader.next = &mylist->pHeader;
	mylist->m_size = 0;
}
//��������
void destroy_linklist(Llist * mylist)
{
	if (mylist == NULL)
	{
		return ;
	}
	delete mylist;
}

struct person{
	Linknode * node;
	string m_name;
	int age;
};


void personprient(void * list)
{
	person * p = (person *)list;
	cout << "������" << p->m_name << " ���䣺" << p->age << endl;
}
bool compare(void * mylist, void * data)
{
	person *p1 = (person*)mylist;
	person *p2 = (person*)data;

	return p1->m_name == p2->m_name && p1->age == p2->age;
}
int main()
{
	//�����б�
	Llist *mylist = Linklist_init();
	//
	//׼�������Ԫ��
	person p1 = { NULL,"aaa",18 };
	person p2 = { NULL,"bbb",19 };
	person p3 = { NULL,"ccc",20 };
	person p4 = { NULL,"ddd",21 };
	person p5 = { NULL,"eee",22 };
	person p6 = { NULL,"fff",23 };
	//��������
	insert_Linklist(mylist, 0, &p1);
	insert_Linklist(mylist, 0, &p2);
	insert_Linklist(mylist, 1, &p3);
	insert_Linklist(mylist, 0, &p4);
	insert_Linklist(mylist, 1, &p5);
	insert_Linklist(mylist, 10, &p6);
	foreach_Linklist(mylist, personprient);

	cout << size_linklist(mylist) << endl;
	cout << "-------------------------" << endl;
	removebypos_linklist(mylist, 0);
	foreach_Linklist(mylist, personprient);
	cout << size_linklist(mylist) << endl;
	cout << "-------------------------" << endl;
	person p7 = { NULL,"fff",23 };
	removebyvalue_linklist(mylist, &p7, compare);
	foreach_Linklist(mylist, personprient);
	cout << size_linklist(mylist) << endl;
	cout << "-------------------------" << endl;
	clear_linklist(mylist);
	foreach_Linklist(mylist, personprient);
	cout << size_linklist(mylist) << endl;
	cout << "-------------------------" << endl;
	destroy_linklist(mylist);

	system("pause"); 
	return 0;
}

