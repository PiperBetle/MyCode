#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline int cnt(int x)
{
	int y=0;
	while(x)x/=10,y++;
	return y;
}
inline int r(int x)
{
	int y=x%10;
	while(cnt(y)<cnt(x))y=(y<<1)+(y<<3);
	return y+x/10;
}
bool pr[1000007]={0,1};
int pt[1000007],len,sum[1000007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	for(i=2;i<=1000000;i++)
	{
		if(!pr[i])pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<=1000000;j++)
		{
			pr[i*pt[j]]=1;
			if(i%pt[j]==0)break;
		} 
	}
	for(i=1;i<=1000000;i++)
	{
		sum[i]=sum[i-1];
		if(pr[i])continue;
		int m=i,flag=1;
		for(j=cnt(i);j>=2;j--)
			if(pr[m=r(m)])
			{
				flag=0;
				break;
			}
		sum[i]+=flag;
	}
	while(cin>>n)
	{
		if(n==-1)return 0;
		cin>>m;
		if(sum[n-1]==sum[m])cout<<"No";
		else cout<<sum[m]-sum[n-1];
		cout<<" Circular Prime";
		if(sum[m]-sum[n-1]!=1)cout<<'s';
		cout<<".\n";
	}
	
	return 0;
}
