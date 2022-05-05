#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<set>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
inline int read()
{
	int w=0;char c;
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())w=(w<<1)+(w<<3)+(c^48);
	return w;
}
std::set<int>s[2000007];
int a[2000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,q;
	int t,l,r;

	n=read();q=read();m=read();
	for(i=1;i<=n;i++)cin>>a[i];
	if(m==1)
	{
		
		return 0;
	}
	while(q--)
	{
		t=read();l=read();r=read();k=read();
		if(t==1)for(;l<=r;l++)s[k].insert(l);
		if(t==2)
		{
			int cnt=0;
			for(;l<=r;l++)cnt+=s[k].count(a[l]);
			cout<<cnt<<'\n';
		}
	}

	return 0;
}