#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
using namespace std;
bool pr[15000007]={0,1};
int pt[15000007],len=0,a[15000007],b[15000007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int g=0,maxn=0,ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i],g=gcd(g,a[i]);
	for(i=1;i<=n;i++)a[i]/=g,maxn=max(maxn,a[i]),b[a[i]]++;
	for(i=2;i<=maxn;i++)
	{
		if(!pr[i])pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<=maxn;j++)
		{
			pr[i*pt[j]]=1;
			if(i%pt[j]==0)break;
		} 
	}
	for(i=1;i<=len;i++)
	{
		int cnt=0;
		for(j=pt[i];j<=maxn;j+=pt[i])cnt+=b[j];
		ans=max(ans,cnt);
	}
	cout<<(ans==0?-1:n-ans);
	
	return 0;
}
