#include "dynamicArray.h"

//��ʼ������
struct dynamicArray * init_dynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}
	//�ڶ�������һ������ṹ��
	struct dynamicArray * array = new struct dynamicArray;

	//�ж�array�Ƿ����ɹ�
	if (NULL == array)
	{
		return 0;
	}

	//��������
	array->m_capacity = capacity;

	//�������鵱ǰ��С
	array->m_size = 0;

	//�ڶ�������һ������
	//
	array->pAddr = new void*[array->m_capacity];

	return array;
}

//���빦��
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
		//��Чλ�� ǿ�ƽ���β��
		pos = array->m_size;
	}

	//���ж��Ƿ��Ѿ����أ�������أ���̬�����µĶ����ڴ�
	if (array->m_size >= array->m_capacity)
	{
		//1������һ������Ŀռ�
		int newcapaticy = array->m_capacity * 2;
		//2�������µĿռ�
		void **newspace = new void*[newcapaticy];
		//3����ԭ�пռ�����ݿ������¿ռ���
		memcpy(newspace, array->pAddr, sizeof(void *)*array->m_capacity);
		//4���ͷ�ԭ�пռ�
		delete array->pAddr;
		//5������ָ���ָ��
		array->pAddr = newspace;
		//6����������
		array->m_capacity = newcapaticy;
	}

	//�����µ�����Ԫ��

	//�����һ��λ�ÿ�ʼ�������ƶ�����
	for (int i = array->m_size - 1; i >= pos; i--)
	{
		array->pAddr[i + 1] = array->pAddr[i];
	}

	//����Ԫ�ز��뵽ָ��λ��
	array->pAddr[pos] = data;

	//����һ�µ�ǰ����Ĵ�С
	array->m_size++;
}

//��������
void foreach_dynamicArray(struct dynamicArray *array, void(*myForeach)(void *))
{
	if (array == NULL)
	{
		cout << "����Ϊ��" << endl;
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

//ɾ��������Ԫ��--����λ����ɾ��
void removeByPos_dynamicArray(struct dynamicArray *array, int pos)
{
	if (array == NULL)
	{
		return;
	}
	if (pos<0 || pos>array->m_size - 1)
	{
		//��Чλ�� 
		return;
	}

	for (int i = pos; i < array->m_size - 1; i++)
	{
		array->pAddr[i] = array->pAddr[i + 1];
	}

	array->m_size--;

}

//ɾ�������е�Ԫ��--����ֵ������ɾ��
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

//��������
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