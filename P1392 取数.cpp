#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline void swap(int &x,int &y){x^=y;y^=x;x^=y;}
int q[1000007],len,a[1000007],b[1000007];
inline void get(int x)
{
	len++;
	q[len]=x;
	int j=len,k;
	while(j>1)
	{
		k=j>>1;
		if(q[j]<=q[k])return;
		swap(q[j],q[k]);
		j=k;
	}
}
inline int put()
{
	int t=q[1],j=1,k;
	q[1]=q[len];
	len--;
	while((j<<1)<=len)
	{
		k=j<<1;
		if((k<len)&&(q[k+1]>q[k]))k++;
		if(q[j]>=q[k])return t;
		swap(q[j],q[k]);
		j=k;
	}
	return t;
} 
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)cin>>a[i];
	std::sort(a+1,a+1+m);
	while(--n)
	{
		for(i=1;i<=m;i++)cin>>b[i];
		std::sort(b+1,b+1+m);
		for(i=1;i<=k;i++)get(a[1]+b[i]);
		for(i=2;i<=k;i++)
			for(j=1;j<=k;j++)
				if(len<k)get(a[i]+b[j]);
				else if(q[1]<=a[i]+b[j])break;
				else put(),get(a[i]+b[j]);
		while(len>k)put();
		for(i=1;i<=k;i++)a[k-i+1]=put();
	}
	for(i=1;i<=k;i++)cout<<a[i]<<' ';

	return 0;
}