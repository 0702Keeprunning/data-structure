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
	//保存当前节点的下标
	int max = index;
	//找到当前节点的左右子
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;
	//判断左子是否存在 且是否大于根节点index
	if (lchild<length && arr[lchild]>arr[max])
	{
		max = lchild;  //
	}
	if (rchild<length && arr[rchild]>arr[max])
	{
		max = rchild;
	}
	//如果儿子比跟节点大 交换大的那个
	if (max != index)
	{
		swap(arr[max], arr[index]);
		//交换后下面的节点也要重新看是否满足堆 满足的话不会再进该if
		heapadjust(arr, max, length);
	}
}
void heapsort(int *arr, int length)
{
	//先找到最后一个非叶子节点的根节点 进行大顶堆处理
	//遍历到最上方根节点  i表示当前节点下标
	//先把数据初始化成大顶堆
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		heapadjust(arr, i, length);
	}
	//交换堆顶和堆最后一个元素 总共交换
	for (int i = length - 1; i >= 0; i--)
	{
		//交换
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