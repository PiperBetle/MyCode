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
int s[1000007],len,n,m;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int a,b,c;
	int minn=1e17,maxn=-1e17;
	
	cin>>n;
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)s[++len]=i;
		if(i*i!=n)s[++len]=n/i;
	}
	for(i=1;i<=len;i++)
	{
		if(n%s[i])continue;
		for(j=1;j<=len;j++)
		{
			if(n%(s[i]*s[j]))continue;
			a=s[i];b=s[j];c=n/a/b;
			minn=min(minn,(a+1)*(b+2)*(c+2));
			maxn=max(maxn,(a+1)*(b+2)*(c+2));
		}
	}
	cout<<minn-n<<' '<<maxn-n;
	
	return 0;
}
