#include <iostream>

using namespace std;


void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void printsort(int *arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void insertsort(int *arr, int length)
{
	int temp;
	int i, j;
	for (i = 1; i < length ; i++)
	{
		if (arr[i] > arr[i - 1])
		{
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] < temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}
int main()
{
	int arr[] = { 0,4,2,8,6,5,7,1,3,9 };
	int length = sizeof(arr) / sizeof(int);
	printsort(arr, length);
	insertsort(arr, length);
	printsort(arr, length);
	system("pause");
	return 0;
}