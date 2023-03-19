#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)>0?(a):-(a))
using namespace std;
struct city
{
	int l,r;
};
city a[200005];
bool cmp(city a,city b)
{
	return a.l<b.l;
}
int f[200005],len=1;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].l>>a[i].r;
	sort(a+1,a+1+n,cmp);
	f[1]=a[1].r;
	for(i=2;i<=n;i++)
	{
		t=upper_bound(f+1,f+len+1,a[i].r)-f;
		f[t]=a[i].r;
		if(t>len)len++;
	}
	cout<<len;
	
	return 0;
}
