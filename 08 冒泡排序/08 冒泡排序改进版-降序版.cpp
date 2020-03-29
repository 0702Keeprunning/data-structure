#include <iostream>
#include <ctime>

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
void bubblesort(int *arr, int length)
{
	int flag = 1;
	for (int i = 0; i < length&&flag == 1; i++)
	{
		flag = 0;
		for (int j = length - 1; j > i; j--)
		{
			if (arr[j - 1] < arr[j])
			{
				flag = 1;
				swap(arr[j - 1], arr[j]);
			}
		}
	}
}
int main()
{
	int arr[] = { 0,4,2,8,6,5,7,1,3,9 };
	int length = sizeof(arr) / sizeof(int);
	printsort(arr, length);
	bubblesort(arr, length);
	printsort(arr, length);
	system("pause");
	return 0;
}