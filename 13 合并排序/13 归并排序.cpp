#include<iostream>
#include<ctime>
using namespace std;
#define MAX 10

void printsort(int *arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//归并函数
void merge(int *arr, int *temp, int start, int end, int mid)
{
	//分离成两个数组
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//标志temp存了几个数
	int length = 0;
	//开始合并 向temp寄存 直到其中一个数组全部寄存到temp中
	while (i_start <= i_end && j_start <= j_end)
	{
		//如果i_start指向的数据比j_start小 先把它放到temp中
		if (arr[i_start] < arr[j_start])
		{
			temp[length] = arr[i_start];
			length++;
			i_start++;
		}
		else
		{
			temp[length] = arr[j_start];
			length++;
			j_start++;
		}
	}
	//如果分两个数组不等长 会有其中一个数组还有数没有放到temp中继续放
	while (i_start <= i_end)
	{
		temp[length] = arr[i_start];
		length++;
		i_start++;
	}
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		length++;
		j_start++;
	}

	//此时重新拍好序的数组为temp  更新到arr中
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i];
	}
}

//归并排序
void mergesort(int *arr, int *temp, int start, int end)
{
	//递归结束条件
	if (start >= end)
	{
		return;
	}

	//先分成两组
	int mid = (start + end) / 2;

	//递归左组
	mergesort(arr, temp, start, mid);
	//递归右组
	mergesort(arr, temp, mid+1, end);

	//合并
	merge(arr, temp, start, end, mid);
}

int main()
{
	int arr[] = { 0,4,2,8,6,5,7,1,3,9 };
	int temp[MAX];

	printsort(arr, MAX);
	mergesort(arr, temp, 0, MAX-1);
	printsort(arr, MAX);

	system("pause");
	return 0;
}