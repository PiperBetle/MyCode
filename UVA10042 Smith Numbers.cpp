#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define MOD 1000000007
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int pt[100007],len,f[100007];
bool pr[100007];
inline int find(int x,int cnt=0){while(x>9)cnt+=x%10,x/=10;return cnt+x;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	pr[1]=1;
	for(i=2;i<=100000;i++)
	{
		if(!pr[i])pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<=100000;j++)
		{
			pr[i*pt[j]]=1;
			if(i%pt[j]==0)break;
		} 
	}
	for(i=1;i<=len;i++)f[i]=find(pt[i]);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(k=n+1;;k++)
		{
			n=k;
			int sum=find(n);
			for(i=1;pt[i]*pt[i]<=n;i++)
				while(!(n%pt[i]))n/=pt[i],sum-=f[i];
			if(!(n^k))continue;
			if(n>1)sum-=find(n);
			if(!sum){cout<<k<<'\n';break;}
		}
	}
	
	return 0;
}
