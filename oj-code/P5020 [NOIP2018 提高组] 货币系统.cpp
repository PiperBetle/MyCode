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
int a[1007],f[25007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;

	cin>>T;
	while(T--)
	{
		memset(f,0,sizeof f);f[0]=1;
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i];
		std::sort(a+1,a+1+n);
		int cnt=0;
		for(i=1;i<=n;i++)
			if(f[a[i]]){cnt++;continue;}
			else for(j=a[i];j<=25000;j++)f[j]|=f[j-a[i]];
		cout<<n-cnt<<'\n';
	}

	return 0;
}