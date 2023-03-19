#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	int i,j,k;
	int n,T;
	int ans=0,len;
	string aa,bb;
	int a[11],b[11];
	
	cin>>aa>>bb;
	if(aa.length()!=bb.length())
	{
		cout<<"WRONG_ANSWER";
		return 0;
	}
	len=aa.length();
	for(i=0;i<len;i++)
		a[i]=aa[i]-'0';
	for(i=0;i<len;i++)
		b[i]=bb[i]-'0';
	sort(a,a+len);
	i=0;
	while(a[i]==0&&i<len)i++;
	swap(a[0],a[i]);
	for(i=0;i<len;i++)
		if(a[i]!=b[i])
		{
			cout<<"WRONG_ANSWER";
			return 0;
		}
	cout<<"OK";
	
	return 0;
}
