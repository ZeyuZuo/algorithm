// 在数据加密和数据压缩中常需要对特殊的字符串进行编码。给定的字母表 A 由 26 个小
// 写英文字母组成 A={a,b,…,z}。该字母表产生的升序字符串是指字符串中字母按照从左到
// 右出现的次序与字母在字母表中出现的次序相同，且每个字符最多出现 1 次。例如，
// a,b,ab,bc,xyz 等字符串都是升序字符串。现在对字母表 A 产生的所有长度不超过 6 的升序
// 字符串按照字典序排列并编码如下。
// 1 2 … 26 27 28 …
// a b … z  ab ac …
// 对于任意长度不超过 6 的升序字符串，迅速计算出它在上述字典中的编码。

// Input:
// 2
// a
// b

// Output
// 1
// 2

#include<stdio.h>
#include<string.h>

//以start字母打头，长度为len的字符串，总共有多少
int get_num(char start,int len)
{
	if(len == 0)
		return 0;
	if(len == 1)
		return 1;
	
	int sum=0;
	for(char ch=start+1;ch<='z';ch++)
		sum += get_num(ch,len-1);
	return sum;
}

//以start字母打头，长度为len的字符串，前面总共有多少
int get_pre(char start,int len)
{
	int sum = 0;
	
	//所有长度小于len的
	for(char ch='a';ch<='z';ch++)
		for(int l=1;l<len;l++)
			sum+=get_num(ch,l);
	
	
	//长度等于len，但是首字母小于start的
	for(char ch='a';ch<start;ch++)
		sum+=get_num(ch,len);
	return sum;
	
}

int get_sum(char* s)
{
	int sum=0;
	int len = strlen(s);
	//先算前面有多少
	sum += get_pre(s[0],len);
	
	//一定要从s[i-1]+1到s[i]，遍历一下
	for(int i=1;i<len;i++)
		for(char ch=s[i-1]+1;ch<s[i];ch++)
			sum+=get_num(ch,len-i);
	
	//算的都是前面有多少个，数字从1开始，加上1；
	sum+=1;
	return sum;
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char s[8] = "a";
		scanf("%s",s);
		printf("%d\n",get_sum(s));
	}
	return 0;
}
