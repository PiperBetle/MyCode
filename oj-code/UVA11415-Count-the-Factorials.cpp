#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
inline int MAX(int x,int y){return x>y?x:y;}
inline int MIN(int x,int y){return x<y?x:y;}
inline int ABS(int x){return x>0?x:-x;}
using namespace std;
bool pr[100007];
int pt[100007],len=0;
int cnt_p[10000007],cou[10000007];
int func(int n)
{
	int ans=0;
	for(int i=1;;i++)
		if(cou[i]>=n)
			ans++;
		else return ans;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;

	pr[1]=1;
	for(i=2;i<=100000;i++)
	{
		if(!pr[i])
			pt[++len]=i,cnt_p[i]=1;
		for(j=1;j<=len&&i*pt[j]<=100000;j++)
		{
			pr[i*pt[j]]=1;
			if(i%pt[j]==0)break;
		}
	}
	cnt_p[1]=1;
	for(i=2;i<=10000000;i++)
	{
		if(pr[i])
			for(j=1;pt[j]*pt[j]<=i;j++)
				if(i%pt[j]==0)
				{
					cnt_p[i]=cnt_p[i/pt[j]]+1;
					break;
				}
		cou[i]=cou[i-1]+cnt_p[i];
	}
	cou[0]=cou[1]=1;
	for(i=0;i<=100;i++)
	{
		cout<<i<<" "<<cou[i]<<'\n';
	}
	cin>>T;
	while(T--)
	{
		cin>>n;
		// int *p=lower_bound(cou+1,cou+10000001,n);
		// cout<<(p-cou)<<'\n';
		cout<<func(n)<<'\n';
	}
	
	return 0;
}