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

//��������
void quicksort(int *arr, int start, int end)
{
	int i = start;
	int j = end;
	//��׼ֵ 
	int temp = arr[start];
	//������ֹ����
	if (i < j)
	{
		//���i<j ��ôһֱ�ڿ�����
		while (i < j)
		{
			//�ȴ��������ұȻ�׼ֵС���� Ȼ��ŵ���׼ֵ�����
			while (i<j && arr[j]>=temp)
			{
				j--;
			}
			//�˳�ѭ�� ���i<j֤���ҵ��˱�tempС����
			//��ʼ���
			if (i < j)
			{
				arr[i] = arr[j];
				//��iǰ��һ��λ��
				i++;
			}
			

			//�ٴ��������ұȻ�׼ֵ����� Ȼ��ŵ���׼ֵ���ұ�
			while (i<j && arr[i]<temp)
			{
				i++;
			}
			//�˳�ѭ�� ���i<j֤���ҵ��˱�temp�����
			//��ʼ���
			if (i < j)
			{
				arr[j] = arr[i];
				//��j����һ��λ��
				j--;
			}
			
		}
		//ֱ��i=j,Ҫ�ѻ�׼ֵ�i=j��
		arr[i] = temp;
		//�ݹ�
		//��׼ֵ�������� 0~i-1
		quicksort(arr, 0, (i - 1));
		//��׼ֵ����ȥ�� i+1~end-1
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

