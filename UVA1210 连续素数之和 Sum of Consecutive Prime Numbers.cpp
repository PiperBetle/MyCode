#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
using namespace std;
bool pr[100007];
int pt[100007],len;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	for(i=2;i<=100000;i++)
	{
		if(!pr[i])pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<=100000;j++)
		{
			pr[i*pt[j]]=1;
			if(i%pt[j]==0)break;
		} 
	}
	while(cin>>n)
	{
		if(n==0)return 0;
		int sum=0,left=1,right,cnt=0;
		for(right=1;right<=len;right++)
		{
			sum+=pt[right];
			while(sum>n)sum-=pt[left++];
			cnt+=(sum==n);
		}
		cout<<cnt<<'\n';
	}
	
	return 0;
}
