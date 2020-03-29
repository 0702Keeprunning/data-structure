#pragma once
#include <iostream>
#include <string>
using namespace std;

//��̬����ṹ��
struct dynamicArray
{
	void **pAddr;	//ά���ڶ����������ָ��
	int m_capacity;	//���������
	int m_size;		//����Ĵ�С
};

//��ʼ������
struct dynamicArray * init_dynamicArray(int capacity);


//���빦��
void insert_dynamicArray(struct dynamicArray *array, int pos, void * data);


//��������
void foreach_dynamicArray(struct dynamicArray *array, void(*myForeach)(void *));


//ɾ��������Ԫ��--����λ����ɾ��
void removeByPos_dynamicArray(struct dynamicArray *array, int pos);


//ɾ�������е�Ԫ��--����ֵ������ɾ��
void removeByPos_dynamicArray(struct dynamicArray *array, void *data, int(*myCompare)(void *, void *));


//��������
void destory_dynamicArray(struct dynamicArray *array);
