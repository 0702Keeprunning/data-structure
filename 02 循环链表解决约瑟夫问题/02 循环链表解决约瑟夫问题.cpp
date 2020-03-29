#include <iostream>
#include <string>
using namespace std;


struct Linknode {
	Linknode * next; //ֻά��ָ����
};
struct Llist {
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

void foreach_Linklist(Llist * mylist, void(*myprient)(void *))
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
		if (mycompare(pCurrent, data))
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
		return;
	}
	delete mylist;
}

struct yuesefu {
	Linknode * node;
	int value;
};


void personprient(void * list)
{
	yuesefu * p = (yuesefu *)list;
	cout << p->value << " ";
}
bool compare(void * mylist, void * data)
{
	yuesefu *p1 = (yuesefu*)mylist;
	yuesefu *p2 = (yuesefu*)data;

	return p1->value == p2->value;
}
//�ܹ�M���� ÿ����N��ʱ���  ֪���˸�ֵ�����

#define M 8
#define N 3


int main()
{
	//�����б�
	Llist *mylist = Linklist_init();
	//����ֵ
	yuesefu num[M]; //����M��ֵ
	for (int i = 0; i < M; i++)
	{
		num[i].value = i + 1;
		//���뵽ѭ��������
		insert_Linklist(mylist, i, &num[i]);
	}
	foreach_Linklist(mylist, personprient);
	cout << endl;

	//���Լɪ������

	int index = 1;
	//ָ���һ�����ݵ�ָ��
	Linknode * pCurrent = mylist->pHeader.next;
	//�����������ݲ�Ϊһʱ
	while (size_linklist(mylist) > 0)
	{
		if (index == N)
		{
			//����������и�λ�õ�ֵ
			yuesefu * numvalue = (yuesefu *)pCurrent;
			cout << numvalue->value << " ";
			//Ȼ���λ�õ�ֵɾ��
			Linknode * pnetx = pCurrent->next;
			removebyvalue_linklist(mylist, pCurrent, compare);
			//�õ�ǰ��������һ���ڵ�
			pCurrent = pnetx;
			//�������ͷ���
			if (pCurrent == &mylist->pHeader)
			{
				pCurrent = mylist->pHeader.next;
			}
			index = 1;
				
		}
		pCurrent = pCurrent->next;
		//�������ͷ��� ָ���һ�����ݽ��
		if (pCurrent == &mylist->pHeader)
		{
			pCurrent = mylist->pHeader.next;
		}
		index++;
	}
	cout << endl;

	
	system("pause");
	return 0;
}

	