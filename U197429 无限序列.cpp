#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int unsigned long long
using namespace std;
int f[107];
int s(int n)
{
	int p=upper_bound(f+1,f+94,n)-f-1;//找到第一个不大于 
	if(f[p]==n)
		return f[p-1];
	else
		return f[p-1]+s(n-f[p]);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	int MAXN=(1<<63)-1;
	
	f[1]=f[2]=1;
	for(i=3;i<=93;i++)
		f[i]=f[i-1]+f[i-2];
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		cout<<s(m)-s(n-1)<<'\n';
	}
	//1011010110110101101
    return 0;
}
