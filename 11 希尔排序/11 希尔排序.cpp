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
//		//ȷ�����������
//		increasement = increasement / 3 + 1;
//		//��ȷ��ÿ������ĵ�һ��ֵ
//		for (i = 0; i < increasement; i++)
//		{
//			//ÿ������в�������
//			for (j = i + increasement; j < length; j += increasement)
//			{
//				////�ж�ÿ�鵱ǰ�����Ƿ����һ����С
//				if (arr[j] < arr[j - increasement])
//				{
//					//�洢��ǰ����
//					temp = arr[j];
//					//ǰ�������temp��ͺ��� ֱ��ǰ��û������ǰ�������tempС
//					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement)
//					{
//
//						arr[k + increasement] = arr[k];
//					}
//					//�ƶ����������
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