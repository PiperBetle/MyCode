#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
string s;
int a[100007];
int main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		if(s[i]==')')
			for(j=i-1;j>=0;j--)
				if(s[j]=='('&&a[j]==0)
				{
					a[i]=a[j]=1;
					break;
				}
				else
				{
					if(s[j]=='['&&a[j]==0)
						break;
				}
		if(s[i]==']')
			for(j=i-1;j>=0;j--)
				if(s[j]=='['&&a[j]==0)
				{
					a[i]=a[j]=1;
					break;
				}
				else
				{
					if(s[j]=='('&&a[j]==0)
					break;
				}
	}
	for(i=0;i<n;i++)
		if(a[i]==0)
		{
			if(s[i]=='('||s[i]==')')
				cout<<"()";
			else
				cout<<"[]";
		}
		else
			cout<<s[i];
	
	return 0;
}