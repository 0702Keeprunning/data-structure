//#define _CRT_SECURE_NO_WARNINGS //允许使用旧模板库
//#include <iostream>
//
//#include <ctime>
//#define MAX 10
//using namespace std;
//void swap(int &a, int &b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//void printarr(int *arr, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//void InsertSort(int *arr, int length)
//{
//	int i, j;
//	for (i = 1; i < length; i++)
//	{
//		//如果当前数比上一个数小
//		if (arr[i] < arr[i - 1])
//		{
//			//缓存一下当前待插入的数据
//			int temp = arr[i];
//			//从当前数据后一个位置开始，如果temp小，就将前面数据往后移动
//			for (j = i - 1; j >= 0 && temp < arr[j]; j--)
//			{
//				arr[j + 1] = arr[j];
//			}
//			arr[j + 1] = temp;
//		}
//	}
//}
//
//int main()
//{
//	clock_t start, finish;
//	srand((unsigned int)time(NULL));
//
//	int arr[MAX];
//	for (int i = 0; i < MAX; i++)
//	{
//		arr[i] = rand() % MAX;
//	}
//	start = clock();
//	printarr(arr, MAX);
//	InsertSort(arr, MAX);
//	printarr(arr, MAX);
//	
//	finish = clock();
//	cout << finish - start << "毫秒" << endl;
//
//	system("pause");
//	return 0;
//}