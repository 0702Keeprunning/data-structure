#include<iostream>
#include<string>
using namespace std;

//***************��ͨģʽƥ���㷨
//***************����ֵ ���������Ӵ�ƥ��ĵ�һ��λ��
//***************����  
//***************    goodgoodle
//***************        google
//***************����ֵΪ4
//***************s--����  t--�Ӵ�  pos��������posλ�ÿ�ʼ��

int BF_index(string s, string t, int pos)
{
	int i = pos;  
	int j = 0;	  

	//��������ǿ��ת��  �����ַ����ĳ���
	int sl = s.length();
	int tl = t.length();
	//���i �� jС�����ǵĳ���
	while (i < sl && j < tl)
	{
		//�������λ�õ��ַ���ͬ
		if (s[i] == t[j])
		{
			//����λ��
			i++;
			j++;
		}
		else {				//�����ַ������ i��j�������¿�ʼƥ��
			i = i - j + 1; //���� i�ƶ�����һ��ƥ��ɹ������һ��λ��
			j = 0;		//�Ӵ� j��ͷ��ʼ
		}
	}
	//�ҵ��� ���������±�
	if (j >= tl)
	{
		return i - tl;
	}
	else
	{
		return -1; //δ�ҵ�
	}
}


//***************KMPģʽƥ���㷨

//***************��ȡ�Ӵ�j����ֵ�仯����
//�������������� 
void get_next(string t, int *next)
{
	int i = 0;  //��׺�±�
	int j = -1; //ǰ׺�±�
	next[0] = -1;
	while (i < t.length())
	{
		//����Ӵ����ҵ������������ȵ����Ӵ�
		if (j == -1 || t[i] == t[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		//������ݵ���һ����ȵ��������Ӵ�
		else
		{
			j = next[j];
		}
	}
}
//KMP�Ľ���next
void get_next_good(string t, int *next)
{
	int i = 0;
	int j = -1;
	next[0] = -1;
	while (i < t.length())
	{
		if (j == -1 || t[i] == t[j])
		{
			i++;
			j++;
			//�����ǰ�ַ���ǰ׺�ַ���ͬ 
			if (t[i] != t[j])
				next[i] = j;
			//�����ͬ ����ǰ׺��next
			else
				next[i] = next[j];
		}
		else
		{
			j = next[j];
		}
	}
}

int KMP_index(string s, string t, int pos)
{
	int i = pos;
	int j = 0;
	//�����Ӵ�j�ı仯������
	int next[255];

	//��������ǿ��ת��  �����ַ����ĳ���
	int sl = s.length();
	int tl = t.length();

	//��ȡ����
	//get_next(t, next);
	//�Ľ���Ļ�ȡ����
	get_next_good(t, next);
	while (i < sl && j < tl)
	{
		if (j == -1 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];

		}
	}
	if (j >= tl)
	{
		return i - t.length();

	}
	else
	{
		return -1;
	}

}

int main()
{
	string str1 = "aaaaaabaaaaaaadcdef";
	string str2 = "aaaaaadc";
	
	cout << "-----------BF��ͨģʽƥ���㷨-------------" << endl;
	cout << BF_index(str1, str2, 0) << endl;

	cout << "-----------KMPģʽƥ���㷨-------------" << endl;
	cout << KMP_index(str1, str2, 0) << endl;
	system("pause");
	return 0;
}