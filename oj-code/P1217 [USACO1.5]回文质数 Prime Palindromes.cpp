#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool pr[10000007];
int pt[10000007];
int len=0;
void xxs(int _n)
{
	int i,j;
	for(i=0;i<_n;i++)pr[i]=1;
	pr[1]=0;
	for(i=2;i<=_n;i++)
	{
		if(pr[i])
		{
			len++;
			pt[len]=i;
		}
		for(j=1;j<=len;j++)
		{
			if(i*pt[j]>_n)break;
			pr[i*pt[j]]=0;
			if(i%pt[j]==0)break;
		}
	}
}
bool rev(int n)
{
	int m=0,t=n;
	while(t)
	{
		m=m*10+t%10;
		t=t/10;
	}
	if(m==n)return 1;
	return 0;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	int a,b;
	
	cin>>a>>b;
	b=min(b,10000000);
	xxs(10000007);
	for(;a<=b;a++)
		if(pr[a]==1)
			if(rev(a)==1)
				cout<<a<<'\n';
	
	return 0;
}
// 1 100000000
