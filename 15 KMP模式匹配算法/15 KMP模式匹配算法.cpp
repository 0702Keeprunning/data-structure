#include<iostream>
#include<string>
using namespace std;

//***************普通模式匹配算法
//***************返回值 主串中与子串匹配的第一个位置
//***************例如  
//***************    goodgoodle
//***************        google
//***************返回值为4
//***************s--主串  t--子串  pos从主串的pos位置开始测

int BF_index(string s, string t, int pos)
{
	int i = pos;  
	int j = 0;	  

	//这里隐含强制转换  两个字符串的长度
	int sl = s.length();
	int tl = t.length();
	//如果i 和 j小于他们的长度
	while (i < sl && j < tl)
	{
		//如果两个位置的字符相同
		if (s[i] == t[j])
		{
			//更新位置
			i++;
			j++;
		}
		else {				//两个字符不相等 i和j后退重新开始匹配
			i = i - j + 1; //主串 i移动到上一次匹配成功后的下一个位置
			j = 0;		//子串 j从头开始
		}
	}
	//找到了 返回主串下标
	if (j >= tl)
	{
		return i - tl;
	}
	else
	{
		return -1; //未找到
	}
}


//***************KMP模式匹配算法

//***************获取子串j的数值变化数组
//这个函数很难理解 
void get_next(string t, int *next)
{
	int i = 0;  //后缀下标
	int j = -1; //前缀下标
	next[0] = -1;
	while (i < t.length())
	{
		//如果子串中找到了最长的两个相等的子子串
		if (j == -1 || t[i] == t[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		//否则回溯到上一次相等的两个子子串
		else
		{
			j = next[j];
		}
	}
}
//KMP改进的next
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
			//如果当前字符与前缀字符不同 
			if (t[i] != t[j])
				next[i] = j;
			//如果相同 则用前缀的next
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
	//定义子串j的变化的数组
	int next[255];

	//这里隐含强制转换  两个字符串的长度
	int sl = s.length();
	int tl = t.length();

	//获取数组
	//get_next(t, next);
	//改进后的获取数组
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
	
	cout << "-----------BF普通模式匹配算法-------------" << endl;
	cout << BF_index(str1, str2, 0) << endl;

	cout << "-----------KMP模式匹配算法-------------" << endl;
	cout << KMP_index(str1, str2, 0) << endl;
	system("pause");
	return 0;
}