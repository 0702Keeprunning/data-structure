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
//�鲢����
void merge(int *arr, int *temp, int start, int end, int mid)
{
	//�������������
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//��־temp���˼�����
	int length = 0;
	//��ʼ�ϲ� ��temp�Ĵ� ֱ������һ������ȫ���Ĵ浽temp��
	while (i_start <= i_end && j_start <= j_end)
	{
		//���i_startָ������ݱ�j_startС �Ȱ����ŵ�temp��
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
	//������������鲻�ȳ� ��������һ�����黹����û�зŵ�temp�м�����
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

	//��ʱ�����ĺ��������Ϊtemp  ���µ�arr��
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i];
	}
}

//�鲢����
void mergesort(int *arr, int *temp, int start, int end)
{
	//�ݹ��������
	if (start >= end)
	{
		return;
	}

	//�ȷֳ�����
	int mid = (start + end) / 2;

	//�ݹ�����
	mergesort(arr, temp, start, mid);
	//�ݹ�����
	mergesort(arr, temp, mid+1, end);

	//�ϲ�
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