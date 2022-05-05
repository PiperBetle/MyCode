#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
struct player
{
	int s,w,ID;
};
player a[1000007],t1[1000007],t2[1000007];
bool cmp(player a,player b)
{
	if(a.s!=b.s)return a.s>b.s;
	return a.ID<b.ID;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int r,b,q;
	
	cin>>n>>r>>q;
	for(i=1;i<=(n<<1);i++)
		cin>>a[i].s;
	for(i=1;i<=(n<<1);i++)
		cin>>a[i].w;
	for(i=1;i<=(n<<1);i++)
		a[i].ID=i;
	sort(a+1,a+1+(n<<1),cmp);
	while(r--)
	{
		for(i=1;i<=n;i++)
			if(a[(i<<1)-1].w<a[i<<1].w)
			{
				a[i<<1].s++;
				t1[i]=a[i<<1];
				t2[i]=a[(i<<1)-1];
			}
			else
			{
				a[(i<<1)-1].s++;
				t1[i]=a[(i<<1)-1];
				t2[i]=a[i<<1];
			}
		merge(t1+1,t1+n+1,t2+1,t2+n+1,a+1,cmp);
	}
	cout<<a[q].ID<<'\n';
	
	return 0;
}