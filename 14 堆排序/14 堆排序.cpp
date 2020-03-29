#include<iostream>
#include<ctime>

using namespace std;
void printsort(int *arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void heapadjust(int *arr, int index, int length)
{
	//���浱ǰ�ڵ���±�
	int max = index;
	//�ҵ���ǰ�ڵ��������
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;
	//�ж������Ƿ���� ���Ƿ���ڸ��ڵ�index
	if (lchild<length && arr[lchild]>arr[max])
	{
		max = lchild;  //
	}
	if (rchild<length && arr[rchild]>arr[max])
	{
		max = rchild;
	}
	//������ӱȸ��ڵ�� ��������Ǹ�
	if (max != index)
	{
		swap(arr[max], arr[index]);
		//����������Ľڵ�ҲҪ���¿��Ƿ������ ����Ļ������ٽ���if
		heapadjust(arr, max, length);
	}
}
void heapsort(int *arr, int length)
{
	//���ҵ����һ����Ҷ�ӽڵ�ĸ��ڵ� ���д󶥶Ѵ���
	//���������Ϸ����ڵ�  i��ʾ��ǰ�ڵ��±�
	//�Ȱ����ݳ�ʼ���ɴ󶥶�
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		heapadjust(arr, i, length);
	}
	//�����Ѷ��Ͷ����һ��Ԫ�� �ܹ�����
	for (int i = length - 1; i >= 0; i--)
	{
		//����
		swap(arr[0], arr[i]);
		heapadjust(arr, 0, i);
	}

}
int main()
{
	int arr[] = { 0,4,2,8,6,5,7,1,3,9 };
	int length = sizeof(arr) / sizeof(int);
	printsort(arr, length);
	heapsort(arr, length);
	printsort(arr, length);
	system("pause");
	return 0;
}