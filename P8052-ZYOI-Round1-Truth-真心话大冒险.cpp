#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
inline int MAX(int x,int y){return x>y?x:y;}
inline int MIN(int x,int y){return x<y?x:y;}
inline int ABS(int x){return x>0?x:-x;}
using namespace std;
vector<int> a;
int b[20007],t[20007];
int q1(int x,int y,int z)
{
	cout<<"1 "<<x<<' '<<y<<' '<<z<<endl;
	cin>>x;
	return x;
}
void ms(int l,int r)
{
	if(l==r)return;
	int m=(l+r)/2;
	ms(l,m);
	ms(m+1,r);
	int p=l,i=l,j=m+1;
	while(i<=m&&j<=r)
		if(q1(b[0],b[i],b[j])==j)t[p++]=b[j++];
		else t[p++]=b[i++];
	while(i<=m)t[p++]=b[i++];
	while(j<=r)t[p++]=b[j++];
	for(i=l;i<=r;i++)b[i]=t[i];
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int x,y,z;
	
	cin>>n;
	if(n==1)
	{
		cout<<"3 1"<<endl;
		return 0;
	}
	for(i=1;i<=n;i++)
		a.push_back(i);
	for(i=1;i<=n-2;i++)
	{
		x=a.back();
		a.pop_back();
		y=a.back();
		a.pop_back();
		z=a.back();
		a.pop_back();
		t=q1(x,y,z);
		if(t!=x)a.push_back(x);
		if(t!=y)a.push_back(y);
		if(t!=z)a.push_back(z);
	}
	x=a.back();
	a.pop_back();
	y=a.back();
	a.pop_back();
	cout<<"2 "<<x<<' '<<y<<endl;
	cin>>b[0];

	int len=0;
	for(i=1;i<=n;i++)
		if(i!=b[0])
			b[++len]=i;
	ms(1,len);
	cout<<"3 "<<b[0];
	for(i=1;i<=len;i++)
		cout<<' '<<b[i];
	cout<<endl;

	return 0;
}