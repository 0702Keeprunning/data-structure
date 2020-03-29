#pragma once
#include <iostream>
#include <string>
using namespace std;

//动态数组结构体
struct dynamicArray
{
	void **pAddr;	//维护在堆区的数组的指针
	int m_capacity;	//数组的容量
	int m_size;		//数组的大小
};

//初始化数组
struct dynamicArray * init_dynamicArray(int capacity);


//插入功能
void insert_dynamicArray(struct dynamicArray *array, int pos, void * data);


//遍历数组
void foreach_dynamicArray(struct dynamicArray *array, void(*myForeach)(void *));


//删除数组中元素--按照位置来删除
void removeByPos_dynamicArray(struct dynamicArray *array, int pos);


//删除数组中的元素--按照值来进行删除
void removeByPos_dynamicArray(struct dynamicArray *array, void *data, int(*myCompare)(void *, void *));


//销毁数组
void destory_dynamicArray(struct dynamicArray *array);
