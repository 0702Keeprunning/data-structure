//#include <iostream>
//#include <string>
//#include <ctime>
//using namespace std;
//#define MAX 10
//void swap(int& a, int& b)
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
//void selectsort(int *arr, int length)
//{
//	int i, j, min;
//	for (i = 0; i < length; i++)
//	{
//		min = i;
//		for (j = i + 1; j < length; j++)
//		{
//			if (arr[j] < arr[min])
//			{
//				min = j;
//			}
//		}
//		swap(arr[i], arr[min]);
//	}
//}
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	time_t start, finish;
//	start = clock();
//	int arr[MAX];
//	for (int i = 0; i < MAX; i++)
//	{
//		arr[i] = rand() % MAX;
//	}
//	printsort(arr, MAX);
//	selectsort(arr, MAX);
//	printsort(arr, MAX);
//	finish = clock();
//	cout << finish - start << "ºÁÃë" << endl;
//	system("pause");
//	return 0;
//}