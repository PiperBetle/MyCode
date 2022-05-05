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
int phi[100007],pt[100007],len;
bool pr[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=0;
	
	phi[1]=pt[1]=1;
	for(i=2;i<=100000;i++)
	{
		if(!pr[i])pt[++len]=i,phi[i]=i-1;
		for(j=1;j<=len&&i*pt[j]<=100000;j++)
		{
			pr[i*pt[j]]=1;
			if(!(i%pt[j])){phi[i*pt[j]]=phi[i]*pt[j];break;}
			phi[i*pt[j]]=phi[i]*(pt[j]-1);
		}
	}
	cin>>n;
	for(i=1;i<n;i++)ans+=phi[i];
	cout<<(n==1?0:(ans<<1|1));
	
	return 0;
}
