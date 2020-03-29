//#include <iostream>
//#include <string>
//#include <ctime>
//using namespace std;
//#define MAX 10
//
//void swap(int &a, int &b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//void printsort(int *arr,int length)
//{
//	for (int i = 0; i < length; i++)
//	{
//		cout << arr[i] << " ";
//
//	}
//	cout << endl;
//}
//void bubblesort(int *arr, int length)
//{
//	int i, j;
//	int flag = 1;
//	for (i = 0; i < length &&flag == 1; i++)
//	{
//		flag = 0;
//		for (int j = length - 1; j > i; j--)
//		{
//			if (arr[j - 1] > arr[j])
//			{
//				flag = 1;
//				swap(arr[j - 1], arr[j]);
//
//			}
//		}
//	}
//}
//int main()
//{
//	time_t start, finish;
//	srand((unsigned int)time(NULL));
//	start = clock();
//	//初始化数组
//	int arr[MAX];
//	for (int i = 0; i < MAX; i++)
//	{
//		arr[i] = rand() % MAX;
//	}
//	printsort(arr, MAX);
//	bubblesort(arr, MAX);
//	printsort(arr, MAX);
//	
//	finish = clock();
//	cout << finish - start << "毫秒" << endl;
//	system("pause");
//	return 0;
//}
