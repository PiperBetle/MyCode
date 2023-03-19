#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
struct qw
{
	int num,d;
};
qw a[107],b[107];
int l=0,t[107];
inline void up(int x)
{
	int j=x,k;
	while(j>1)
	{
		k=(j>>1);
		if(a[j].num<=a[k].num)break;
		swap(a[j],a[k]);
		j=k;
	}
}
inline void down(int x)
{
	int j=x,k;
	while((j<<1)<=l)
	{
		k=(j<<1);
		if((k<l)&&(a[k].num<a[k+1].num))++k;
		if(a[k].num<=a[j].num)break;
		swap(a[j],a[k]);
		j=k;
	}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T,ans=0,maxn=0,h;
	qw awa;
	
	cin>>n>>h;
	h*=60;
	for(i=1;i<=n;i++)cin>>b[i].num;
	for(i=1;i<=n;i++)cin>>b[i].d;
	for(i=1;i<n;i++)cin>>t[i];
	for(i=1;i<=n;i++)
	{
		l=0;
		ans=0;
		T=h;
		for(j=1;j<i;j++)T-=t[j]*5;
		for(j=1;j<=i;j++)
		{
			l++;
			a[l]=b[j];
			up(l);
		}
		while(T>0&&a[1].num>0)
		{
			qw awa=a[1];
			ans+=awa.num;
			
			a[1]=a[l];
			l--;
			down(1);
			
			awa.num-=awa.d;
			
			l++;
			a[l]=awa;
			up(l);
			
			T-=5;  
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	
	return 0;
}
