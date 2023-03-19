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
signed main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	
	xxs(10000007);
	cout<<pt[n];
	
	return 0;
}
// 1 100000000
