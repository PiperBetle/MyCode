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
int pt[100007],len,sum[100007];
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
	
	return 0;
}
