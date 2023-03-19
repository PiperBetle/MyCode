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
bool pr[100007]={0,1};
int pt[100007],len;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int left,right;
	
	for(i=2;i<=100000;i++)
	{
		if(!pr[i])pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<=100000;j++)
		{
			pr[i*pt[j]]=1;
			if(i%pt[j]==0)break;
		} 
	}
	cin>>T;
	while(T--)
	{
		cin>>left>>right;
		int maxn_num,maxn_divisor=0;
		for(i=left;i<=right;i++)
		{
			int cnt=1;m=i;
			for(j=1;pt[j]*pt[j]<=m&&j<=len;j++)
			{
				int s=1;
				while(m%pt[j]==0)m/=pt[j],s++;
				cnt*=s;
			}
			if(m>1)cnt<<=1;
			if(cnt>maxn_divisor)maxn_divisor=cnt,maxn_num=i;
		}
		cout<<"Between "<<left<<" and "<<right<<", "<<maxn_num<<" has a maximum of "<<maxn_divisor<<" divisors.\n";
	}
	
	return 0;
}
