#include<iostream>
using namespace std;

//���ֲ��ҵ����� ��������ҵĹؼ����������
int Binary_search(int *arr, int n, int key)
{
	int low, high, mid;
	low = 0;
	high = n-1;
	while (low<=high)  //����λ�����ڸ�λʱ
	{
		//mid = (low + high) / 2;  //����
		mid = low + (key - arr[low])*(high - low) / (arr[high] - arr[low]);  //��ֵ����
		if (key < arr[mid])		//����ֵ����ֵС
			high = mid - 1;		//��λ�±�ĳ���ֵ�±��һ��
		else if (key > arr[mid])
			low = mid + 1;
		else
			return mid;			//�鵽����ֵ �򷵻ز���ֵ���±�
	}
	return -1;  //δ�鵽ֵ ����-1
}
//쳲�������������
int fbi(int i)
{
	if (i < 2)
		return i == 0 ? 0 : 1;
	return fbi(i - 2) + fbi(i - 1);
}
int f[15] = { 0 };
//쳲���������
int fibonacci_search(int *arr, int n, int key)
{
	int low, high, mid, i, k;
	low = 0;
	high = n - 1;
	k = 0;
	//���㳤��nλ��쳲��������е�λ��
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
	cout << "���ֲ��ҺͲ�ֵ����" << endl;
	cout << arr[Binary_search(arr, 8, 16)] << endl;
	cout << "쳲���������" << endl;
	cout << arr[fibonacci_search(arr, 8, 16)] << endl;


	system("pause");
	return 0;

}