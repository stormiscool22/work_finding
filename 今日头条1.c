/*有 n 个字符串，每个字符串都是由 A-J 的大写字符构成。现在你将每个字符映射为一个 0-9 的数字，不同字符映射为不同的数字。这样每个字符串就可以看做一个整数，唯一的要求是这些整数必须是正整数且它们的字符串不能有前导零。现在问你怎样映射字符才能使得这些字符串表示的整数之和最大？

输入描述:
每组测试用例仅包含一组数据，每组数据第一行为一个正整数 n ， 接下来有 n 行，每行一个长度不超过 12 且仅包含大写字母 A-J 的字符串。 n 不大于 50，且至少存在一个字符不是任何字符串的首字母。


输出描述:
输出一个数，表示最大和是多少。

输入例子:
2
ABC
BCA

输出例子:
1875*/


#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

struct node 
{ 
    int value; 
	bool no_zero;
}; 
bool cmp(struct node a, struct node b) 
{ 
    if(a.value < b.value)
    { 
        return true; 
    } 
    return false; 
} 

void main()
{
	int n,i,j;
	cin>>n;
	node counter[10];
	for(i = 0;i<10;i++)
	{
		counter[i].value = 0;
		counter[i].no_zero = false;
	}
	string temp;
	for(i=0;i<n;i++ )
	{
		cin>>temp;
		int mul = 1;
		for(j=temp.size()-1;j>=0;j--)
		{
			counter[temp[j]-'A'].value+=mul;
			mul*=10;
			if(j==0)
			{
				counter[temp[j]-'A'].no_zero=true;
			}
		}
	}
	sort(counter,counter+10,cmp);
	int sum=0;
	for(i = 0;i<10;i++)
	{
		if( counter[i].no_zero == false)
			break;
	}
	for(j = 9;j>=0;j--)
	{
		if(j>i)  sum+=counter[j].value*j;
		else if(j<i) sum+=(counter[j].value*(j+1));
	}
	cout<<sum<<endl;
	system("pause");
	return;
}
