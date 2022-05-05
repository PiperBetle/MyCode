#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
using std::endl;
int a[107];
inline int check(int x){cout<<x<<endl;cin>>x;return x;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,n,t,l=1,r,mid;
	cin>>r>>n;
	for(i=0;i<n;i++)
	{
		cout<<1<<endl;
		cin>>t;
		if(t!=0)a[i]=t;else return 0;
	}
	i=0;
	while(l<=r)
		if((t=check(mid=(l+r)>>1)*a[(i++)%n])==1)l=mid+1;
		else if(t==-1)r=mid-1;
		else return 0;
	return 0;
}