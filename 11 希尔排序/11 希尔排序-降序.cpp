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
void shellsort(int *arr, int length)
{
	int i, j, k;
	int temp;
	int increasement = length;
	do {
		 increasement = increasement / 3 + 1;
		//先分组
		for (i = 0; i < increasement; i++)
		{
			//每个组分别做插入排序
			for (j = i + increasement; j < length; j = j + increasement)
			{
				if (arr[j] > arr[j - increasement])
				{
					temp = arr[j];
					for (k = j - increasement; k >= 0 && arr[k] < temp; k = k - increasement)
					{
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;
				}
			}
		}
	} while (increasement > 1);

}
int main()
{

	int arr[] = { 0,4,2,8,6,9,7,1,3,9 };
	int length = sizeof(arr) / sizeof(int);
	printsort(arr, length);
	shellsort(arr, length);
	printsort(arr, length);
	system("pause");
	return 0;
}