#include<iostream>
using namespace std;

//二分查找的条件 必须待查找的关键字是有序的
int Binary_search(int *arr, int n, int key)
{
	int low, high, mid;
	low = 0;
	high = n-1;
	while (low<=high)  //当低位不高于高位时
	{
		//mid = (low + high) / 2;  //二分
		mid = low + (key - arr[low])*(high - low) / (arr[high] - arr[low]);  //插值查找
		if (key < arr[mid])		//查找值比中值小
			high = mid - 1;		//高位下标改成中值下标减一处
		else if (key > arr[mid])
			low = mid + 1;
		else
			return mid;			//查到查找值 则返回查找值的下标
	}
	return -1;  //未查到值 返回-1
}
//斐波那契数列生成
int fbi(int i)
{
	if (i < 2)
		return i == 0 ? 0 : 1;
	return fbi(i - 2) + fbi(i - 1);
}
int f[15] = { 0 };
//斐波那契查找
int fibonacci_search(int *arr, int n, int key)
{
	int low, high, mid, i, k;
	low = 0;
	high = n - 1;
	k = 0;
	//计算长度n位于斐波那契数列的位置
	while (n > f[k] - 1)
	{
		k++;
	}
	for (i = n ; i < f[k] - 1; i++) 
		arr[i] = arr[n - 1];
	while (low<=high)
	{
		mid = low + f[k - 1] - 1;
		if (key < arr[mid])
		{
			high = mid - 1;
			k = k - 1;
		}
		else if (key > arr[mid])
		{
			low = mid + 1;
			k = k - 2;
		}
		else {
			if (mid < n)
				return mid;
			else
				return n;
		}
	}
	return -1;
}

int main()
{
	int arr[20] = { 0, 1, 2, 4, 8, 16, 32, 64 };
	int length = sizeof(arr) / sizeof(int);
	
	for (int i = 0; i < 15; i++)
	{
		f[i] = fbi(i);
		cout << f[i] << " ";
	}
	cout << endl;
	cout << length << endl;
	cout << "二分查找和插值查找" << endl;
	cout << arr[Binary_search(arr, 8, 16)] << endl;
	cout << "斐波那契查找" << endl;
	cout << arr[fibonacci_search(arr, 8, 16)] << endl;


	system("pause");
	return 0;

}