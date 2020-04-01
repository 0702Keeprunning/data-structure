#include<iostream>
using namespace std;

#define HASHSIZE 12 /* ����ɢ�б�Ϊ����ĳ��� */
#define NULLKEY -32768 

int m;	/* ɢ�б����ȫ�ֱ��� */
struct hashtable
{
	int *elem;	/* ����Ԫ�ش洢��ַ����̬�������� */
	int count;	/*  ��ǰ����Ԫ�ظ��� */
};
/* ��ʼ��ɢ�б� */
void inithashtable(hashtable *h)
{
	int i;
	m = HASHSIZE;
	h->count = m;
	h->elem = (int *) new int * [m];

	for (i = 0; i < m; i++)
	{
		h->elem[i] = NULLKEY;
	}
}

/* ɢ�к��� */
int hashs(int key)
{
	return key % m; /* ���������� */
}
/* ����ؼ��ֽ�ɢ�б� */
void inserthash(hashtable *h, int key)
{
	int addr = hashs(key);	/* ��ɢ�е�ַ */
	while (h->elem[addr] != NULLKEY) /* �����Ϊ�գ����ͻ */
	{
		addr = (addr + 1) % m; /* ���Ŷ�ַ��������̽�� */
	}
	h->elem[addr] = key; /* ֱ���п�λ�����ؼ��� */
}
bool searchhash(hashtable *h, int key, int *addr)
{
	*addr = hashs(key);   /* ��ɢ�е�ַ */
	while (h->elem[*addr] != key)	/* �����Ϊ�գ����ͻ */
	{
		*addr = (*addr + 1) % m; /* ���Ŷ�ַ��������̽�� */
		if (h->elem[*addr] == NULLKEY || *addr == hashs(key))	/* ���ѭ���ص�ԭ�� */
			return false;  //����ʧ��
	}
	return true; //���ҳɹ�
}

int main()
{
	int arr[HASHSIZE] = { 12,67,56,16,25,37,22,29,15,47,48,34 };
	int key,i,search;

	hashtable h;

	key = 39;

	inithashtable(&h);

	for ( i = 0; i < m; i++)
	{
		inserthash(&h, arr[i]);
	}
	if (searchhash(&h,key,&search))
	{
		cout << "���ҵ�" << key << "���±�Ϊ��" << search << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}
	cout << "----------------------------" << endl;
	for (i = 0; i < m; i++)
	{
		key = arr[i];
		searchhash(&h, key, &search);
		cout << "���ҵ�" << key << "���±�Ϊ��" << search << endl;
	}

	system("pause");
	return 0;
}
