#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int a[107],b[107][107],pre[107],f[107],ans[107];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k=0;
	int n,m=0,p=0;

	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<n;i++)for(j=i+1;j<=n;j++)cin>>b[i][j];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			if(b[j][i]&&f[i]<f[j])f[i]=f[j],pre[i]=j;
		f[i]+=a[i];
		if(f[i]>m)p=i,m=f[i];
	}
	do ans[++k]=p; while(p=pre[p]);
	do cout<<ans[k]<<' '; while(--k);
	cout<<'\n'<<m;

	return 0;
}