#include <iostream>
#include <ctime>
#include <string>
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

//快速排序
void quicksort(int *arr, int start, int end)
{
	int i = start;
	int j = end;
	//基准值 
	int temp = arr[start];
	//迭代终止条件
	if (i < j)
	{
		//如果i<j 那么一直挖坑填数
		while (i < j)
		{
			//先从右往左找比基准值小的数 然后放到基准值的左边
			while (i<j && arr[j]>=temp)
			{
				j--;
			}
			//退出循环 如果i<j证明找到了比temp小的数
			//开始填坑
			if (i < j)
			{
				arr[i] = arr[j];
				//让i前移一个位置
				i++;
			}
			

			//再从左往右找比基准值大的数 然后放到基准值的右边
			while (i<j && arr[i]<temp)
			{
				i++;
			}
			//退出循环 如果i<j证明找到了比temp大的数
			//开始填坑
			if (i < j)
			{
				arr[j] = arr[i];
				//让j后移一个位置
				j--;
			}
			
		}
		//直到i=j,要把基准值填到i=j处
		arr[i] = temp;
		//递归
		//基准值的左区间 0~i-1
		quicksort(arr, 0, (i - 1));
		//基准值的右去加 i+1~end-1
		quicksort(arr, (i + 1), end);

	}
}
int main()
{
	int arr[] = { 4,2,8,6,5,7,1,3,9 };
	int length = sizeof(arr) / sizeof(int);
	printsort(arr, length);
	quicksort(arr, 0, length-1);
	printsort(arr, length);

	system("pause");
	return 0;
}

