#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
inline int read()
{
	int f=1,w=0;char c;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar()) w=(w<<1)+(w<<3)+(c^48);
	return w*f;
}
signed main()
{
//	freopen(".in","r",stdin);
	freopen(".in","w",stdout);
	int i,j,k;
	int n,m,T;
	
	for(i=1;i<=1000000;i++)
		cout<<i<<" ";
	
	return 0;
}