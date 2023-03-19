#pragma GCC optimize(2)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int pt[10000007],len;
bool pr[100000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	
	for(i=2;i<=100000000;i++)
	{
		if(!pr[i])pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<=100000000;j++)
		{
			pr[i*pt[j]]=1;
			if(i%pt[j]==0)break;
		}
	}
	for(i=1;i<=len;i+=100)cout<<pt[i]<<'\n';
	
	return 0;
}