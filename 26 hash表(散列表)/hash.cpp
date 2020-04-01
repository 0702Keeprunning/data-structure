#include<iostream>
using namespace std;

#define HASHSIZE 12 /* 定义散列表长为数组的长度 */
#define NULLKEY -32768 

int m;	/* 散列表表长，全局变量 */
struct hashtable
{
	int *elem;	/* 数据元素存储基址，动态分配数组 */
	int count;	/*  当前数据元素个数 */
};
/* 初始化散列表 */
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

/* 散列函数 */
int hashs(int key)
{
	return key % m; /* 除留余数法 */
}
/* 插入关键字进散列表 */
void inserthash(hashtable *h, int key)
{
	int addr = hashs(key);	/* 求散列地址 */
	while (h->elem[addr] != NULLKEY) /* 如果不为空，则冲突 */
	{
		addr = (addr + 1) % m; /* 开放定址法的线性探测 */
	}
	h->elem[addr] = key; /* 直到有空位后插入关键字 */
}
bool searchhash(hashtable *h, int key, int *addr)
{
	*addr = hashs(key);   /* 求散列地址 */
	while (h->elem[*addr] != key)	/* 如果不为空，则冲突 */
	{
		*addr = (*addr + 1) % m; /* 开放定址法的线性探测 */
		if (h->elem[*addr] == NULLKEY || *addr == hashs(key))	/* 如果循环回到原点 */
			return false;  //查找失败
	}
	return true; //查找成功
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
		cout << "查找的" << key << "的下标为：" << search << endl;
	}
	else
	{
		cout << "查找失败" << endl;
	}
	cout << "----------------------------" << endl;
	for (i = 0; i < m; i++)
	{
		key = arr[i];
		searchhash(&h, key, &search);
		cout << "查找的" << key << "的下标为：" << search << endl;
	}

	system("pause");
	return 0;
}
