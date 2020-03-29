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
void slectsort(int *arr, int length)
{
	int max;
	for (int i = 0; i < length; i++)
	{
		max = i;
		for (int j = i+1; j < length; j++)
		{
			if (arr[j] > arr[max])
			{
				max = j;
			}
		}
		swap(arr[i], arr[max]);
	}
}
int main()
{
	int arr[] = { 0,4,2,8,6,5,7,1,3,9 };
	int length = sizeof(arr) / sizeof(int);
	printsort(arr, length);
	slectsort(arr, length);
	printsort(arr, length);
	system("pause");
	return 0;
}