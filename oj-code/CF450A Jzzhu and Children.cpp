#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline int read()
{
	int w=0,y=1;char c;
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=(w<<1)+(w<<3)+(c^48);
	return w*y;
}
struct children{int data,ID;};
std::queue<children>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n=read(),m=read(),t;
	
	for(i=1;i<=n;i++)q.push((children){read(),i});
	while(q.size()>1)
	{
		children ch=q.front();q.pop();
		if(ch.data>m)ch.data-=m,q.push(ch);
	}
	cout<<q.front().ID;
	
	return 0;
}
