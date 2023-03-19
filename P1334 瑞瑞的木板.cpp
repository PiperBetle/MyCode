#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int a[100007],l=0;
inline void swap(int &x,int &y)
{
	x^=y;
	y^=x;
	x^=y;
}
inline void up(int x)
{
	int j=x,k;
	while(j>1)
	{
		k=(j>>1);
		if(a[j]>=a[k])break;
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
		if((k<l)&&(a[k]>a[k+1]))++k;
		if(a[k]>=a[j])break;
		swap(a[j],a[k]);
		j=k;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int i,j,k,n;
	long long ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		up(i);
	}
	l=n;
	for(i=1;i<n;i++)
	{
		k=a[1];
		a[1]=a[l];
		l--;
		down(1);
		
		k+=a[1];
		a[1]=a[l];
		l--;
		down(1);
		
		ans+=k;
		l++;
		a[l]=k;
		up(l);
	}
	cout<<ans;
	
	return 0;
}
