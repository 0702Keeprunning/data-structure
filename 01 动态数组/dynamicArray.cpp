#include "dynamicArray.h"

//初始化数组
struct dynamicArray * init_dynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}
	//在堆区创建一个数组结构体
	struct dynamicArray * array = new struct dynamicArray;

	//判断array是否建立成功
	if (NULL == array)
	{
		return 0;
	}

	//设置容量
	array->m_capacity = capacity;

	//设置数组当前大小
	array->m_size = 0;

	//在堆区创建一个数组
	//
	array->pAddr = new void*[array->m_capacity];

	return array;
}

//插入功能
void insert_dynamicArray(struct dynamicArray *array, int pos, void * data)
{
	if (array == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos<0 || pos>array->m_size - 1)
	{
		//无效位置 强制进行尾插
		pos = array->m_size;
	}

	//先判断是否已经满载，如果满载，动态开辟新的堆区内存
	if (array->m_size >= array->m_capacity)
	{
		//1、申请一个更大的空间
		int newcapaticy = array->m_capacity * 2;
		//2、创建新的空间
		void **newspace = new void*[newcapaticy];
		//3、将原有空间的数据拷贝到新空间中
		memcpy(newspace, array->pAddr, sizeof(void *)*array->m_capacity);
		//4、释放原有空间
		delete array->pAddr;
		//5、更改指针的指向
		array->pAddr = newspace;
		//6、更新容量
		array->m_capacity = newcapaticy;
	}

	//插入新的数据元素

	//从最后一个位置开始，依次移动数据
	for (int i = array->m_size - 1; i >= pos; i--)
	{
		array->pAddr[i + 1] = array->pAddr[i];
	}

	//将新元素插入到指定位置
	array->pAddr[pos] = data;

	//更新一下当前数组的大小
	array->m_size++;
}

//遍历数组
void foreach_dynamicArray(struct dynamicArray *array, void(*myForeach)(void *))
{
	if (array == NULL)
	{
		cout << "数组为空" << endl;
		return;
	}
	if (myForeach == NULL)
	{
		return;
	}

	for (int i = 0; i < array->m_size; i++)
	{
		myForeach(array->pAddr[i]);
	}
}

//删除数组中元素--按照位置来删除
void removeByPos_dynamicArray(struct dynamicArray *array, int pos)
{
	if (array == NULL)
	{
		return;
	}
	if (pos<0 || pos>array->m_size - 1)
	{
		//无效位置 
		return;
	}

	for (int i = pos; i < array->m_size - 1; i++)
	{
		array->pAddr[i] = array->pAddr[i + 1];
	}

	array->m_size--;

}

//删除数组中的元素--按照值来进行删除
void removeByPos_dynamicArray(struct dynamicArray *array, void *data, int(*myCompare)(void *, void *))
{
	if (array == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	for (int i = 0; i < array->m_size; i++)
	{
		if (myCompare(array->pAddr[i], data))
		{
			removeByPos_dynamicArray(array, i);
			break;
		}
	}
}

//销毁数组
void destory_dynamicArray(struct dynamicArray *array)
{
	if (array == NULL)
	{
		return;
	}

	if (array->pAddr != NULL)
	{
		delete array->pAddr;
	}
	delete array;
	array = NULL;

}