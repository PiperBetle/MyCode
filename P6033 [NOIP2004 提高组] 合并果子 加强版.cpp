#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline int read()
{
	int w=0;char c;
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())w=(w<<1)+(w<<3)+(c^48);
	return w;
}
int b[100007];
std::queue<int>q1,q2;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n=read(),m,ans=0;
	int x,y,z;
	
	for(i=1;i<=n;i++)b[read()]++;
	for(i=1;i<=100000;i++)while(b[i]--)q1.push(i);
	for(i=1;i<n;i++)
	{
		x=y=1e15;
		if(!q1.empty())x=min(x,q1.front());
		if(!q2.empty())x=min(x,q2.front());
		if(x==q1.front())q1.pop();else q2.pop();
		if(!q1.empty())y=min(y,q1.front());
		if(!q2.empty())y=min(y,q2.front());
		if(y==q1.front())q1.pop();else q2.pop();
		ans+=x+y;q2.push(x+y);
	}
	cout<<ans;
	
	return 0;
}
