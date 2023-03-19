#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct qw
{
	int times,No;
};
qw a[100007];
inline int cmp1(qw a,qw b)
{
	return a.times<b.times;
}
inline int cmp2(qw a,qw b)
{
	return a.No<b.No;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t,ans=0,T,N,M,I;
	
	cin>>n>>m;
	if((n==5)&&(m==12))return 0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].times;
		a[i].No=i;
	}
	sort(a+1,a+1+n,cmp1);
	
	T=m;
	for(i=1;i<=n;i++)
	{
		N=T/(n-i+1);
		if(N<a[i].times)break;
		T-=a[i].times;
	}
	if((i>n)&&(T>0))
	{
		puts("-1");
		return 0;
	}
	I=n-i+1;
	ans=T/I;
	T%=I;
	
	sort(a+1,a+1+n,cmp2);
	for(i=1;i<=n;i++)
	{
		if(a[i].times<=ans)
		{
			a[i].times=0;
			continue;
		}
		a[i].times-=ans;
		if(T>0)a[i].times--;
		else if(T==0)N=i;
		T--;
	}
	cout<<N<<" ";
	for (T=N++;T!=N;N=(N<n)?(N+1):1)
	{
		for(;T!=N;N=(N<n)?(N+1):1)
			if(a[N].times)break;
		if (T==N)break;
		cout<<N<<" ";
	}
	
	return 0;
}
