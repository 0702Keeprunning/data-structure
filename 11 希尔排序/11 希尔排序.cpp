//#include <iostream>
//#include <ctime>
//using namespace std;
//#define MAX 10
//void swap(int &a, int &b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//void printsort(int *arr, int length)
//{
//	for (int i = 0; i < length; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//void shellsort(int *arr, int length)
//{
//	int increasement = length;
//	int i, j, k, temp;
//	//
//	do {
//
//		//确定分组的增量
//		increasement = increasement / 3 + 1;
//		//先确定每个分组的第一个值
//		for (i = 0; i < increasement; i++)
//		{
//			//每个组进行插入排序
//			for (j = i + increasement; j < length; j += increasement)
//			{
//				////判断每组当前数据是否比上一个数小
//				if (arr[j] < arr[j - increasement])
//				{
//					//存储当前数据
//					temp = arr[j];
//					//前面的数比temp大就后移 直到前面没数或者前面的数比temp小
//					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement)
//					{
//
//						arr[k + increasement] = arr[k];
//					}
//					//移动完插入数据
//					arr[k + increasement] = temp;
//				}
//			}
//		}
//
//
//
//	} while (increasement > 1);
//
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int arr[MAX];
//	for (int i = 0; i < MAX; i++)
//	{
//		arr[i] = rand() % MAX;
//	}
//	printsort(arr, MAX);
//	shellsort(arr, MAX);
//	printsort(arr, MAX);
//
//	system("pause");
//	return 0;
//}