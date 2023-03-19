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
struct cow{int p,c;}a[100007];
bool cmp1(cow x,cow y){return x.c<y.c;};
bool cmp2(cow x,cow y){return x.p<y.p;};
std::priority_queue<int>q;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;

	cin>>n>>k>>m;
	for(i=1;i<=n;i++)cin>>a[i].p>>a[i].c;
	std::sort(a+1,a+1+n,cmp1);
	int sum=0;
	for(i=1;i<=k;i++)
	{
		sum+=a[i].c;q.push(a[i].c-a[i].p);
		if(sum>m)return cout<<i-1<<'\n',0;
	}
	std::sort(a+1+k,a+1+n,cmp2);
	for(i=k+1;i<=n;i++)
	{
		if(!q.empty())t=-q.top();
		else t=1e15;
		if(a[i].p-a[i].c>t)
		{
			sum+=t+a[i].c;
			q.pop();
			q.push(a[i].c-a[i].p);
		}
		else sum+=a[i].p;
		if(sum>m)break;
	}
	cout<<i-1<<'\n';
	
	return 0;
}